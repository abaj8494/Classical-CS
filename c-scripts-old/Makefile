CC=gcc
CFLAGS=-lm

SRCS=$(wildcard *.c)
BINS=$(patsubst %.c,%,$(SRCS))

.PHONY: all clean

all: $(BINS)

%: %.c
		$(CC) $(CFLAGS) $< -o $(HOME)/.local/bin/c/$@

clean:
		rm -f $(BINS)
