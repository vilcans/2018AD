PART = face3
RESOURCES = image.eliasd
DEPENDENCIES = roller

include ../common/part.mk

IMAGE ?= imodium.png

image.bin: $(IMAGE)
	python $(BIN_DIR)/image_to_gfx.py $< $@

