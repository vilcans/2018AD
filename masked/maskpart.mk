RESOURCES = image.bin maskdat.s

COMPRESS_ARGS ?=

include ../common/part.mk

mask.bin: mask.png
	python $(BIN_DIR)/image_to_gfx.py $< $@

maskdat.s: mask.bin
	python ../masked/compress.py $(COMPRESS_ARGS) $< $@

image.bin: image.png
	python $(BIN_DIR)/image_to_gfx.py $< $@
