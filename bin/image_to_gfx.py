#!/usr/bin/env python

# Python 2 utility for converting an image file to the raw frame buffer format
# used by VZ (and others devices using the MC6847 chip) in graphics mode.

import sys

from array import array

from PIL import Image

import argparse

palettes = [
    # Palette 0
    (
        (0x07, 0xff, 0x00),
        (0xff, 0xff, 0x00),
        (0x3b, 0x08, 0xff),
        (0xcc, 0x00, 0x3b),
    ),
    # Palette 1
    (
        (0xff, 0xff, 0xff),
        (0x07, 0xe3, 0x99),
        (0xff, 0x1c, 0xff),
        (0xff, 0x81, 0x00),
    )
]

def get_pixel(image, palette, x, y):
    if 0 <= x < image.size[0] and 0 <= y < image.size[1]:
        rgb = image.getpixel((x, y))
        nearest_index = 0
        nearest_distance = 1000000000
        _, index = sorted(
            (
                sum((palette[index][i] - rgb[i]) ** 2 for i in range(3)),
                index
            ) for index in range(len(palette))
        )[0]
        return index
    return 0


def convert(image, palette):
    """Returns the image as a byte array"""

    image = image.convert('RGB')
    data = array('B')
    for y in range(image.size[1]):
        for c in range(image.size[0] // 4):
            value = 0
            for xoffs in range(4):
                pixel = get_pixel(image, palette, c * 4 + xoffs, y)
                value = (value << 2) | pixel
            data.append(value)

    return data

def main():
    parser = argparse.ArgumentParser(
        description='Convert an image to raw VZ graphics screen format'
    )
    parser.add_argument(
        'source', metavar='IMAGE_FILE',
        help='Image file to convert'
    )
    parser.add_argument(
        'out', metavar='OUTPUT_FILE',
        type=argparse.FileType('wb'),
        help='File to write graphics data to'
    )
    parser.add_argument(
        '--palette', metavar='PALETTE',
        type=int, choices=[0, 1], default=0,
        help='Palette to use'
    )
    parser.add_argument(
        '--xor', metavar='FIRST_ROW_VALUE',
        type=lambda s: int(s, 0),
        help='XOR each row of bytes with previous row, '
        'or the given value for the first row'
    )

    args = parser.parse_args()

    image = Image.open(args.source)

    print >>sys.stdout, 'Image size:', image.size

    if (image.size[0] % 4) != 0:
        print >>sys.stderr, 'Image must have a width that is a multiple of 4'
        sys.exit(1)

    raw_data = convert(image, palettes[args.palette])

    if args.xor is not None:
        bytes_per_row = image.size[0] / 4
        raw_data = (
            array('B', (v ^ args.xor for v in raw_data[:bytes_per_row])) +
            array('B', (
                raw_data[i - bytes_per_row] ^ raw_data[i]
                for i in range(bytes_per_row, image.size[1] * bytes_per_row)
            ))
        )

    args.out.write(raw_data)

if __name__ == '__main__':
    main()
