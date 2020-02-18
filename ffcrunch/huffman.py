#!/usr/bin/env python

import sys
import argparse

from heapq import heappush, heappop, heapify
from collections import defaultdict
from array import array

from .bits import bits_to_bytes


def encode(symb2freq):
    """Huffman encode the given dict mapping symbols to weights"""
    heap = [[wt, [sym, ""]] for sym, wt in symb2freq.items()]
    heapify(heap)
    while len(heap) > 1:
        lo = heappop(heap)
        hi = heappop(heap)
        for pair in lo[1:]:
            pair[1] = '0' + pair[1]
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]
        heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    return sorted(heappop(heap)[1:], key=lambda p: (len(p[-1]), p))


def create_tree(data):
    """Returns list of [symbol, encoding]"""

    symb2freq = defaultdict(int)
    for ch in data:
        symb2freq[ch] += 1
    # in Python 3.1+:
    # symb2freq = collections.Counter(txt)
    huff = encode(symb2freq)
    #print "Symbol\tWeight\tHuffman Code"
    #for p in huff:
    #    print "%s\t%s\t%s" % (p[0], symb2freq[p[0]], p[1])
    return dict(huff)


def compress(raw_data, tree=None):
    if tree is None:
        tree = dict(create_tree(raw_data))
    bits = ''.join(tree[symbol] for symbol in raw_data)
    return bits_to_bytes(bits)


def save_tree(tree, tree_file):
    parent_node_value = 0xa5
    if parent_node_value in tree:
        print '"parent node indicator" value occurs in raw data; can not use it'
        sys.exit(1)

    tree_height = max(len(bits) for bits in tree.values())
    print 'Tree height', tree_height

    with open(tree_file, 'w') as out:
        out.write('; Tree of height {}:\n'.format(tree_height))
        out.write('; {}\n'.format(str(tree)))
        out.write('PARENT = ${:0>2x}\n'.format(parent_node_value))
        for level in xrange(tree_height + 1):
            out.write('\t; Level {}\n'.format(level))
            level_values = [(parent_node_value, '')] * (1 << level)
            for (value, bits) in tree.iteritems():
                if len(bits) == level:
                    level_values[int(bits, 2)] = (ord(value), bits)
            for v, b in level_values:
                out.write('\tdb ${:0>2x}  ; {:1}\n'.format(v, b))


def main():
    parser = argparse.ArgumentParser(description='Convert an image sequence to a character-based animation')
    parser.add_argument(
        '--tree', metavar='FILE', required=True,
        help='Save Huffman tree to this file')
    parser.add_argument(
        '--data', metavar='FILE', required=True,
        help='Save Huffman encoded data to this file')
    parser.add_argument(
        'input', metavar='INPUT_FILE',
        help='File to compress')

    args = parser.parse_args()

    raw_data = open(args.input).read()
    tree = create_tree(raw_data)
    print tree
    encoded = compress(raw_data, tree)
    save_tree(tree, args.tree)
    with open(args.data, 'wb') as out:
        out.write(encoded)

if __name__ == '__main__':
    main()
