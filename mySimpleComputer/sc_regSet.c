#include "mySimpleComputer.h"

int
sc_regSet (int registr, int value)
{
  if (registr < 0 || registr > 4)
    {
      return -1;
    }

  if (value < 0 || value > 1)
    {
      return -1;
    }

  if (value == 1)
    {
      flagsRegister = flagsRegister | (1 << registr);
    }

  else
    {
      flagsRegister = flagsRegister & ~(1 << registr);
    }

  return 0;
}