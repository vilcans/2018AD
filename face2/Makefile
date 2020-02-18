PART = face2
RESOURCES = image.eliasd
DEPENDENCIES = roller

include ../common/part.mk

IMAGE ?= morbid.png

image.bin: $(IMAGE)
	python $(BIN_DIR)/image_to_gfx.py $< $@

