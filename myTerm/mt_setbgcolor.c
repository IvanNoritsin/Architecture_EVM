#include <myTerm.h>

int
mt_setbgcolor (enum colors color)
{
  if (color < 0 && color > 7)
    {
      return -1;
    }

  char buf[50];
  sprintf (buf, "\E[4%dm", color);

  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  write (terminal, buf, strlen (buf));
  close (terminal);

  return 0;
}