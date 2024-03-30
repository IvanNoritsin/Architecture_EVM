#include <myTerm.h>

int
mt_setdefaultcolor (void)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  write (terminal, "\E[0m", sizeof ("\E[0m"));
  close (terminal);

  return 0;
}