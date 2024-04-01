#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include "myTerm.h"
#include <stdio.h>

#define OVERFLOW 0
#define NULL_DEL 1
#define OUT_OF_MEMORY 2
#define IMPULS 3
#define WRONG_COMMAND 4

extern int memory[128];
extern int flagsRegister;
extern int accumulator;
extern int icounter;

int sc_memoryInit ();
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);
int sc_regInit ();
int sc_regSet (int registr, int value);
int sc_regGet (int registr, int *value);
int sc_accumulatorInit ();
int sc_accumulatorSet (int value);
int sc_accumulatorGet (int *value);
int sc_icounterInit ();
int sc_icounterSet (int value);
int sc_icounterGet (int *value);
int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
int sc_commandValidate (int command);
void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();
void printCommand ();
void printTerm (int address, int input);

#endif