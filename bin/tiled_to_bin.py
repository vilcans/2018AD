#!/usr/bin/env python

import xml.etree.ElementTree as ET
import struct
from array import array


def convert_tmx(infile):
    tree = ET.parse(infile)

    # Assuming only one tileset
    tileset_node = tree.find('tileset')
    firstgid = int(tileset_node.attrib['firstgid'])

    layer_nodes = tree.findall('layer')
    layers = []

    for layer_node in layer_nodes:
        data_node = layer_node.find('data')
        name = layer_node.attrib['name']

        raw_data = data_node.text.decode(data_node.attrib['encoding'])

        # raw_data is raw 32-bit integers packed into a string: decode it
        data = struct.unpack('<%dI' % (len(raw_data) / 4), raw_data)

        array_data = array('B')
        for index, d in enumerate(data):
            d = d & 0x3fffffff   # bit 30 and 31 are mirror x, y flags
            if d >= firstgid:
                array_data.append(d - firstgid)
            else:
                array_data.append(0)

        layers.append((name, array_data))

    return layers


def main():
    import argparse
    parser = argparse.ArgumentParser(description='Convert Tiled to binary')
    parser.add_argument(
        'tmx', type=argparse.FileType('r'),
        help='Tiled file',
    )
    parser.add_argument(
        'out', type=argparse.FileType('wb'), nargs='?', default=None,
        help='Binary data',
    )
    parser.add_argument(
        '--layers', required=False,
        help='Pattern for layers. {0} will be replaced by layer name.',
    )

    args = parser.parse_args()
    if not args.out and not args.layers:
        parser.error('Either give an output filename or --layers flag')

    layers = convert_tmx(args.tmx)

    if args.layers:
        for name, data in layers:
            filename = args.layers.format(name)
            print 'Writing', filename
            with open(filename, 'wb') as out:
                out.write(data)
    else:
        for name, data in layers:
            args.out.write(data)

if __name__ == '__main__':
    main()
