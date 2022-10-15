CC=gcc
CFLAGS=-I.
DEPS = cqueue/cqueue.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

example: main.o cqueue/cqueue.o 
	$(CC) -o example main.o cqueue/cqueue.o 