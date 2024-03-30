#include <myTerm.h>

int
mt_delline (void)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  write (terminal, "\E[M", sizeof ("\E[M"));
  close (terminal);
}