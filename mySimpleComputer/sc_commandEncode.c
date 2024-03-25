#include "mySimpleComputer.h"

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (sign != 0 && sign != 1)
    {
      printf ("ERROR\n");
      return -1;
    }

  if (sc_commandValidate (command) == 1)
    {
      sc_regSet (WRONG_COMMAND, 1);
      printf ("ERROR\n");
      return -1;
    }

  if (operand < 0 || operand > 127)
    {
      sc_regSet (OUT_OF_MEMORY, 1);
      printf ("ERROR\n");
      return -1;
    }

  *value = (sign << 14) | (command << 7) | operand;
  return 0;
}