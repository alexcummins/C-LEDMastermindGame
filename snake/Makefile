CC      = gcc
CFLAGS  = -Wall -g -D_DEFAULT_SOURCE -std=c99 -Werror -pedantic

.SUFFIXES: .c .o

.PHONY: all clean

all: snakeC

snakeC: snakeC.o
	$(CC) $(CFLAGS) -static snakeC.c -o snakeC -lncurses -ltinfo

clean:
	rm snakeC
rm -f $(wildcard *.o)
