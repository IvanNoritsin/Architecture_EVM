CC = gcc

CFLAGS = -c -Wall

DIR = console

all: hello

hello: $(DIR)/test.o $(DIR)/testfunc.o
	$(CC) $(DIR)/test.o $(DIR)/testfunc.o -o test

test.o: $(DIR)/test.c
	$(CC) $(CFLAGS) $(DIR)/test.c

testfunc.o: $(DIR)/testfunc.c
	$(CC) $(CFLAGS) $(DIR)/testfunc.c

clean:
	rm -f $(DIR)/*.o
	rm -f test