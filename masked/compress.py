from array import array
import argparse

def main():
    parser = argparse.ArgumentParser(
        description='Convert mask to runtime data'
    )
    parser.add_argument(
        'mask', metavar='MASK',
        type=argparse.FileType('rb'),
        help='Mask file'
    )
    parser.add_argument(
        'out', metavar='OUTPUT_FILE',
        type=argparse.FileType('wb'),
        help='File to write result to'
    )
    parser.add_argument(
        '--left', action='store_true', default=False,
        help='Image should be to the left'
    )

    args = parser.parse_args()
    out = args.out

    mask = array('B', args.mask.read())
    if args.left:
        mask = array('B', [x ^ 0xff for x in mask])

    width_bytes = 32
    leftmost = 9999
    rightmost = -1
    for row_no in range(len(mask) / width_bytes):
        row = mask[row_no * width_bytes:row_no * width_bytes + width_bytes]
        for left in range(width_bytes):
            if row[left] != 0:
                break
        for right in range(width_bytes, 0, -1):
            if row[right - 1] != 0xff:
                break

        mask_byte = row[left]
        if not args.left:
            mask_byte = mask_byte ^ 0xff

        out.write('; Row %d: left=%d right=%d mask=%d\n' % (row_no, left, right, mask_byte))
        out.write('\tdb $%02x,$%02x\n' % (left, mask_byte))

        leftmost = min(left, leftmost)
        rightmost = max(left, rightmost)

    if args.left:
        print 'Rightmost edge byte offset:', rightmost, 'i.e. min image width', rightmost
    else:
        print 'Leftmost edge byte offset:', leftmost, 'i.e. min image width', (32 - leftmost)

if __name__ == '__main__':
    main()
