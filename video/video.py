
import sys

sys.path.append('/usr/local/lib/python2.7/site-packages')

import cv2

# Windows dependencies
# - Python 2.7.6: http://www.python.org/download/
# - OpenCV: http://opencv.org/
# - Numpy -- get numpy from here because the official builds don't support x64:
#   http://www.lfd.uci.edu/~gohlke/pythonlibs/#numpy

# Mac Dependencies
# - brew install python
# - pip install numpy
# - brew tap homebrew/science
# - brew install opencv


# Video is encoded to samples as:
# [line1][linesynch]
# ...
# [line16][framesynch]
# Where:
# [line] = alternating high low 0-3 samples per pixel
# Frame timing @22khz:
# 512 points of max 4samples -> ~40-10fps
# 
# receiver loop:
# - wait for framesynch
# - receive symbol count at end of framesynch
# - receive frame
# - wait for VBLANK
# - draw frame to screen
#

import wave
import argparse
import time
from array import array
from ast import literal_eval as make_tuple

parser = argparse.ArgumentParser(description='Capture video and convert to character screen. Code as WAV')

parser.add_argument('--verbose', '-v', action='store_true', help='Write more information to stdout')
parser.add_argument('--ceil', '-c', default='256', help='Highest pixel value (above will be solid)')
parser.add_argument('--tresh', '-t', default='10', help='Lowest pixel value (below will be considered 0)')
parser.add_argument('--amplitude', '-a', default='250', help='signal amplitude (high=bias+amplitude) 0-255')
parser.add_argument('--bias', '-b', default='0', help='signal level bias 0-255')
parser.add_argument('--outfile', metavar='<out-file>', help='RIFF (Wav) file to write')
parser.add_argument('--fps', '-F',  metavar='<FPS>', default="5", help='frames per second')
parser.add_argument('--size', '-s',  metavar='<WINDOWSIZE>', default="(64,32)", help='(width,height)')
parser.add_argument('--offs', '-o',  metavar='<OFFSET>', default="(16,16)", help='(x,y)')
parser.add_argument('wavfiles', metavar='<wav-file>', nargs="*", help='wav files to play before starting')

args = parser.parse_args()

outfile = args.outfile

cpuspeed = 3579500 # hz
samplerate = 22050 # hz
outoffs = int(args.bias)
outhigh = int(args.amplitude)

capturesize = make_tuple(args.size)
captureoffs = make_tuple(args.offs)

# linesynch: 11111100
linesynch = 6*chr(outhigh) + 2*chr(outoffs)
# framesynch: 4*linesync + 1100
framesync = 6*linesynch+chr(outhigh)+chr(outoffs)

#chars = " .,+x*$s&8%B#Q@" + chr(143)
chars = " .,'-+x=*$&%B#@"
#chars = " .,+*#"
txtsize = (32,16)

cps = samplerate / len(chars)

tresh = int(args.tresh)
scale = (int(args.ceil) - tresh) / len(chars)

upstr = "\033["+str(1+txtsize[1])+"A"
print "\033[2J"
print "using", len(chars), "chars -> minimum cps =", cps, "[cps] ->", cps/(txtsize[0]*txtsize[1]), "[fps]" 
tstates = cpuspeed/samplerate
print "samplerate =", samplerate, "@cpu =", cpuspeed, "[hz] ->", tstates, "[tstates/byte]"

cap = cv2.VideoCapture(0)

def waveframe(lines):
    # framesync
    wavedata = 30*(24*chr(0) + 24*chr(1))
    for line in lines:
        for val in line:
            linestr += chars[val]
        # end of line
        wavedata += 24*chr(alt)
    return wavedata


def writewav(outfile, data):
#    print "write data:", len(data), "[bytes]"
    wavewrite = wave.open(outfile, 'wb')
    wavewrite.setnchannels(1)
    wavewrite.setsampwidth(1)
    wavewrite.setframerate(samplerate)
    
    wavewrite.writeframes(data)
    wavewrite.close()


def printscr(lines):
    for line in lines:
        linestr = ""
        for val in line:
            linestr += chars[val]
        print linestr
    sys.stdout.flush();

def getValuesFromFrame(frame):
    #pic = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    #pic = cv2.resize(pic, txtsize, interpolation = cv2.INTER_CUBIC)
    pic = cv2.resize(frame, capturesize, interpolation = cv2.INTER_CUBIC)
    pic = cv2.cvtColor(pic, cv2.COLOR_BGR2GRAY)
    cv2.imshow('frame', pic)
    lines = []
    for y in range(captureoffs[1], captureoffs[1]+txtsize[1]):
        line = []
        for x in range(captureoffs[0], captureoffs[0] + txtsize[0]):
            val = (pic[y, x] - tresh) / scale
            if val < 0:
                val = 0
            elif val >= len(chars):
                val = len(chars)-1
            line.append(val)
        lines.append(line)
    return lines

fps = float(args.fps)
ftime = 1.0/fps

upstr = "\033["+str(1+txtsize[1])+"A"

while True:
    # Capture frame-by-frame
    last = time.time()
    ret, frame = cap.read()

    lines = getValuesFromFrame(frame)

    print upstr
    printscr(lines)

    sleeptime = ftime+last-time.time() 
    if sleeptime > 0:
        time.sleep(sleeptime)
    
    if cv2.waitKey(1) & 0xff == ord('q'):
#        out = cv2.imwrite('capture.jpg', frame)
        break


cap.release()
cv2.destroyAllWindows()
