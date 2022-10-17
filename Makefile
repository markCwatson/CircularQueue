CC=gcc
CFLAGS=-I.
DEPS=cqueue/cqueue.h
OBJ=main.o cqueue/cqueue.o
TEST_OBJ=test.o cqueue/cqueue.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o example $(OBJ)

test: $(TEST_OBJ)
	$(CC) -o run_test $(TEST_OBJ)

clean: 
	rm -f example run_test *.o cqueue/*.o