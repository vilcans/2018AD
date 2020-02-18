#!/usr/bin/env python

import sys
import math
from xml.etree import ElementTree

filename='hand-lines.svg'
tag='HAND'

tree = ElementTree.parse(filename)
root = tree.getroot()

paths = root.findall('.//{http://www.w3.org/2000/svg}path')
if len(paths) != 1:
	print 'Expected one path; found %d' % len(paths)
	sys.exit(1)

path = paths[0]
d = path.get('d')
values = d.split(' ')
if values[0] != 'm':
	print 'Expected path to start with "m"'
	sys.exit(1)

del values[0]
x = y = 0
points = []
for value in values:
	dx, dy = tuple(float(v) for v in value.split(','))
	x += dx
	y += dy
	points.append((x, y))

def get_bounds(points):
	left = min(p[0] for p in points)
	right = max(p[0] for p in points)
	top = max(p[1] for p in points)
	bottom = min(p[1] for p in points)
	return left, right, top, bottom

left, right, top, bottom = get_bounds(points)
print '; Bounds: left=%s right=%s top=%s bottom=%s' % (left, right, top, bottom)

requested_width = 126 # 300 # 300
requested_height = 63 # 160 # 200

width = right - left
height = top - bottom
scale_x = requested_width / width
scale_y = requested_height / height

scale = min(scale_x, scale_y)

translate_x = -5 # 32+128 #-140
translate_y = -30 # -60 #-180
transformed_points = [
	(translate_x + p[0] * scale_x, translate_y + p[1] * scale_y)
	for p in points
]

print '; generated from: ', filename
print ';'
print '; scale: x', scale_x, 'y', scale_y, 'scale', scale
left, right, top, bottom = get_bounds(transformed_points)
print '; Bounds: left=%s right=%s top=%s bottom=%s' % (left, right, top, bottom)
print ';'
""" 
tlen = len(transformed_points)
print tag+'_COUNT\tEQU\t', tlen
#for p in transformed_points:
for i in range(tlen):
    p = transformed_points[i]
    x = int(p[0] + 0.5)
    y = int(p[1] + 0.5)
    shift  = 1<<(15-(x & 15))
    offset = y*44+int(x/16)*2
    print '\tdefb \t%d,%s' % (x, y)
    #    print '\tdc.w\t$%04x, $%02x \t; (%d,%d)' % (offset, shift, x , y)
    if i < tlen-1:
        pp = transformed_points[i+1]
        dx = int(pp[0] + 0.5)-x
        dy = int(pp[1] + 0.5)-y
        #print 'dx=",dx, " dy=",dy
        if abs(dx) > abs(dy):
            ax = math.copysign(65536, dx)
            ay = ax*dy/dx
        else:
            ay = math.copysign(65536, dy)
            ax = ay*dx/dy
#        print '\tdc.l\t%05d, %05d \t; (%d,%d)' % (ax, ay, dx , dy)
 """

current_angle_256 = 0
print "START_X=%s" % (int(round(transformed_points[0][0])))
print "START_Y=%s" % (int(round(transformed_points[0][1])))
print "\tdefb PEN_ROTATE,0"
print "\tdefb PEN_DOWN,PEN_COLOR_11"

for i in range(0, len(transformed_points)):
#for i in range(0, 4):
    x0,y0 = transformed_points[i]
    x1,y1 = transformed_points[(i+1) % len(transformed_points)]
    dy = y1-y0
    dx = x1-x0
    length = math.sqrt(dx*dx+dy*dy)*2
    angle = math.atan2(dy, dx)
    angle_degree = math.degrees(angle)
    angle_256 = (angle_degree/360.0)*256

    delta_angle_256 = (angle_256 - current_angle_256) % 256
    current_angle_256 = angle_256

#    print "; x0 %s y0 %s x1 %s y1 %s dy %s dx %s angle %s angle_degrees %s length %s angle_256 %s current_angle_256 %s delta_angle_256 %s" % (x0, y0, x1, y1, dy, dx, angle, angle_degree, length, angle_256, current_angle_256, delta_angle_256)
    print "\tdefb PEN_ROTATE,%s" % (int(round(delta_angle_256)))
    print "\tdefb PEN_MOVE,%s" % (int(round(length)))

print "\tdefb PEN_DONE"

    