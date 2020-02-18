#!/usr/bin/env python

import sys
import argparse
import json
from collections import OrderedDict

parser = argparse.ArgumentParser(
    description=
    'Map each character a text to its corresponding character number'
)
parser.add_argument(
    '-m', required=True, dest='mapping', metavar='FILE',
    type=argparse.FileType('r'),
    help='JSON file mapping character to char number',
)
parser.add_argument(
    '-o', metavar='ASSEMBLY',
    default=sys.stdout,
    type=argparse.FileType('w'),
    help='Where to write the result as assembly source (default stdout)',
)
parser.add_argument(
    'text', nargs=1,
    type=argparse.FileType('r'),
    help='Text file to convert to char numbers',
)
parser.add_argument(
    '--unused', action='store_true', default=False,
    help='Report how much each character in the font is used'
)
default_format = 'db ${0:02x}  ; {1!r}'
parser.add_argument(
    '--format',
    default=default_format,
    help='Format string (default "' + default_format + '")',
)

args = parser.parse_args()

char_map = json.load(args.mapping)
char_map = OrderedDict(
    sorted(char_map.iteritems(), key=lambda e: e[1]['index'])
)
usage = OrderedDict((char, 0) for (char, entry) in char_map.iteritems())

out = args.o

for text_file in args.text:
    for line in text_file:
        if line.startswith('='):
            out.write(line[1:])
        else:
            for char in line:
                if char in char_map:
                    usage[char] += 1
                    out.write('\t')
                    out.write(args.format.format(char_map[char]['index'], char))
                    out.write('\n')

if args.unused:
    unused = [c for c, count in usage.iteritems() if count == 0]
    if unused:
        print 'Unused characters in font:'
        for c in unused:
            entry = char_map[c]
            print repr(c), 'at row', entry['row'], 'column', entry['column']
