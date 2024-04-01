#include "mySimpleComputer.h"

int
sc_memorySet (int address, int value)
{
  if (address < 0 || address > 127)
    {
      sc_regSet (OUT_OF_MEMORY, 1);
      return -1;
    }

  else
    {
      memory[address] = value;
      return 0;
    }
}