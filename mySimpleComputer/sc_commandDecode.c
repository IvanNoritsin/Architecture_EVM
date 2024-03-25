#include "mySimpleComputer.h"

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (value < 0 || value > 0x7FFF)
    {
      sc_regSet (WRONG_COMMAND, 1);
      return -1;
    }

  *sign = (value >> 14) & 1;
  *command = (value >> 7) & 0x7F;
  *operand = value & 0x7F;

  return 0;
}