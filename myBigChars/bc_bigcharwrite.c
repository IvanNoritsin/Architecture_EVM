#include "myBigChars.h"

int
bc_bigcharwrite (int fd, int *big, int count)
{
  if (write (fd, big, count * 2 * sizeof (int)))
    {
      return -1;
    }

  return 0;
}