PART = fldscroll
RESOURCES = text.s font.bin
DEPENDENCIES = gensine

include ../common/part.mk

charmap.json: fontchars.txt
	        $(BIN_DIR)/map_chars.py -f fontchars.txt -o charmap.json

text.s: charmap.json text.txt
	../bin/map_text.py -m charmap.json --format='db $${0:02x}+1 ; {1!r}' --unused -o $@ text.txt

font.bin: genfont.py font.png charmap.json
	./genfont.py -m charmap.json --charsize=8x8 --charstep=8x10 --origin=23,57 font.png font.bin
