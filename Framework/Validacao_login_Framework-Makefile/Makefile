CC=gcc
CFLAGS=-Iinclude -Wall

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

all: libmeuframework.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libmeuframework.a: $(OBJ)
	ar rcs build/libmeuframework.a $(OBJ)

clean:
	rm -f src/*.o
	rm -f build/*.a
