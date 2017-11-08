TARGETS = arrstats noblanks
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: clean all

all: $(TARGETS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

arrstats: arrstats.o
	$(CC) $< -Wall -o $@.out

noblanks: noblanks.o
	$(CC) $< -Wall -o $@.out

clean:
	rm *.o
	rm *.out
