PART = rot8

TEXTURES = texture_0 texture_1 texture_2 texture_3 texture_4 texture_F texture_I texture_V texture_E

RAW_TEXTURES = $(foreach texture,$(TEXTURES),$(texture).bin)
COMPRESSED_TEXTURES = $(foreach texture,$(TEXTURES),$(texture).unary)
RESOURCES = $(COMPRESSED_TEXTURES)

DEPENDENCIES = gensine

include ../common/part.mk

$(RAW_TEXTURES): textures.tmx
	python $(BIN_DIR)/tiled_to_bin.py --layers='./texture_{0}.bin' $<

textures: $(COMPRESSED_TEXTURES)

.PHONY: textures
