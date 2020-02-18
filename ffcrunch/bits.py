from array import array

def bits_to_bytes(bits):
    """
    Converts string of bit values to raw bytes.

    >>> bits_to_bytes('111111110000000010101010')
    array('B', [255, 0, 170])

    Left padding if number of bits not divisable by 8:

    >>> bits_to_bytes('0000000011')
    array('B', [0, 192])
    >>> bits_to_bytes('0000000011000000')
    array('B', [0, 192])
    """
    byte_count = (len(bits) + 7) // 8
    data = array('B')
    for n in range(byte_count):
        bits_in_byte = bits[n * 8:n * 8 + 8]
        bits_in_byte += '0' * (8 - len(bits_in_byte))
        data.append(int(bits_in_byte, 2))
    return data


