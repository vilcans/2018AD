#!/usr/bin/env python
#
# By Imodium of Five Finger Punch
#
# 
import sys
import os

import wave
import argparse

from array import array

parser = argparse.ArgumentParser(description='Write data to WAV suitable for vz200)')

parser.add_argument('--verbose', '-v', action='store_true', help='Write more information to stdout')
parser.add_argument('--outfile', metavar='<out-file>', help='RIFF (Wav) file to write')
parser.add_argument('infiles', metavar='<in-file>', nargs="+", help='wavfiles to mix')

args = parser.parse_args()

outfile = args.outfile if args.outfile else os.path.basename(args.infiles[0]) + ".mix.wav"

samplerate = 0 # means that anything goes :)

mixdata = []
maxlen = 0
for f in args.infiles:
    waveread = wave.open(f, "rb")
    rspb = waveread.getsampwidth()
    rnch = waveread.getnchannels()
    rate = waveread.getframerate()

    if samplerate == 0:
        samplerate = rate
    
    mixbytesperframe = rspb*rnch
    print "<- " + f + ": samplerate =", samplerate, "channels =", rnch, "bytes/frame =", mixbytesperframe

    data = waveread.readframes(waveread.getnframes())
    if rate != samplerate or rnch != 1 or rspb != 1:
        print "invalid mixtrack: should be samplerate =", samplerate, "1 ch 1 byte per sample"
#       exit(-1)
        data = [ data[mixbytesperframe * frameno] for frameno in range(0, waveread.getnframes()) ]
    waveread.close()
    if len(data) > maxlen:
        maxlen = len(data)
    mixdata.append(data)

tracks = len(mixdata)
print "-- total ", tracks, "[tracks]", maxlen, "[frames]"

wavdata = [ chr(0) ] * tracks * maxlen

for track, data in enumerate(mixdata):
    for pos, byte in enumerate(data):
        offs = pos*tracks + track
        wavdata[offs] = byte

wavstring = bytearray(wavdata)

print "->", outfile

wavewrite = wave.open(outfile, 'wb')
wavewrite.setnchannels(tracks)
wavewrite.setsampwidth(1)
wavewrite.setframerate(samplerate)

wavewrite.writeframes(wavstring)
wavewrite.close()
