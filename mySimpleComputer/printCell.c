#include "mySimpleComputer.h"

void
printCell (int address)
{
  int value;
  if (sc_memoryGet (address, &value) == 0)
    {
      int sign, command, operand;
      sc_commandDecode (value, &sign, &command, &operand);
      printf ("+%02X%02X ", command, operand);
    }
  else
    {
      printf ("ERROR! INCORRECT ADDRESS: %04d\n", address);
    }
}