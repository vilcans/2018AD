#!/usr/bin/python
import sys
import os
import math
from array import array
#from PIL import Image

import argparse

EXT=".pun"
	
parser = argparse.ArgumentParser(description='Compress a blob')
	
parser.add_argument(
    '--verbose', '-v', action='store_true',
    help='Write more information to stdout')
parser.add_argument(
    '--simplest', '-s', action='store_true',
    help='Simplest. Only remove redundant blocks')
parser.add_argument(
    '--huffman', '-H', action='store_true',
    help='Build a full huffman tree')
parser.add_argument(
    '--blocks2', '-B', action='store_true',
    help='Do block detect with out overlap (no memory decode)')
parser.add_argument(
    '--blocks', '-b', action='store_true',
    help='Do block detect')
parser.add_argument(
    '--out', '-o', help='out filename')
parser.add_argument(
    '--maxblock', '-m', help='Max size of blocks to look for')
parser.add_argument(
    '--decode', '-d', action='store_true',
    help='Decode')

parser.add_argument('infiles', metavar='FILE',
    nargs="+", help='files to compress')

args = parser.parse_args()

infiles = args.infiles
(inbase, inext) = os.path.splitext(infiles[0])
#outfile = args.out if args.out else inbase+EXT
verbose = args.verbose
doSimplest = args.simplest
doHuffman = args.huffman
doBlocks2 = args.blocks2
doBlocks = args.blocks2
doBlocks |= args.blocks

doDecode = args.decode

if args.maxblock:
	maxBlock = int(args.maxblock)
else:
	maxBlock = 8 if doBlocks2 else 64


def blockhistogram(data, wordlen, tresh):
    words = {}
    totlen = len(data)
    i = 0
    while i < totlen-wordlen:
        word = data[i:i+wordlen]
        (val) = words.get(word, (0))
        # this gives false positives but allows words that are not wordlen alligned
        if val > 0:
            i += wordlen
        else:
            i+=1
        words[word]=(val+1)
    wordlist = [(val, key) for key, (val) in words.items() if val >= tresh]
    wordlist.sort(reverse=True)
    return wordlist

def print_blockhistogram(h):
    for idx, (freq, word) in enumerate(h):
        print freq, "*", list(bytearray(word))

def find_duplicate_blocks(frags, blocks, h):
	for (freq, word) in h:
		nfrags = []
		roffs = -1
		nblocks = []
		for (doffs, data, fref) in frags:
			if doBlocks2 and roffs != -1 and fref > 0:
				nfrags.append((doffs, data, fref))
				continue
			bs = 0
			offset = 0
			while offset != -1:
				offset = data.find(word, offset);
				if offset != -1:
					if roffs == -1:
						roffs = doffs + offset
						if doBlocks2:
							nfrags.append((doffs, data[0:offset], fref))
							# flag as used
							nfrags.append((roffs, data[offset:offset+len(word)], fref + 1))
							bs = offset + len(word)
							if fref != 0:
								break
					else:
						nblocks.append((doffs + offset, word, roffs))
						if offset > bs:
							nfrags.append((bs + doffs, data[bs:offset], fref))
						bs = offset + len(word)

					offset += len(word)

			if len(data) > bs:
				nfrags.append((bs + doffs, data[bs:], fref))
		
		if len(nblocks) > 0:
			blocks += nblocks
			frags = nfrags

	blocks.sort()
	return (frags, blocks)

def merge_frags(frags):
	nfrags = []
	nd = ""
	offset = 0
	bs = 0
	ffref = 0
	for (doffs, data, fref) in frags:
		if doffs == offset:
			nd += data
			ffref += fref
		else:
			nfrags.append((bs, nd, ffref))
			nd = data
			bs = doffs
			ffref = 0
		offset = doffs + len(data)

	if len(nd) > 0:
		nfrags.append((bs, nd, ffref))

	return nfrags

def find_blocks(data):
#	blocksizes = [ 64, 48, 40, 32, 31, 30, 29, 28, 27, 26, 25, 24, 22, 21, 20, 19, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4 ]
	blocksizes = range(maxBlock,3,-1)
	blocks = []
	frags = [ (0, data, 0) ]
	for bsz in blocksizes:
		h = blockhistogram(data, bsz, 2)
#			print_blockhistogram(h[:99])
		(frags, blocks) = find_duplicate_blocks(frags, blocks, h)
