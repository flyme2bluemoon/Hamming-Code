CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -pthread -O3

.PHONY: all sender clean

all: prebuild sender corrupt recover clean

prebuild:
	mkdir -p bin

sender: hamming.o sender.c
	$(CC) $(CFLAGS) -o bin/sender sender.c hamming.o

corrupt: hamming.o corrupt.c
	$(CC) $(CFLAGS) -o bin/corrupt corrupt.c hamming.o

recover: hamming.o recover.c
	$(CC) $(CFLAGS) -o bin/recover recover.c hamming.o

hamming.o: hamming.c hamming.h
	$(CC) $(CFLAGS) -o hamming.o -c hamming.c

clean:
	rm *.o
