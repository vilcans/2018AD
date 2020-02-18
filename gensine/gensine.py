from math import sin, pi

precision = 8

def to_float(value):
    if value == 0:
        return 0, 0
    exponent = 8
    while True:
        s = int(value * 2 ** exponent)
        if s < (1 << (precision - 1)):
            exponent += 1
        else:
            break

    assert (s >> (precision - 1)) == 1, 'Expected highest bit to be 1 in %s' % s
    #s &= (1 << (precision - 1)) - 1
    return s, exponent - precision


def from_float(significand, exponent):
    v = float(significand / (2.0 ** exponent))
    v /= 2 ** precision
    return v


#for v in (0, .01, .02, .05, .1, .5, .99, .99999999):
    #significand, exponent = to_float(v)
    #print v, '=', (significand, exponent), '=', round(from_float(significand, exponent), 3)

out = open('values.s', 'w')

# Tricks used:
# Skip very first value, range(1, ...), as it's always zero.
# As the values are increasing, once the values have a zero exponent,
# all following values will have a zero exponent, so don't store the exponent.
table_size = 64
exponentless = 0
for a in range(1, table_size):
    angle = float(a) / table_size * pi / 2
    v = sin(angle)
    significand, exponent = to_float(v)
    #print a, v, '=', (significand, exponent), '=', round(from_float(significand, exponent), 3)

    if a == 1:
        assert significand == 0xc9, 'Code assumes first byte is opcode for ret'

    if exponent == 0:
        exponentless += 1
        out.write('\tdb $%02x ; %s\n' % (significand, v))
    else:
        out.write('\tdb $%02x,$%02x ; %s\n' % (significand, exponent, v))

out.write('number_of_values_without_exponent = %s\n' % exponentless)
