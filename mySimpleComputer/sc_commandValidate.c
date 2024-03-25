#include "mySimpleComputer.h"

int
sc_commandValidate (int command)
{
  if (command != 0x00 && command != 0x01 && command != 0x0A && command != 0x0B
      && command != 0x14 && command != 0x15 && command != 0x1E
      && command != 0x1F && command != 0x20 && command != 0x21
      && !(command >= 0x28 && command <= 0x2B)
      && !(command >= 0x33 && command <= 0x4C))
    {
      return 1;
    }

  return 0;
}