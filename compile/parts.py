import wave
import sys
from array import array
from collections import namedtuple
import struct

part_samplerate = 44100

beat = 60.0 / 140
bar = beat * 4
frames = 1.0 / 50

# length: How much time it takes to load part
# load_start: Time when part should start loading
# load_end: Time when part should finish loading
# runtime: For how long this part plays
# audio: audio samples
Part = namedtuple('Part', 'name length load_start load_end runtime audio')
parts = []


class Error(RuntimeError):
    pass


def read_wav(filename, samplerate, channels, sample_width):
    wavefile = wave.open(filename, 'rb')
    if wavefile.getsampwidth() != sample_width:
        raise Error(
            'Expected %d bit audio, not %d in %s' %
            (sample_width * 8, wavefile.getsampwidth() * 8, filename)
        )
    if wavefile.getnchannels() != channels:
        raise Error(
            'Expected %d channels, not %d in %s' %
            (channels, wavefile.getnchannels(), filename)
        )
    size = wavefile.getnframes()
    if sample_width == 1:
        typename = 'B'
    else:
        assert sample_width == 2
        typename = 'h'
    audio = array(typename, wavefile.readframes(size))

    assert len(audio) == size, \
        'Read %d samples, expected %d' % (len(audio), size)

    if wavefile.getframerate() == samplerate:
        pass
    elif wavefile.getframerate() == samplerate // 2:
        # Upsample
        audio = array(typename, [audio[i // 2] for i in range(size * 2)])
    else:
        raise Error(
            'Expected %d Hz, not %d in %s' %
            (samplerate, wavefile.getframerate(), filename)
        )

    return audio


def add_part(name, runtime, load_start=None, load_end=None, sync=None):
    """
    runtime: How long this part is shown
    load_start: Time when this part starts loading
    load_end: Time when this part ends loading and starts running
    """

    assert load_start is None or load_end is None

    audio = read_wav('../{0}/{0}-speed.wav'.format(name), part_samplerate, 1, 1)

    length = len(audio) / float(part_samplerate)

    prev_part = parts[-1] if parts else None

    if load_start is None and load_end is None:
        if prev_part is None:
            load_start = 0
        else:
            earliest_start = prev_part.load_end + prev_part.runtime
            earliest_end = earliest_start + length
            if sync is None:
                load_start = earliest_start
            else:
                load_end = int(earliest_end / sync) * sync
                if load_end < earliest_end:
                    load_end += sync
                assert load_end >= earliest_end


    if load_start is None:
        load_start = load_end - length
    if load_end is None:
        load_end = load_start + length

    parts.append(
        Part(name, length, float(load_start), float(load_end), runtime, audio)
    )

add_part('gdpr', load_end=0, runtime=8 * bar)
add_part('technobabble', load_end=8 * bar, runtime = 16, sync=beat)
add_part('turtle', runtime=4.7)
add_part('circles1', runtime=10.5 + 32 * frames)
add_part('trans', runtime=19 * frames)
add_part('helix', runtime=11.5, load_end=54.0)
add_part('rot8', runtime=172 * 9 * frames + 2, load_end=65.14)
add_part('ykaros', runtime=15 + (32 + 8) * frames, sync=beat)     # transition out: 32 frames
add_part('trans', runtime=19 * frames)
add_part('screw', runtime=8.5)
add_part('fldscroll', runtime=132 * 9 * frames + .5, load_end=131.25)  # 132 characters * 9 pixels
#add_part('waving', runtime=(42 * 4 + 21 * 3) * frames, sync=bar)
add_part('waving', runtime=20, sync=bar)
add_part('face1', runtime=1.9)
add_part('cred1', runtime=68 * frames)
add_part('face2', runtime=1.9)
add_part('cred2', runtime=68 * frames)
add_part('face3', runtime=1.9)
add_part('cred3', runtime=68 * frames)
add_part('face4', runtime=1.9)
add_part('cred4', runtime=68 * frames)
add_part('kefrens', runtime=16)
add_part('brag', runtime=18.4)
add_part('rain', runtime=10)
add_part('trans', runtime=19 * frames)
add_part('endlogo', runtime=5)

parts.sort(key=lambda v: v.load_start)


def get_gap(index):
    """
    How long between the given part ends loading and the next starts loading
    """

    if index < len(parts) - 1:
        return parts[index + 1].load_start - parts[index].load_end
    return None


#      0         1         2         3         4         5         6         7
#      01234567890123456789012345678901234567890123456789012345678901234567890
print 'Part                Load start  Load end   Runtime       Gap  (Frames)'
for index, part in enumerate(parts):
    gap = get_gap(index) or 1000
    print '%-20s%10.2f%10.2f%10.2f%10.2f%10d' % (
        part.name, part.load_start, part.load_end,
        part.runtime,
        gap, int(gap * 50),
    )

if any(get_gap(i) < 0 for i in range(len(parts) - 1)):
       print 'Error: Overlapping parts'
       sys.exit(1)

boot = read_wav('../boot/boot.wav', 44100, 1, 1)

# The sample at time 0 (which is a few seconds after start of file)
zero_sample = int((-parts[0].load_start + 1) * part_samplerate + len(boot))

data_audio = array(
    'B',
    [0x80] * int((parts[-1].load_end + 1) * part_samplerate + zero_sample)
)

data_audio[0:len(boot)] = boot
for index, part in enumerate(parts):
    sample_number = int(part.load_start * part_samplerate) + zero_sample
    data_audio[sample_number:sample_number + len(part.audio)] = part.audio

w = wave.open('data.wav', 'wb')
w.setframerate(part_samplerate)
w.setnchannels(1)
w.setsampwidth(1)
w.writeframes(data_audio)
w.close()

original_music = read_wav('music.wav', part_samplerate, 1, 2)
music = array('h', [0] * zero_sample)
music += original_music
# Mix in boot code in music channel so people can hear that we're tape loading
music[0:len(boot)] = array('h', [
    (s - 0x80) * 0x10
    for s in boot
])

w = wave.open('audio.wav', 'wb')
w.setnchannels(1)
w.setsampwidth(2)
w.setframerate(part_samplerate)
raw_music = array('b', music.tostring())
w.writeframes(raw_music)
w.close()

combined_length = max(len(music), len(data_audio))
combined_audio = [0] * (combined_length * 2)
combined_audio[0:len(data_audio) * 2:2] = [
    (sample - 0x80) * 0xff
    for sample in data_audio
]
combined_audio[1:len(music) * 2:2] = music

w = wave.open('combined.wav', 'wb')
w.setnchannels(2)
w.setsampwidth(2)
w.setframerate(part_samplerate)
w.writeframes(
    struct.pack('<%dh' % (combined_length * 2), *combined_audio)
)
w.close()
