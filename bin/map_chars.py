#!/usr/bin/env python

import argparse
import json

parser = argparse.ArgumentParser(
    description=
    'Create a map from Unicode characters to character numbers'
)
parser.add_argument(
    '-f', required=True, dest='fontchars', metavar='FILE',
    type=argparse.FileType('r'),
    help='Defines the characters in the font',
)

parser.add_argument(
    '-o', required=True, dest='mapping', metavar='FILE',
    type=argparse.FileType('w'),
    help='JSON file to save mapping in'
)

args = parser.parse_args()

font_chars = {}   # map character (str) to character number
for row_number, line in enumerate(args.fontchars):
    line = line.rstrip('\n').decode('utf-8')
    for column_number, char in enumerate(line):
        if char != '_':
            if char in font_chars:
                print('Warning: duplicate char in font definition: %r' % char)
            else:
                font_chars[char] = {
                    'row': row_number,
                    'column': column_number,
                    'index': len(font_chars)
                }

json.dump(font_chars, args.mapping, indent=4, sort_keys=True)
