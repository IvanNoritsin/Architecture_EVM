#include "mySimpleComputer.h"
#include "myTerm.h"

void
printAccumulator (void)
{
  int value;
  char buf[50];

  sc_accumulatorGet (&value);
  int sign, command, operand;
  sc_commandDecode (value, &sign, &command, &operand);

  sprintf (buf, "sc: +%02X%02X hex: %X", command, operand, value);
  mt_gotoXY (2, 64);
  mt_printText (buf);
}