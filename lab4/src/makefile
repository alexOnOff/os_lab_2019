CC=gcc
CFLAGS=-I.
all: parallel_sum

parallel_sum : utils.o sum.o utils.h sum.h
	$(CC) -pthread -o parallel_sum utils.o sum.o parallel_sum.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

Sum : Sum.h
	$(CC) -o sum.o -c sum.c $(CFLAGS)

clean :
	rm utils.o sum.o parallel_sum