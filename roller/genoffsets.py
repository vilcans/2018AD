#!/usr/bin/env python

from math import asin

def generate(scanlines, start, end, number_of_source_lines):
    values = []
    section = .97
    section_angle = asin(section)
    for row in range(scanlines):
        y = row / float(scanlines - 1) * 2 - 1   # from -1.0 to 1.0 inclusive
        y *= section
        angle = asin(y)     # -section_angle to section_angle
        a = angle / section_angle  # -1 to 1
        a = (a + 1) / 2  # 0 to 1

        z = start + a * (end - start)
        z = int(z)
        values.append(z)

    return values


out = open('offsets.s', 'w')
values = generate(8, 7.999, 1, 8)
for v in values:
    out.write('\tdw image+width_bytes*%s\n' % (v,))
