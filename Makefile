CC = gcc
CFLAGS := -Wall -I./include

SRC_DIR = console
OUTPUT = $(SRC_DIR)/build
 
LIB1=mySimpleComputer

all: $(OUTPUT)/main

$(OUTPUT)/main: $(OUTPUT)/main.o $(LIB1)/build/$(LIB1).a
	$(CC) $(CFLAGS) -o $@ $^

$(OUTPUT)/main.o: $(SRC_DIR)/main.c | $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB1)/build/$(LIB1).a: $(LIB1)
	make -f ./$</Makefile

$(OUTPUT):
	mkdir $@

clean:
	rm -rf $(OUTPUT)
	make -f ./$(LIB1)/Makefile clean