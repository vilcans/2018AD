#!/usr/bin/env python

# 2017-05-18
# Sine table generator by Mathias Olsson
# New and improved version

import sys
import math
import argparse


def normal_cosine(start, end, nr_of_values):
    '''
        Generate a cosine table from start (inclusive) to end (inclusive)
    '''
    # cosine values go from -1 to 1 inklusive
    # figure out what we should multiply with to get the correct values
    middle = (end - start) / 2.0
    multiply = middle
    add = start + middle

    two_pi = math.pi * 2.0
    increment = two_pi / nr_of_values
    current = 0

    values = []
    while len(values) < nr_of_values:
        current_cosine = math.cos(current) * multiply + add
        current_int = int(round(current_cosine))
        values.append(current_int)
        current += increment

    return values

def normal_sine(start, end, nr_of_values):
    '''
        Generate a sine table from start (inclusive) to end (inclusive)
    '''
    # sine values go from -1 to 1 inklusive
    # figure out what we should multiply with to get the correct values
    middle = (end - start) / 2.0
    multiply = middle
    add = start + middle

    two_pi = math.pi * 2.0
    increment = two_pi / nr_of_values
    current = 0

    values = []
    while len(values) < nr_of_values:
        current_sine = math.sin(current) * multiply + add
        current_int = int(round(current_sine))
        values.append(current_int)
        current += increment

    return values


def write_values(output_file, values, type, prefix):
    newline_counter = 0
    with open(output_file, 'w') as out:
        for value in values:
            if newline_counter == 0:
                out.write('\t%s%s %d' % (prefix, type, value))
            else:
                out.write(', %d' % value)
            newline_counter += 1
            if newline_counter == 8:
                newline_counter = 0
                out.write('\n')
        out.write('\n')



parser = argparse.ArgumentParser(description='Generate a premultiplied integer only sine table')
parser.add_argument('nr_of_values', type=int, help='Number of values to create')
parser.add_argument('start', type=int, help='Start value to use (inclusive)')
parser.add_argument('end', type=int, help='End value to use (inclusive)')
parser.add_argument('out', help='File to write sine table to')
parser.add_argument('--size', help='Size per value: b, w, or l', action="store")
parser.add_argument('--mnemonic', help='Mnemonic to use for defining values', action="store")
parser.add_argument('--cos', help='Use cos instead of sin', default=False, action="store_true")

args = parser.parse_args()

output_file = args.out
nr_of_values = args.nr_of_values
start = args.start
end = args.end
use_cos = args.cos

# Make sure start is always lower than end
if end <= start:
    print "end %s must be greater than start %s" % (end, start)
    sys.exit(-1)

type = ''

if args.size:
    type = args.size
else:
    interval = end-start
    if interval < 2**8:
        # Should fit in a byte
        type = 'b'
    elif interval < 2**16:
        # Should fit in a word
        type = 'w'
    elif interval < 2**32:
        # Should fit in a longword
        type = 'l'
    else:
        print 'Result will be to large. Try with a smaller premultiplier or smaller offset.'
        sys.exit(1)

prefix = ''
if args.mnemonic:
    prefix = args.mnemonic
else:
    # Default to z80
    prefix = 'def'

if use_cos:
    values = normal_cosine(start,end,nr_of_values)
else:
    values = normal_sine(start,end,nr_of_values)
write_values(output_file, values, type, prefix)
