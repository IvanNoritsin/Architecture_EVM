#include "mySimpleComputer.h"

int
sc_accumulatorSet (int value)
{
  if (value < 0 || value > 32767)
    {
      printf ("INVALID ACCUMULATOR VALUE\n");
      return -1;
    }

  accumulator = value;
  return 0;
}