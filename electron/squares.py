#!/usr/bin/env python

import sys
import math

squares = {}
for i in range(0,256):
    s = i*i
    squares[i] = s

print "; lo byte"
for i in range(0,256):
    print "\tdefb $%02x" % (squares[i] & 0xff)

print "; hi byte"
for i in range(0,256):
    print "\tdefb $%02x" % ((squares[i] >> 8) & 0xff)

