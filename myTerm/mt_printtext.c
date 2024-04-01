#include "myTerm.h"

int
mt_printText (char *text)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }
  write (terminal, text, strlen (text));
  close (terminal);
  return 0;
}