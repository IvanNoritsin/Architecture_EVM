#include <myTerm.h>

int
mt_setcursorvisible (int value)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  if (value == 0)
    {
      write (terminal, "\E[?25l\E[?1c", sizeof ("\E[?25l\E[?1c"));
      close (terminal);
      return 0;
    }

  if (value == 1)
    {
      write (terminal, "\E[?25h\E[?8c", sizeof ("\E[?25h\E[?8c"));
      close (terminal);
      return 0;
    }

    else {
        return -1;
    }
}