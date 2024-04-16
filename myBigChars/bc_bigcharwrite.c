#include "myBigChars.h"

int
bc_bigcharwrite (int fd, int big[][2], int count)
{
  write (fd, big, count * 2 * sizeof (int));

  return 0;
}