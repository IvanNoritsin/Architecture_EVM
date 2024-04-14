CC = gcc
CFLAGS := -Wall -I./include

SRC_DIR = console
OUTPUT = $(SRC_DIR)/build
 
LIB1=mySimpleComputer
LIB2=myTerm
LIB3=myBigChars

all: $(OUTPUT)/main

$(OUTPUT)/main: $(OUTPUT)/main.o $(LIB1)/build/$(LIB1).a $(LIB2)/build/$(LIB2).a $(LIB3)/build/$(LIB3).a
	$(CC) $(CFLAGS) -o $@ $^

$(OUTPUT)/main.o: $(SRC_DIR)/main.c | $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB1)/build/$(LIB1).a: $(LIB1)
	make -f ./$</Makefile

$(LIB2)/build/$(LIB2).a: $(LIB2)
	make -f ./$</Makefile

$(LIB3)/build/$(LIB3).a: $(LIB3)
	make -f ./$</Makefile

$(OUTPUT):
	mkdir $@

clean:
	rm -rf $(OUTPUT)
	make -f ./$(LIB1)/Makefile clean
	make -f ./$(LIB2)/Makefile clean
	make -f ./$(LIB3)/Makefile clean