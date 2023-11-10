CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

SOURCES = $(wildcard source/*.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: bruteforce

bruteforce: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ -lpthread -lrt

source/%.o: source/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) bruteforce