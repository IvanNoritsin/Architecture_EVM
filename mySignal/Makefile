CC := gcc
HEADERS=include
CFLAGS := -Wall -I$(HEADERS)
AR := ar rcs

SRCDIR := mySignal
OUTPUT := $(SRCDIR)/build

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(OUTPUT)/%.o, $(SOURCES))

all: $(OUTPUT)/$(SRCDIR).a

$(OUTPUT)/$(SRCDIR).a: $(OBJECTS)
	$(AR) $@ $^ mySimpleComputer/build/printTerm.o mySimpleComputer/build/sc_commandEncode.o

$(OUTPUT)/%.o: $(SRCDIR)/%.c | $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OUTPUT): 
	mkdir $@ 

clean: 
	rm -rf ./$(OUTPUT)