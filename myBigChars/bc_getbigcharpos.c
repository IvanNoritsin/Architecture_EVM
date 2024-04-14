#include "myBigChars.h"

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  if ((x < 0) || (x > 7) || (y < 0) || (y > 7))
    {
      return -1;
    }

  *value = (big[x / 4] >> ((x % 4) * 8 + y)) & 0x1;

  return 0;
}