CC = gcc

CFLAGS = -c -Wall

all: hello

hello: test.o testfunc.o
	$(CC) test.o testfunc.o -o test

test.o: test.c
	$(CC) $(CFLAGS) test.c

testfunc.o: testfunc.c
	$(CC) $(CFLAGS) testfunc.c

clean:
	rm -rf *.o hello