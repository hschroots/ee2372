TARGETS = charblock dsort
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: clean all

all: $(TARGETS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

charblock: charblock.o
	$(CC) $< -Wall -o $@.out

dsort: dsort.o
	$(CC) $< -Wall -o $@.out

clean:
	rm *.o
	rm *.out
