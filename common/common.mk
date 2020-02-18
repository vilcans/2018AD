# Start of our binary data.
# If this is not enough, we can use gfx mode VRAM from $7200
START_ADDRESS_HEX ?= 7800

# Where each part is loaded and starts
# Must match PART_START in demo.lds!
PART_START_HEX ?= 78a0

# Where we load into RAM.
# As we're using the loader in ROM, we don't want to overwrite
# system variables that are in the area $7800 to $7ae8.
# We unpack from this address to START_ADDRESS_HEX.
LOAD_ADDRESS_HEX ?= 7b00

COMMON_DIR = $(abspath $(lastword $(MAKEFILE_LIST)/..))
BASE_DIR := $(abspath $(COMMON_DIR)/..)
BIN_DIR := $(BASE_DIR)/bin

WINE ?= wine

VZEM_DIR ?= $(BASE_DIR)/third_party/vzem/
VZEM_EXE ?= $(WINE) ./vz.exe
EMULATOR_ROM ?= third_party/vzem/vzrom.v20

# Figure out which OS
ifeq ($(OS), Windows_NT)
	BUILD_PLATFORM := WIN
	WINE :=
	MAME_DIR ?= c:\project/mame
	MAME_EXE ?= $(MAME_DIR)/mame64.exe
else
	MAME_DIR ?= 
	MAME_EXE ?= mame
	UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		# Assume 64 bit
        BUILD_PLATFORM := LINUX64
    endif
    ifeq ($(UNAME_S),Darwin)
		BUILD_PLATFORM := OSX
    endif
endif

VASM ?= $(BIN_DIR)/$(BUILD_PLATFORM)/vasmz80_oldstyle
VLINK ?= $(BIN_DIR)/$(BUILD_PLATFORM)/vlink

# Override with e.g. `make RELEASE=1` to make a release build.
# Use `IF RELEASE` and `IF !RELEASE` in code to check.
RELEASE ?= 0

# Override with e.g. `make SHOW_FRAMESKIP=1` to warn about frames that took too long
SHOW_FRAMESKIP ?= 0

ASM_FLAGS = \
	-Dstart_address=\$$$(START_ADDRESS_HEX) \
	-Dload_address=\$$$(LOAD_ADDRESS_HEX) \
	-DSHOW_FRAMESKIP=$(SHOW_FRAMESKIP) \
	-DRELEASE=$(RELEASE) \
	-I $(COMMON_DIR)


# How much to amplify the wav file.
# Emulator likes 1, real hardware likes a big number
VOLUME ?= 1000

#%.bin: %.o
	#vlink -brawbin2 -o $@ $<

%.o: %.s
	$(VASM) $(ASM_FLAGS) -Fvobj -L $@.lst -o $@ $<

%.eliasd: %.bin
	PYTHONPATH=$(BASE_DIR) python -m ffcrunch.compress -o $@ $<

%.unary: %.bin
	PYTHONPATH=$(BASE_DIR) python -m ffcrunch.compress -o $@ $<

%.wav: %.vz
	mkdir -p $(BASE_DIR)/dostmp
	cp $< $(BASE_DIR)/dostmp/input.vz
	dosbox -conf $(BIN_DIR)/bin/dos/dosbox.conf -c 'MOUNT C $(BASE_DIR)' -c 'c:' -c 'c:\bin\dos\vz2wav dostmp\input.vz dostmp\output.wav' -c exit
	sox -v $(VOLUME) $(BASE_DIR)/dostmp/OUTPUT.WAV $@
	rm -r $(BASE_DIR)/dostmp

%.bin: %.tmx
	python $(BIN_DIR)/tiled_to_bin.py $< $@
