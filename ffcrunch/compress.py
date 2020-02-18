#!/usr/bin/env python

import argparse
from array import array

import elias

def main():
    parser = argparse.ArgumentParser(description='Compress data')
    parser.add_argument(
        '-o', metavar='FILE', required=True,
        type=argparse.FileType('wb'),
        help='File to save compressed data to'
    )
    parser.add_argument(
        'input', metavar='INPUT_FILE', type=argparse.FileType('rb'),
        help='File to compress'
    )

    args = parser.parse_args()

    raw_data = array('B', args.input.read())

    filetype = args.o.name.split('.')[-1]
    if filetype == 'eliasd':
        encoded = elias.compress(raw_data, elias.elias_delta_encode)
    elif filetype == 'unary':
        encoded = elias.compress(raw_data, elias.unary_encode)
    else:
        parser.error('Unknown file type: %s' % filetype)

    args.o.write(encoded)

if __name__ == '__main__':
    main()
