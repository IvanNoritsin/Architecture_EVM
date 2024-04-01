#include "myTerm.h"

int
mt_clrscr (void)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  write (terminal, "\E[H\E[J", sizeof ("\E[H\E[J"));
  close (terminal);

  return 0;
}