#		print "bsz = ", bsz, "totblocks =", len(blocks), "frags =", len(frags)
	
	if doBlocks2:
		frags = merge_frags(frags)

	return (frags, blocks)

def encode_plain(data):
	out = ""
	doffs = 0
	plen = len(data)
	if doSimplest:
#		hl = 1
#	print "+", plen, "bytes plain data"
		while plen > 127:
			plen -= 127
			out += chr(127)
#			hl += 1
			out += data[doffs:doffs+127]
			doffs += 127
		out += chr(plen)
		out += data[doffs:doffs+plen]
	else:
		if plen < 64:
			out += chr(plen)
#			hl = 1
		else:
			out += chr(64 + plen/256) + chr(plen & 255)
#			hl = 2
		out += data
	return out

def encode_blocks2(frags, blocks):
	offset = 0
	out = ""
	# Must adjust block positions for encoding to allow forward decode
	# Create and initialize adjusted block vector
	blocks2 = [ (boffs, len(word), roffs, roffs) for (boffs, word, roffs) in blocks ]
	for (doffs, data, ref) in frags:
		if doffs != offset:
			print "! fragment missmatch", doffs, "!=", offset
		encout = encode_plain(data)
		hl = len(encout) - len(data)
		out += encout
#		l = len(data)
#		if l < 64:
#			out += chr(l)
#			hl = 1
#		else:
#			out += chr(64 + l/256) + chr(l & 255)
#			hl = 2
#		out += data
		for i in range(len(blocks2)):
			(boffs, l, roffs, aroffs) = blocks2[i]
			if roffs >= offset:
				blocks2[i] = (boffs, l, roffs, aroffs + hl)
		offset += len(data)

		while len(blocks2) > 0 and blocks2[0][0] == offset:
			(boffs, l, roffs, aroffs) = blocks2.pop(0)
			for i in range(len(blocks2)):
				(nboffs, nl, nroffs, naroffs) = blocks2[i]
				if nroffs > offset:
					blocks2[i] = (nboffs, nl, nroffs, naroffs - l + 3)
			ooffs = aroffs
			out += chr(128 + l) + chr((ooffs >> 8) & 255) + chr(ooffs & 255)
#			print "+", len(word), "bytes backptr @", roffs
			offset += l
	# stopchar
	out += chr(0)
	return out

def decode_blocks2(data):
    out = ""
    offs = 0
    while data[offs] != chr(0):
		blkh = ord(data[offs])
		offs += 1
		if blkh < 128:
			if blkh >= 64 and not doSimplest:
				blkh = (blkh & 63)*256 + ord(data[offs])
				offs += 1
#            print "+", blkh, "bytes plain data"
			out += data[offs:offs+blkh]
 			offs += blkh
		else:
			wlen = blkh & 127
			woffs = ord(data[offs])*256 + ord(data[offs+1])
#			print "+", wlen, "bytes backptr @", woffs
			out += data[woffs:woffs+wlen]
			offs += 2
    return out

def encode_blocks(frags, blocks):
	offset = 0
	out = ""
	for (doffs, data, ref) in frags:
		if doffs != offset:
			print "! fragment missmatch", doffs, "!=", offset
#		l = len(data)
#		if l < 64:
#			out += chr(l)
#			hl = 1
#		else:
#			out += chr(64 + l/256) + chr(l & 255)
#			hl = 2
#		out += data
		out += encode_plain(data)
		offset += len(data)
		while len(blocks) > 0 and blocks[0][0] == offset:
			(boffs, word, roffs) = blocks.pop(0)
			out += chr(128 + len(word)) + chr((roffs >> 8) & 255) + chr(roffs & 255)
#			print offset, ": -", len(word), "bytes redundant block ptr @", roffs
			offset += len(word)

	out += chr(0)
	return out

def decode_blocks(data):
	out = ""
	offs = 0
	while offs < len(data):
		blkh = ord(data[offs])
		offs += 1
		if blkh < 128:
			if not doSimplest and blkh >= 64:
				blkh = (blkh & 63)*256 + ord(data[offs])
				offs += 1
#            print "+", blkh, "bytes plain data"
			out += data[offs:offs+blkh]
			offs += blkh
		else:
			wlen = blkh & 127
			woffs = ord(data[offs])*256 + ord(data[offs+1])
#            print "+", wlen, "bytes backptr @", woffs
			out += out[woffs:woffs+wlen]
			offs += 2
	return out

