#include "mySimpleComputer.h"

int
sc_regGet (int registr, int *value)
{
  if (registr < 0 || registr > 4)
    {
      return -1;
    }

  if (flagsRegister & (1 << registr))
    {
      *value = 1;
    }

  else
    {
      *value = 0;
    }

  return 0;
}