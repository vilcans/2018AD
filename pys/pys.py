
# <CMD> <DATA> <CMD2> <DATA2> ...
# CMD = [0<cnt>] [< <cnt> bytes rle>]  -> <cnt> byte block of RLE
# CMD = [1<rept>] [< ONE byte (rle)>] -> <byte> is repeated <cnt> times
# Like Mathias Hybridhuff but does block detection first and has an
# extensible metastructure 
#
# RLE data:
# 0 -> literal word (unmasked valid bits only)
# 10 -> most frequent byte after block removal
# 110 -> second most frequent byte
# 1110 -> third
# ...

import sys
import argparse
import operator
import os

from bitstring import BitArray, BitStream

EXT = ".pys"

parser = argparse.ArgumentParser(
    description='Huff and Puff and blow some data down')

parser.add_argument(
    '--out', '-o', help='out filename')
parser.add_argument(
    '--decode', '-d', action='store_true',
    help='Decode instead of encode')
parser.add_argument(
    '--blockbits', '-b', default="8",
    help='Number of bits to encode blocklen')
parser.add_argument(
    '--mask', '-m', default="11111111",
    help='Bitmask for data')
parser.add_argument(
    '--graphchar', '-g', action='store_true',
    help='Convert ABC80 graphics chars into 6bits (imply blocklen=6bits)')
parser.add_argument(
    '--verbose', '-v', action='store_true',
    help='Write more information to stdout')
parser.add_argument(
    '--debug', '-D', action='store_true',
    help='Write even more information to stdout')

parser.add_argument('infile', help='files to compress')

args = parser.parse_args()

infile = args.infile
verbose = args.verbose
debug = args.debug
#numcodes = int(args.numcodes)
maskstr = args.mask

blocklenbits = int(args.blockbits)

if args.graphchar:
    print "- ABC80 graphchars"
    maskstr = "01011111"
    blocklenbits = 6

blocklenmax = (1<<blocklenbits)-1
blocklenmask = blocklenmax

#with open(infile, "rb") as f:
#    data = bytearray(f.read())

def addblocks(blocks, btype, s):
    sstart = 0
    while len(s) - sstart > blocklenmax:
        blocks.append(btype + chr(blocklenmax) + s[sstart:sstart+blocklenmax])
        sstart += blocklenmax
    blocks.append(btype + chr(len(s)-sstart) + s[sstart:])

def addmulti(blocks, s, cnt, limit):
    if cnt > limit:        
        bs = 0
        if len(s) > cnt:
            bs = len(s) - cnt
            addblocks(blocks, "0", s[:bs])
        addblocks(blocks, "1", s[bs:])
    else:
        addblocks(blocks, "0", s)

def blocklist(data, limit):
    blocks = []
    lchar = ' '
    cnt = -1
    blockdata = ""
    for b in data:
        if cnt >= 0 and b == lchar:
            cnt += 1
        else:
            
            if cnt > limit:
                addmulti(blocks, blockdata, cnt, limit)
                blockdata = ""
        
            cnt = 1
            lchar = b
        blockdata += b

    addmulti(blocks, blockdata, cnt, limit)
    return blocks

def findcodes(blocks):
    frequency = {}
    for block in blocks:
        if block[0] == "0":
            for ch in block[1:]:
                if frequency.has_key(ch):
                    frequency[ch] += 1
                else:
                    frequency[ch] = 1

    bytelist = [ (val, key) for key, (val) in frequency.items() ]
    bytelist.sort(reverse=True)

    code = ""
    codes = {}
    table = ""
    for (val, key) in bytelist[0:bits-1]:
        code += "1"
        table += key
        codes[key] = code + "0"

    if verbose:
        print "- codes:", codes, "from", len(bytelist), "values"

    return (table, codes)


