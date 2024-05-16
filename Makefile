CC = gcc
CFLAGS := -g -Wall -I./include

SRC_DIR = console
OUTPUT = $(SRC_DIR)/build
 
LIB1=mySimpleComputer
LIB2=myTerm
LIB3=myBigChars
LIB4=myReadKey
LIB5=mySignal
LIB6=myController

LIB7=simpleassembler
LIB7_OUTPUT=$(LIB7)/build

all: $(LIB7_OUTPUT)/sa_translator $(OUTPUT)/main $(OUTPUT)/font

$(OUTPUT)/main: $(OUTPUT)/main.o $(LIB1)/build/$(LIB1).a $(LIB2)/build/$(LIB2).a $(LIB3)/build/$(LIB3).a $(LIB4)/build/$(LIB4).a $(LIB5)/build/$(LIB5).a $(LIB6)/build/$(LIB6).a 
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

$(LIB5)/build/$(LIB5).a: $(LIB5)
	make -f ./$</Makefile

$(LIB6)/build/$(LIB6).a: $(LIB6)
	make -f ./$</Makefile		

$(OUTPUT)/font: $(OUTPUT)/font.o $(LIB3)/build/$(LIB3).a
	$(CC) $(CFLAGS) -o $@ $^

$(OUTPUT)/font.o: $(SRC_DIR)/font.c | $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@

# translators make
$(LIB7_OUTPUT)/sa_translator: $(LIB7_OUTPUT)/sa_translator.o $(LIB1)/build/$(LIB1).a
	$(CC) $(CFLAGS) -o $@ $^

$(LIB7_OUTPUT)/sa_translator.o: $(LIB7)/sa_translator.c | $(LIB7_OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB7_OUTPUT): 
	mkdir $@
# 

$(OUTPUT):
	mkdir $@

clean:
	rm -rf $(OUTPUT)
	rm -rf $(LIB7_OUTPUT)
	make -f ./$(LIB1)/Makefile clean
	make -f ./$(LIB2)/Makefile clean
	make -f ./$(LIB3)/Makefile clean
	make -f ./$(LIB4)/Makefile clean
	make -f ./$(LIB5)/Makefile clean
	make -f ./$(LIB6)/Makefile clean