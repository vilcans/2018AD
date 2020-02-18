PART = boot
RESOURCES =
DEPENDENCIES =

include ../common/part.mk

# Override target in part.mk to put loading screen before part
$(PART).vz: $(PART).mem screen.bin
	python $(BIN_DIR)/vz.py --name=2018\ A.D. --loading-screen=screen.bin --address=0x7260 --copy-to=0x$(START_ADDRESS_HEX) --max-address=0x7800 --vz $@ $(PART).mem
