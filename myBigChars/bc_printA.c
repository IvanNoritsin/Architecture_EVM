#include "myBigChars.h"

int
bc_printA (char *str)
{
  char buf[500];
  sprintf (buf, "\E(0%s\E(B", str);
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  write (terminal, buf, strlen (buf));
  close (terminal);

  return 0;
}