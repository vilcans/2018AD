SECTIONS {
    /*
       Where each part is loaded and starts
       Must match PART_START_HEX in common/common.mk!
    */
    PART_START = 0x78a0;

    .text : {
        . = 0x7800;

        /* Resident modules: */
        initialize.o(*)
        speedload.o(*)
        loader.o(*)

        ASSERT(. <= PART_START, "Overwriting part");

        /* Add the rest of the objects: */
        . = PART_START;
        *.o(.text)
    }
    TEXT_END = .;

    BSS_START = ALIGN(0x100);

    .bss BSS_START : AT(BSS_START) {
        *.o(.bss)
        ASSERT(. <= 0x8000, "Out of RAM for bss");
    }

    /* reusebss is a text segment that overlaps the BSS segment */
    reusebss TEXT_END : {
        *.o(reusebss)
        ASSERT(. <= 0x8000, "Out of RAM for reusebss");
    }

    vram 0x7200 : AT(0x7200) {
        *.o(vram)
        ASSERT(. <= 0x7800, "Out of VRAM");
    }
}
/* vim: set ts=4 sw=4 tw=0 et :*/
