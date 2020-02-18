# Encodes a binary file so it doesn't contain any zeros.
#
# Encoding:
# First byte contains value ESCAPE0.
# For each byte:
#   Xor the byte with ESCAPE0 and output the result

import sys
from array import array
from collections import Counter


def decode(encoded):
    result = array('B')

    xor = encoded[0]
    escape = encoded[1]
    i = 2
    while i < len(encoded):
        byte = encoded[i] ^ xor
        i += 1
        if byte == escape:
            print >>sys.stderr, 'found escape byte at', i - 2, 'value =', encoded[i]
            result.append(encoded[i])
            i += 1
        else:
            result.append(byte)

    return result


def unzero(code):
    """Encode `code` so it contains no zeros.

    Uses the two least common byte values in the data for `xor` and `escape`.

    First tries 255 as `xor` and 254 as `escape`:

    >>> unzero(array('B', [0, 1, 2, 3]))
    array('B', [255, 254, 255, 254, 253, 252])

    If 255 is used, uses 254 and 253, etc:

    >>> unzero(array('B', [0, 1, 2, 3, 255]))
    array('B', [254, 253, 254, 255, 252, 253, 1])
    """

    histogram = Counter()
    histogram.update({a: 0 for a in range(256)})
    for byte in code:
        histogram[byte] += 1

    # Find the least used bytes
    # (except 0 in the unlikely event that it's uncommon)
    most_common = [x for (x, _) in histogram.most_common() if x != 0]
    xor = most_common[-1]
    escape = most_common[-2]

    return encode(xor, escape, code)


def encode(xor, escape, code):
    """
    Encodes the data.
    Xors every value with xor.

    If `xor` and/or `escape` is part of the input data, they're
    escaped with `escape`.

    Using 1 for xor and 2 for escape respectively.

    >>> encode(1, 2, array('B', [5, 6, 7, 8]))
    array('B', [1, 2, 4, 7, 6, 9])

    If the `xor` value appears in data, it is escaped with `xor^escape` (3):

    >>> encode(1, 2, array('B', [1]))
    array('B', [1, 2, 3, 1])

    If the `escape` value appears in data, it is escaped with `xor^escape` (3):

    >>> encode(1, 2, array('B', [2]))
    array('B', [1, 2, 3, 2])
    """

    result = array('B')

    result.append(xor)
    result.append(escape)
    print >>sys.stderr, 'xor=$%02x escape=$%02x' % (xor, escape)
    for index, byte in enumerate(code):
        if byte == xor or byte == escape:
            print >>sys.stderr, 'Escaping byte at', index
            result.append(escape ^ xor)
            result.append(byte)
        else:
            result.append(byte ^ xor)

    decoded = decode(result)
    if decoded != code:
        import difflib
        for line in difflib.unified_diff(
            ['%02x' % b for b in code],
            ['%02x' % b for b in decoded],
        ):
            print >>sys.stderr, line
        raise RuntimeError('Verification failed')

    return result

if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(
        description='Encode binary file to avoid zeros'
    )
    parser.add_argument(
        'bin', type=argparse.FileType('rb'),
        help='Input binary',
    )
    parser.add_argument(
        'out', type=argparse.FileType('wb'),
        help='Output binary'
    )

    args = parser.parse_args()

    code = array('B', args.bin.read())
    args.out.write(unzero(code))
