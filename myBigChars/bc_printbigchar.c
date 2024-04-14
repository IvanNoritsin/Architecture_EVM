#include "myBigChars.h"

int
bc_printbigchar (int big[2], int x, int y, enum colors fg, enum colors bg)
{
  for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
        {
          mt_gotoXY (x + i, y + j);
          int value;
          if (bc_getbigcharpos (big, i, j, &value) == -1)
            {
              return -1;
            }

          if (value == 1)
            {
              bc_printA (ACS_CKBOARD);
            }

          if (value == 0)
            {
              bc_printA (" ");
            }
        }
    }

  return 0;
}