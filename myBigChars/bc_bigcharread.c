#include "myBigChars.h"

int
bc_bigcharread (int fd, int big[][2], int need_count, int *count)
{
  *count = 0;
  for (int i = 0; i < need_count; ++i)
    {
      for (int j = 0; j < 2; j++)
        {
          read (fd, &big[i][j], sizeof (int));
        }
      (*count)++;
    }

  return 0;
}