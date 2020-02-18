#!/usr/bin/env python
#
# By Imodium of Five Finger Punch
#
# 
# ...11001100110010

import sys
import os

import wave
import argparse

from array import array

parser = argparse.ArgumentParser(description='Write data to WAV suitable for vz200)')

parser.add_argument('--verbose', '-v', action='store_true', help='Write more information to stdout')
parser.add_argument('--amplitude', '-a', type=int, default=250, help='signal amplitude (high=bias+amplitude) 0-255')
parser.add_argument('--bias', '-b', type=int, default=0, help='signal level bias 0-255')
parser.add_argument('--samplerate', '-s', type=int, default=44100, help='samples per second')
parser.add_argument('--outfile', metavar='<out-file>', help='RIFF (Wav) file to write')
parser.add_argument('infiles', metavar='<in-file>', nargs="+", help='data file to convert')

args = parser.parse_args()

infiles = [ infile.split(',') for infile in args.infiles ]

inbase = os.path.basename(infiles[0][0])
outfile = args.outfile if args.outfile else inbase + ".wav"

samplerate = args.samplerate
outoffs = args.bias
outhigh = args.amplitude

synch = 7*chr(0) + chr(1)

shortfreq = 22050/2
longfreq = 22050/4

shortpulse = samplerate / shortfreq
longpulse = samplerate / longfreq

shortsym = shortpulse*chr(outoffs)+shortpulse*chr(outoffs+outhigh)
longsym = longpulse*chr(outoffs)+longpulse*chr(outoffs+outhigh)

cpuspeed = 3579500 # hz
#bitcounttime = 37 # tstates
#bitoverhead = 67 #tstates
bitcounttime = 36 # tstates
bitoverhead = 43 #tstates
tstates = cpuspeed/samplerate

print "samplerate =", samplerate, "@cpu =", cpuspeed, "[hz] ->", tstates, "[tstates/byte]"
shortcount = (len(shortsym)*tstates - bitoverhead)/bitcounttime
longcount = (len(longsym)*tstates - bitoverhead)/bitcounttime

print "short:", shortcount, "[iterations] long:", longcount, "[iterations] avg", (longcount+shortcount)/2

def data2wav(data):
    out = ""
    for ch in data:
        bw = 128
        while bw >= 1:
            out += shortsym if (ord(ch) & bw) == 0 else longsym
            bw /= 2

    return out
    
def writewav(outfile, wavedata):
    wavewrite = wave.open(outfile, 'wb')
    wavewrite.setnchannels(1)
    wavewrite.setsampwidth(1)
    wavewrite.setframerate(samplerate)

    wavewrite.writeframes(wavedata)
    wavewrite.close()

totwavdata = ""
timeoffset = 0   # in samples
for infile in infiles:
    nameoffs = infile[0].split('@')
    start = int(nameoffs[1], 16) if len(nameoffs) > 1 else 0x7800
    name = nameoffs[0]
    indata = open(name, 'rb').read()
    startframe = int(infile[1]) if len(infile)>1 else 0
    startsample = startframe * samplerate / 50
    inlen = len(indata)
    datastart = chr(start&255)+chr(start/256)
    datalen = chr(inlen&255)+chr(inlen/256)
    totlen = len(datastart) + len(datalen) + inlen
    wavdata = data2wav(synch + datastart + datalen + indata)
    loadtimesamples = len(wavdata)

#    timeoffset += loadtimesamples
    if timeoffset > startsample:
        print "! invalid loadstart frame =", startframe, "sample =", startsample, "less than current time offset =", timeoffset
        delaysamples = 0
    else:
        delaysamples = startsample - timeoffset
    
    delaywavdata = (delaysamples/len(shortsym)) * shortsym
    totwavdata += delaywavdata + wavdata
    timeoffset += len(delaywavdata) + len(wavdata) # use real numbers

    print "<-", name, len(indata), "[bytes] @" + hex(start)
    print "  start: " + str(startsample) + "[samples] =", str(startframe), "[frames]"
    print "  end: " + str(timeoffset) + "[samples] =", str(timeoffset*50 / samplerate), "[frames]"
    print "  delay: " + str(delaysamples) + "[samples] =", str(delaysamples*50 / samplerate), "[frames]" 
    print "  load: " + str(loadtimesamples) + "[samples] =", str(loadtimesamples*50 / samplerate), "[frames]"

print "->", outfile
writewav(outfile, totwavdata)
