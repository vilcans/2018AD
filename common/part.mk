COMMON_PATH := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

DEPENDENCIES ?=

ADDITIONAL_MODULES = initialize speedload loader $(DEPENDENCIES)
MODULES = $(PART) $(ADDITIONAL_MODULES)

OBJS = $(foreach mod,$(MODULES),../$(mod)/$(mod).o)

SAMPLERATE ?= 44100

include $(COMMON_PATH)/common.mk

all: $(PART).o

$(PART).o: $(PART).s $(RESOURCES)

# mem is basically a dump of what will be in RAM when part starts, including common modules
$(PART).mem: $(PART).o ../demo.lds
	$(MAKE) -C .. $(ADDITIONAL_MODULES)
	$(VLINK) -M -Ttext 0x$(START_ADDRESS_HEX) -T../demo.lds -brawbin2 -o $@ $(OBJS)

# Only the part-specific data. Cut away the common stuff from the mem file
$(PART).part: $(PART).mem
	python $(BIN_DIR)/cut.py --base=0x$(START_ADDRESS_HEX) --start=0x$(PART_START_HEX) $< $@

$(PART)-speed.wav: $(PART).part
	python $(BASE_DIR)/speedload/speedload.py --samplerate=$(SAMPLERATE) --outfile=$@ $(PART).part\@$(PART_START_HEX)

$(PART).vz: $(PART).mem
	python $(BIN_DIR)/vz.py --name=$(PART) --address=0x7200 --copy-to=0x$(START_ADDRESS_HEX) --max-address=0x7800 --vz $@ $<

mame: $(PART).vz
	$(MAME_EXE) -w -rp $(BASE_DIR)/third_party/mame_vz200/ -cfg_directory $(BASE_DIR)/third_party/mame_vz200/ -v vz200 -dump $(PART).vz

mamedebug: $(PART).vz
	$(MAME_EXE) -debug -w -rp $(BASE_DIR)/third_party/mame_vz200/ -cfg_directory $(BASE_DIR)/third_party/mame_vz200/ -v vz200 -dump $(PART).vz

clean:
	rm -f $(RESOURCES)
	rm -f $(PART).o $(PART).mem
	rm -f *.lst

play: $(PART)-speed.wav
	mpv $(PART)-speed.wav

.PHONY: run mame mamedebug clean play
