all: compile

combined.wav audio.wav data.wav: compile

compile:
	python parts.py

combined.ogg: combined.wav
	oggenc -q 10 combined.wav

music:
ifndef MUSIC
	$(error MUSIC should point to source wav)
endif
	sox $(MUSIC) -c 1 music.wav

.PHONY: compile music
