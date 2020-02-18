#!/usr/bin/env python

from array import array
from collections import Counter

from .bits import bits_to_bytes


def elias_delta_decode(bits):
    # length_of_length = L in Wikipedia
    # length = N in Wikipedia

    #print 'Reading length_of_length'
    length_of_length = 0
    while bits.next() == 0:
        length_of_length += 1
    #if length_of_length == 0:
        #return 1
    #print 'Number of zeros:', length_of_length

    #print 'Reading length'
    length = 1
    for _ in range(length_of_length):
        b = bits.next()
        #print b
        length = (length << 1) | b
    length -= 1
    #print 'Length =', length

    #print 'Reading value'
    value = 1
    for _ in range(length):
        b = bits.next()
        #print b
        value = (value << 1) | b
    #print 'value =', value

    #print 'length_of_length = %d length = %d value = %d' % (length_of_length, length, value)
    return value - 1


def elias_delta_encode(value):
    value += 1
    value_bits = format(value, 'b')
    length = len(value_bits) - 1
    #print 'value_bits =', value_bits, ' => length =', length
    length_of_length = len(format(length + 1, 'b')) - 1
    #print 'length_of_length =', length_of_length, 'length =', length
    return (
        '0' * length_of_length +
        format(length + 1, '0' + str(length_of_length + 1) + 'b') +
        value_bits[1:]
    )


def unary_decode(bits):
    count = 0
    while bits.next() == 0:
        count += 1
    return count


def unary_encode(value):
    return '0' * value  + '1'


def compress(values, encoder):
    weights = Counter(values)
    ordered_values = sorted(weights.keys(), key=lambda v: -weights[v]);

    if all(i == value for i, value in enumerate(ordered_values)):
        print 'Note: Data is already sorted by frequency - can be used!'

    if False:
        for value in ordered_values:
            weight = weights[value]
            print value, 'appears', weight, 'times', weight * 100.0 / len(values), '%'

    indices = dict(
        (value, index)
        for index, value in enumerate(ordered_values)
    )

    encoded = ''
    for value in values:
        mapped_value = indices[value]
        encoded_value = encoder(mapped_value)
        #print 'mapped', value, 'to', mapped_value, 'encoded =', encoded_value
        encoded += encoded_value

    #print 'encoded size:', len(encoded), 'bits:', encoded
    return (
        array('B', [len(ordered_values)]) +
        array('B', ordered_values) +
        bits_to_bytes(encoded)
    )


def test(value, encoder, decoder, expected_encoding=None):
    encoded = encoder(value)
    print value, '=>', encoded
    if expected_encoding is not None:
        assert encoded == expected_encoding, \
            'encoded=%r expected %r using %r' % \
            (encoded, expected_encoding, encoder)

    bits = [int(x) for x in encoded]
    #print 'decode', encoded, '=>',
    decoded = decoder(iter(bits))
    #print decoded

    assert value == decoded, 'value %r != decoded %r encoded=%r' % (value, decoded, encoded)


if __name__ == '__main__':
    test(1 - 1, elias_delta_encode, elias_delta_decode, '1')
    test(2 - 1, elias_delta_encode, elias_delta_decode, '0100')
    test(3 - 1, elias_delta_encode, elias_delta_decode, '0101')
    test(4 - 1, elias_delta_encode, elias_delta_decode, '01100')
    test(8 - 1, elias_delta_encode, elias_delta_decode, '00100000')
    test(17 - 1, elias_delta_encode, elias_delta_decode, '001010001')

    test(0, unary_encode, unary_decode, '1')
    test(1, unary_encode, unary_decode, '01')
    test(2, unary_encode, unary_decode, '001')
    test(3, unary_encode, unary_decode, '0001')

    for i in range(1, 256):
        test(i, elias_delta_encode, elias_delta_decode)
        test(i, unary_encode, unary_decode)
