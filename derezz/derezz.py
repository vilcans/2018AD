#!/usr/bin/env python3

from collections import namedtuple

import PIL.Image
from PIL import Image

Layer = namedtuple('Layer', 'threshold color dither')

def list_of_ints(s):
    return [int(v) for v in s.split(',')]


def process(image, source_left, source_top, source_height, thresholds, blurs):
    layers = [
        # threshold, color
        Layer(0, (0, 0, 255, 255), False),
        Layer(thresholds[0] - blurs[0], (255, 0, 0, 255), True),
        Layer(thresholds[0] + blurs[0], (255, 0, 0, 255), False),
        Layer(thresholds[1] - blurs[1], (255, 255, 0, 255), True),
        Layer(thresholds[1] + blurs[1], (255, 255, 0, 255), False),
    ]

    image = image.convert('RGB')

    target_width = 128
    target_height = 64
    target_par = 4.0 / 3

    #source_left = 1000
    #source_top = 754
    #source_height = 580

    source_width = int(round(
        source_height * (target_width / target_height) / target_par
    ))
    assert source_left + source_width <= image.width

    image = image.crop((
        source_left, source_top,
        source_left + source_width, source_top + source_height
    ))

    image = image.resize((target_width, target_height), resample=PIL.Image.BILINEAR)
    image.save('cropped.png')

    #layer_images = [None] * len(layers)
    composite = Image.new('RGBA', image.size)
    for layer_number, layer in enumerate(layers):
        pixel_data = []
        source_data = iter(image.getdata())
        for y in range(image.height):
            for x in range(image.width):
                r, g, b = next(source_data)
                p = int((r + g + b) / 3.0)
                if p < layer.threshold or layer.dither and (x + y) % 2 == 0:
                    pixel_data.append((0, 0, 0, 0))
                else:
                    pixel_data.append(layer.color)

        i = Image.new('RGBA', image.size)
        i.putdata(pixel_data)
        #i.save('layer%02d.png' % layer_number)

        composite = Image.alpha_composite(composite, i)

    return composite


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('image', type=Image.open)
    parser.add_argument('--left', type=int, required=True)
    parser.add_argument('--top', type=int, required=True)
    parser.add_argument('--height', type=int, required=True)
    parser.add_argument('--thresholds', type=list_of_ints, required=True)
    parser.add_argument('--blurs', type=list_of_ints, required=True)
    parser.add_argument('--composite', required=True)
    args = parser.parse_args()

    result = process(
        args.image, args.left, args.top, args.height,
        args.thresholds, args.blurs
    )
    result.save(args.composite)
