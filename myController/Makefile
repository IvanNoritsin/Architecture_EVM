CC := gcc
HEADERS=include
CFLAGS := -Wall -I$(HEADERS)
AR := ar rcs

SRCDIR := myController
OUTPUT := $(SRCDIR)/build

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(OUTPUT)/%.o, $(SOURCES))

all: $(OUTPUT)/$(SRCDIR).a

$(OUTPUT)/$(SRCDIR).a: $(OBJECTS)
	$(AR) $@ $^ mySimpleComputer/build/sc_tcounterSet.o

$(OUTPUT)/%.o: $(SRCDIR)/%.c | $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OUTPUT): 
	mkdir $@ 

clean: 
	rm -rf ./$(OUTPUT)