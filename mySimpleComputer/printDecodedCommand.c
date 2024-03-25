#include "mySimpleComputer.h"

void
printDecodedCommand (int value)
{
  printf ("dec: %d | ", value);
  printf ("oct: %o | ", value);
  printf ("hex: %X   ", value);
  printf ("bin: ");
  for (int i = 14; i >= 0; i--)
    {
      if (value & (1 << i))
        {
          printf ("1");
        }
      else
        {
          printf ("0");
        }
    }
  printf ("\n");
}
