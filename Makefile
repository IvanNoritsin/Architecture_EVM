CC = gcc
CFLAGS := -Wall -I./include

SRC_DIR = console
OUTPUT = $(SRC_DIR)/build
 
LIB1=mySimpleComputer
LIB2=myTerm
LIB3=myBigChars
LIB4=myReadKey

all: $(OUTPUT)/main $(OUTPUT)/font 

$(OUTPUT)/main: $(OUTPUT)/main.o $(LIB1)/build/$(LIB1).a $(LIB2)/build/$(LIB2).a $(LIB3)/build/$(LIB3).a $(LIB4)/build/$(LIB4).a
	$(CC) $(CFLAGS) -o $@ $^

$(OUTPUT)/main.o: $(SRC_DIR)/main.c | $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB1)/build/$(LIB1).a: $(LIB1)
	make -f ./$</Makefile

$(LIB2)/build/$(LIB2).a: $(LIB2)
	make -f ./$</Makefile

$(LIB3)/build/$(LIB3).a: $(LIB3)
	make -f ./$</Makefile

$(LIB4)/build/$(LIB4).a: $(LIB4)
	make -f ./$</Makefile

$(OUTPUT)/font: $(OUTPUT)/font.o $(LIB1)/build/$(LIB1).a $(LIB2)/build/$(LIB2).a $(LIB3)/build/$(LIB3).a $(LIB4)/build/$(LIB4).a
	$(CC) $(CFLAGS) -o $@ $^

$(OUTPUT)/font.o: $(SRC_DIR)/font.c | $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT):
	mkdir $@

clean:
	rm -rf $(OUTPUT)
	make -f ./$(LIB1)/Makefile clean
	make -f ./$(LIB2)/Makefile clean
	make -f ./$(LIB3)/Makefile clean
	make -f ./$(LIB4)/Makefile clean