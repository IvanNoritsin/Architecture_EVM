#include "mySimpleComputer.h"

int
sc_memoryInit (void)
{
  for (int i = 0; i < 128; i++)
    {
      memory[i] = 0;
    }

  return 0;
}