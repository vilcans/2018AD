	GLOBAL cred1_start

start_y = 63
end_y = 5
image_width = 32/4+1
image_height = 58  ;(masked_image_end-masked_image)/image_width
mask_left = 1

	jp masked_start

masked_image:
	INCBIN image.bin
masked_image_end:
mask_data:
	INCLUDE maskdat.s

	INCLUDE ../masked/masked.s
