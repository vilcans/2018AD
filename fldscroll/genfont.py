#!/usr/bin/env python

import argparse
import json
from PIL import Image
from array import array


# Each single row bitmap (list of bytes)
bitmaps = []

# Map a bitmap (list of bytes) to its index
bitmap_numbers = {}



def image_to_bytes(image, threshold=64):
    pixel_width = image.size[0]
    byte_width = (pixel_width + 7) // 8
    b = array('B', [0] * (image.size[1] * byte_width))
    for y in range(image.size[1]):
        for x in range(image.size[0]):
            p = image.getpixel((x, y))
            if p >= threshold:
                b[y * byte_width + x // 8] |= 0x80 >> (x & 7)

    return b


def main(image, rows_and_columns, charsize, charstep, font_out):
    image = image.convert('L')

    for row, column in rows_and_columns:
        left = column * charstep[0]
        top = row * charstep[1]
        right = left + charsize[0]
        bottom = top + charsize[1]
        char_image = image.crop((left, top, right, bottom))
        char_image = char_image.transpose(Image.ROTATE_270)
        #char_image = char_image.transpose(Image.FLIP_LEFT_RIGHT)
        bitmap = image_to_bytes(char_image)

        font_out.write(bitmap)


def point(s):
    return two_ints(s, ',')


def size(s):
    return two_ints(s, 'x')


def two_ints(s, separator):
    values = tuple(int(x) for x in s.split(separator))
    if len(values) != 2:
        raise ValueError('Expected two integers')
    return values


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Convert a font image to cool data')
    parser.add_argument('font', metavar='IMAGE_FILE', help='Font image')
    parser.add_argument(
        'bitmaps', metavar='FILE', type=argparse.FileType('wb'),
        help='File to write bitmap data to'
    )
    parser.add_argument(
        '--origin', metavar='LEFT,TOP', type=point, default=(0, 0),
        help='Top left corner of font image to use'
    )
    parser.add_argument(
        '--charsize', metavar='WIDTHxHEIGHT', type=size, required=True,
        help='Size of each character'
    )
    parser.add_argument(
        '--charstep', metavar='WIDTHxHEIGHT', type=size,
        help='Size of each character, including margin in the font image'
    )
    parser.add_argument(
        '-m', metavar='MAPPING_FILE', required=True,
        type=argparse.FileType('r'),
        help='File to read character mappings from'
    )

    args = parser.parse_args()
    image = Image.open(args.font)
    image = image.crop(
        (args.origin[0], args.origin[1], image.size[0], image.size[1])
    )

    char_map = json.load(args.m)

    rows_and_columns = [
        (char['row'], char['column'])
        for char in sorted(char_map.values(), key=lambda c: c['index'])
    ]
    main(
        image, rows_and_columns,
        args.charsize, args.charstep or args.charsize,
        args.bitmaps
    )