def bitstr(ch, shrinkmask):
    bit = 1
    bstr = ""
    val = ord(ch)
    while bit < 256:
        if shrinkmask & bit > 0:
            bstr = "1" + bstr if val & bit > 0 else "0" + bstr
        bit *= 2
    return bstr
    
def encchar(ch, codes):
    bstr = codes[ch] if codes.has_key(ch) else "0" + bitstr(ch, mask)
    if debug:
        print "encoded: ", ord(ch), "->", bstr
    return bstr

def encode(data, limit):
    blocks = blocklist(data, limit)
    (outdata, codes) = findcodes(blocks)
    bitstream = ""
    for block in blocks:
        count = bitstr(block[1], blocklenmask)
        if debug:
            print "block [" + str(len(bitstream)) + "]:", block[0], ord(block[1]), count
        if block[0] == "1":
            # repeat block
            bitstream += "1" + count + encchar(block[2], codes)
        else:
            bitstream += "0" + count
            for ch in block[2:]:
                bitstream += encchar(ch, codes)
               
    bitstream += "0" + bitstr('\0', blocklenmask)
    boffs = 0
    while boffs < len(bitstream):
        outdata += chr(int(bitstream[boffs:boffs+8], 2))
        boffs += 8
    
#    print "encode: lenbitstr:", len(bitstream), "numcodes:", codes.items(), "lenout:", len(outdata)
    return outdata


def decchar(inbytes, decbitstr, idx, bitcount):
    oidx = idx
    if decbitstr[idx] == "0":
        idx += 1
        val = int(decbitstr[idx:idx+bitcount], 2)
        idx += bitcount
        if args.graphchar:
            if val >= 32:
                val += 32
            val += 32
        ch = chr(val)
        if debug:
            print "decoded full:", decbitstr[oidx:idx], val
    else:
        idx += 1
        sidx = idx
        while decbitstr[idx] == "1":
            idx += 1
        ch = inbytes[idx-sidx]
        idx += 1
        if debug:
            print "decoded rle:", decbitstr[oidx:idx], ord(ch)


    return (ch, idx)
        
def decode(inbytes, numcodes):
    decbitstr = ""
    for ch in inbytes[numcodes:]:
        decbitstr += bitstr(ch, 0xff)

    if verbose:
        print "decode:", len(inbytes), "numcodes:", numcodes, "bitstr:", len(decbitstr)

    idx = 0
    outbytes = ""
    while True:
        btype = decbitstr[idx]
        blen = int(decbitstr[idx+1:idx+1+blocklenbits], 2)
#        print "block [" + str(idx) + "]:", btype, blen
        idx += 1 + blocklenbits
        if blen == 0:
            break
        if btype == "0":
            blockbytes = ""
            for i in range(blen):
                (ch, idx) = decchar(inbytes, decbitstr, idx, bits)
                outbytes += ch
        else:
            (ch, idx) = decchar(inbytes, decbitstr, idx, bits)
            outbytes += blen * ch

    return outbytes



mask = int(maskstr, 2)

bits = 0
for ch in maskstr:
    if ch == '1':
        bits += 1

if verbose:
    print "- mask: " + bitstr(chr(mask), 0xff) + " ["+ str(bits) +"]"

inbytes = open(infile, 'rb').read()

if args.decode:
    outfile = args.out if args.out else os.path.splitext(infile)[0]
    outbytes = decode(inbytes, bits - 1)

else:
    # search a range of block limits for best result
    outbytes = inbytes
    outfile = args.out if args.out else infile + EXT
    for limit in range(7, 8):
        tmpout = encode(inbytes, limit)
        if len(tmpout) < len(outbytes):
            outbytes = tmpout

diff = len(inbytes)-len(outbytes)
perc = 100*len(outbytes)/len(inbytes)

print infile, len(inbytes), "[bytes] ->", outfile, "[", len(outbytes), "bytes ] ", str(perc) + "%", "diff =", diff

with open(outfile, 'wb') as out:
    out.write(outbytes)
