#ifndef MY_SIGNAL_H
#define MY_SIGNAL_H

#include "myReadKey.h"
#include "mySimpleComputer.h"
#include "myTerm.h"
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>

void CU ();
int ALU (int command, int operand);
void INOUT (int command, int operand);
void signals ();
void IRC (int signum);

#endif