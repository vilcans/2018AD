import sys
import argparse
import struct

parser = argparse.ArgumentParser(description='Convert VZ to raw memory map')
parser.add_argument(
    'vz', type=argparse.FileType('rb'),
    help='Input VZ file'
)
parser.add_argument(
    '--full', type=argparse.FileType('wb'), default=sys.stdout,
    help='Output, full address space $0000-$ffff for hex dumps etc'
)

args = parser.parse_args()

vz = args.vz.read()

format = '<4s17sBH'
header, filename, filetype, address = struct.unpack_from(format, vz)
filename = filename.rstrip('\0')
data = vz[struct.calcsize(format):]

print >>sys.stderr,'filename %r' % filename
print >>sys.stderr,'type $%02x' % filetype
print >>sys.stderr,'address $%04x' % address

args.full.write('\0' * address)
args.full.write(data)
args.full.write('\0' * (0x10000 - len(data) - address))