_huffman_codes = []
def _traverse_huffman(tree, path):
	(freq, leaf, val) = tree
	if leaf == 0:
#		print path, "=", ord(val)
		_huffman_codes.append((ord(val), path))
	else:
		_traverse_huffman(val[0], path+"0")
		_traverse_huffman(val[1], path+"1")
		
def huffman_tree(data):
	bytes = {}
	for byte in data:
		freq = bytes.get(byte, 0)
		bytes[byte]=freq+1

	codes = [(freq, 0, key) for key, freq in bytes.items()]
	while (len(codes) > 1):
		codes.sort(reverse = True)
		l = codes.pop()
		r = codes.pop()
		codes.append((l[0]+r[0], 1, (l, r)))
	_traverse_huffman(codes[0], "")
	_huffman_codes.sort()
#	codes = [(len(code), val, code) for (val, code) in _huffman_codes]
	codes = { val: code for (val, code) in _huffman_codes }
#	codes.sort();
	print "codes =", codes
	clens = [ 0 ] * 256
	for val in codes:
		clens[val] = len(codes[val])
	print "clens =", clens
	return (clens, codes)

			
def tree_from_lens(clens):
	freq = [ 0 ] * 16
	for l in clens:
		if l>0:
			freq[l] += 1
	print "freq =", freq
	loffs = 0
	offs = [ 0 ] * 16
	for i in range(16):
		offs[i] = loffs
		loffs += freq[i]
	print "offs =", offs
	vals = [ 0 ] * 256
	test = [0] * 256
	for i, l in enumerate(clens):
		vals[offs[l]] = i
		test[offs[l]] = l
		offs[l] += 1
	print "test =", test
	print "vals =", vals

	nodes = [ 0 ] * 16
	forks = 0
	sum = 0
	for l in range(16):
		lnc = freq[15-l] + forks
		forks = int((lnc+1) / 2)
		nodes[15-l] = lnc
		sum += lnc*2
	print "node count =", sum, ":", nodes
	
	tree = [ 0 ] * sum

	rowoffs = 0
	l = 0
	for i in range(16):
		f = freq[i]
		offs = rowoffs
		while f>0:
			tree[offs] = 1
			tree[offs+1] = vals[l]
			l+=1
			f-=1
			offs+=2
		rowoffs += nodes[i] * 2
	print "tree =", tree

def huffman_encode(bytes, codes):
	outbytes = ""
	carry = 0
	shiftc = 0
	for byte in bytes:
		for bitc in codes[ord(byte)]:
			bit = ord(bitc)-48
			carry = 2*carry + bit
			shiftc += 1
			if shiftc == 8:
				outbytes += chr(carry)
				carry = 0
				shiftc = 0
	if shiftc > 0:
		outbytes += chr(carry)
	return outbytes
			

totbytes = ""
for infile in infiles:
	inbytes = open(infile, 'rb').read()
	print "<-", infile, len(inbytes), "[bytes]"
	totbytes += inbytes

#totbytes = bitexpand(totbytes)
#clens = huffman_tree(totbytes)
#tree_from_lens(clens)

if doDecode:
	outfile = args.out if args.out else os.path.splitext(infiles[0])[0]
	outbytes = totbytes
	if doBlocks:
		if doBlocks2:
			outbytes = decode_blocks2(totbytes)
		else:
			outbytes = decode_blocks(totbytes)

else:
	outfile = args.out if args.out else infiles[0]+EXT
	outbytes = totbytes
	if doBlocks:
		(frags, blocks) = find_blocks(outbytes)	
		print "blocks =", len(blocks), "frags =", len(frags)
		if doBlocks2:
			outbytes = encode_blocks2(frags, blocks)
		else:
			outbytes = encode_blocks(frags, blocks)

	if doHuffman:
		(clens, codes) = huffman_tree(outbytes)
		outbytes = huffman_encode(outbytes, codes)
		#tree_from_lens(clens)

diff = len(totbytes)-len(outbytes)
perc = 100*len(outbytes)/len(totbytes)

# Enable this if we are on MSX
#if len(outbytes) > 0x4000:
#	print "Too large, won't fit in VDP: %s" % (hex(len(outbytes)))
#	sys.exit(1)

print "->", outfile, "[", len(outbytes), "bytes ] ",  str(perc) + "%", "diff =", diff

with open(outfile, 'wb') as out:
	out.write(outbytes)
