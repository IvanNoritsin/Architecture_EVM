#include "mySimpleComputer.h"

void
printAccumulator (void)
{
  int value;
  sc_accumulatorGet (&value);

  int sign, command, operand;
  sc_commandDecode (value, &sign, &command, &operand);
  printf ("sc: +%02X%02X hex: %X", command, operand, value);
}