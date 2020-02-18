from array import array

if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(
        description='Cut out a part of a binary file'
    )
    parser.add_argument(
        '--base', type=lambda v: int(v, 0), default=0,
        help='The address in memory space the input file starts at',
    )
    parser.add_argument(
        '--start', type=lambda v: int(v, 0), required=True,
        help='The address in memory space to start output at'
    )
    parser.add_argument(
        '--length', type=lambda v: int(v, 0), default=None,
        help='The max number of bytes to output'
    )
    parser.add_argument(
        'input', type=argparse.FileType('rb'),
        help='Input binary',
    )
    parser.add_argument(
        'output', type=argparse.FileType('wb'),
        help='Output binary'
    )

    args = parser.parse_args()

    data = array('B', args.input.read())
    trim_start = args.start - args.base
    #print 'Removing', trim_start, 'leading bytes'
    data = data[trim_start:]
    if args.length is not None:
        data = data[:args.length]
    args.output.write(data)
