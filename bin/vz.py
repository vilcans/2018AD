import sys
import struct


# Where basic program normally starts.
# The ROM fixes the addresses in the basic program after loading,
# so AFAIK the actual number doesn't actually matter.
basic_start_address = 0x7ae9

header_format = '<4s17sBH'


def get_vz_header(filename, filetype, address=0x7ae9):
    return struct.pack(header_format, 'VZF0', filename, filetype, address)


def parse_int(i):
    return int(i, 0)


def main():
    import argparse
    parser = argparse.ArgumentParser(description='Convert binary to VZ format')
    parser.add_argument(
        'bin', type=argparse.FileType('rb'),
        help='Input binary',
    )
    parser.add_argument(
        '--name', default='DEMO',
        help='File name in VZ',
    )
    parser.add_argument('--basic', action='store_true')
    parser.add_argument(
        '--address', metavar='START_ADDRESS',
        default=basic_start_address,
        type=parse_int,
        help='Address to load code at',
    )
    parser.add_argument(
        '--max-address',
        default=0x7ff0,
        type=parse_int,
        help='address + size must not be greater than this',
    )
    parser.add_argument(
        '--copy-to',
        default=None,
        type=parse_int,
        help='Add code to copy the data to this address and then jump there'
    )
    parser.add_argument(
        '--loading-screen',
        type=argparse.FileType('rb'),
        default=None,
        help='Put this data at $7000, pad with zeros up to START_ADDRESS'
    )
    parser.add_argument(
        '--vz', type=argparse.FileType('wb'), required=True,
        help='Output VZ file'
    )

    args = parser.parse_args()

    code = args.bin.read()

    if args.copy_to is not None:
        code = ''.join([
            # di
            struct.pack('<B', 0xf3),
            # ld hl,code
            struct.pack('<BH', 0x21, args.address + 0x0e),
            # ld bc,length
            struct.pack('<BH', 0x01, len(code)),
            # ld de,copy_to
            struct.pack('<BH', 0x11, args.copy_to),
            # push de   ; for jumping to code after copy
            struct.pack('<B', 0xd5),
            # ldir; ret
            struct.pack('<BBB', 0xed, 0xb0, 0xc9),
        ]) + code

    if args.loading_screen:
        loading_screen = args.loading_screen.read()
        padding = args.address - 0x7000 - len(loading_screen)
        if padding < 0:
            print >>sys.stderr, 'Loading screen ends after %04x' % args.address
            sys.exit(1)
    else:
        loading_screen = None

    args.vz.write(
        get_vz_header(
            args.name.upper(),
            0xf0 if args.basic else 0xf1,
            0x7000 if loading_screen else args.address
        )
    )
    end_address = args.address + len(code)
    if end_address > args.max_address:
        print >>sys.stderr, 'Data too large: ends at $%04x' % end_address
        sys.exit(1)

    if args.basic:
        create_basic(code, args.vz)
    else:
        if loading_screen:
            args.vz.write(loading_screen)
            args.vz.write('\0' * padding)
        args.vz.write(code)


def tokenize(basic):
    r = basic
    for code, token in (
        ('=', '\xd5'),
        ('/', '\xd0'),
        ('-', '\xce'),
        ('+', '\xcd'),
        ('*', '\xcf'),
        ('peek', '\xe5'),
        ('poke', '\xb1'),
        ('print', '\xb2'),
        ('int', '\xd8'),
        ('usr', '\xc1'),
        ('rem', '\x93'),
        ('if', '\x8f'),
        ('then', '\xca'),
        ('goto', '\x8d'),
        ('inkey$', '\xc9'),
        ('sound', '\x9e'),
    ):
        r = r.replace(code, token)
    return r


def create_basic(code, out):
    """Create a BASIC program that contains the machine code in a huge
    REM statement in the end.
    Count backwards from the end of the program to find it.
    """

    global address
    address = basic_start_address

    def write_basic_line(line_number, code):
        global address
        overhead = 5   # next line pointer + line number + null terminator
        next_line = address + len(code) + overhead
        out.write(struct.pack('<HH', next_line, line_number))
        out.write(code)
        out.write('\0')
        address = next_line

    if '\0' in code:
        print >>sys.stderr, 'ERROR: Code contains zero byte'
        sys.exit(1)

    write_basic_line(
        1,
        tokenize(':'.join((
            'F=256',
            # 30969 points to the byte after the three trailing null bytes
            # (but apparently there are four bytes, not three)
            'A=peek(30969)+peek(30970)*F-' + str(4 + len(code)),
            'H=int(A/F)',
            # Set the pointer that the USR function calls
            'poke 30863,H',
            'poke 30862,A-H*F',
            'print usr(0)',
        )))
    )
    write_basic_line(2018, '\x93' + code)
    out.write('\0\0\0')  # trailing null bytes

if __name__ == '__main__':
    main()
