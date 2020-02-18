
include common/common.mk

# Make sure all modules are listed here in PARTS or MODULES.
# This makes dependencies and clean work.
# git ls-files '*/Makefile' | sed -E 's/^([^/]*)\/Makefile/\1 \\/' | grep -v rom-disassembled/ | grep -v template
PARTS = \
	brag \
	circles1 \
	console_test \
	covfefe \
	cred1 \
	cred2 \
	cred3 \
	cred4 \
	face1 \
	face2 \
	face3 \
	face4 \
	fldscroll \
	gdpr \
	helix \
	kefrens \
	loader \
	nocnt \
	rain \
	rot8 \
	screw \
	shadebobs \
	simple \
	technobabble \
	trans \
	glitterflag \
	electron \
	turtle \
	video \
	waving \
	endlogo \
	ykaros

MODULES = $(PARTS) \
	boot \
	console \
	ffcrunch \
	gensine \
	initialize \
	ps \
	randprint \
	speedload \
	tinyboot \
	roller

MODULE_OBJS = $(foreach mod,$(MODULES),$(mod)/$(mod).o)
OBJS = $(MODULE_OBJS)

all: $(MODULES)

compile:
	$(MAKE) -C boot boot.wav
	for mod in $(PARTS) ; do \
		$(MAKE) RELEASE=1 -C $$mod $$mod-speed.wav ; \
	done
	$(MAKE) -C compile

$(MODULES):
	$(MAKE) -C $@ $@.o

copyrom: rom.bin
	cp $< $(EMULATOR_ROM)

restorerom:
	cp $(EMULATOR_ROM).orig $(EMULATOR_ROM)

vzem:
	(cd $(VZEM_DIR) && $(VZEM_EXE))

run: copyrom vzem

clean:
	rm -f rom.bin demo.bin unpack.bin demo.pun demo.binary initialize.o *.lst
	for mod in $(MODULES) ; do \
		$(MAKE) -C $$mod clean ; \
	done

# Create a new part from template.
# Usage example to create new part xyz: make newpart NEWPART=xyz
newpart:
ifndef NEWPART
	$(error NEWPART not defined)
endif
	mkdir $(NEWPART)
	sed 's/template/$(NEWPART)/g' template/template.s >$(NEWPART)/$(NEWPART).s
	sed 's/template/$(NEWPART)/g' template/Makefile >$(NEWPART)/Makefile
	sed 's/template/$(NEWPART)/g' template/gitignore >$(NEWPART)/.gitignore

.PHONY: $(MODULES) copyrom run clean restorerom compile
