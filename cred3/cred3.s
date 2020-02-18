	GLOBAL cred1_start

start_y = 63
end_y = 0
image_width = 44/4
image_height = (masked_image_end-masked_image)/image_width
mask_left = 0

	jp masked_start

masked_image:
	INCBIN image.bin
masked_image_end:
mask_data:
	INCLUDE maskdat.s

	INCLUDE ../masked/masked.s
