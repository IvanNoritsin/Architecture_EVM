#include "myBigChars.h"

int
bc_setbigcharpos (int *big, int x, int y, int value)
{
  if ((x < 0) || (x > 7) || (y < 0) || (y > 7))
    {
      return -1;
    }

  if (value == 1)
    {
      big[x / 4] = big[x / 4] | (1 << ((x % 4) * 8 + y));
    }

  else if (value == 0)
    {
      big[x / 4] = big[x / 4] & (~(1 << ((x % 4) * 8 + y)));
    }

  return 0;
}