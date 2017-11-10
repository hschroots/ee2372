

TARGET = binread

CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: clean all

all: $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

binread : binread.o
	$(CC) $(CFLAGS) $< -o $@.out

clean:
	rm *.o
	rm *.out
