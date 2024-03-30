#include <myTerm.h>

int
mt_gotoXY (int x, int y)
{
  int rows, cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    {
      return -1;
    }

  if (x > rows || y > cols || x <= 0 || y <= 0)
    {
      return -1;
    }

  char buf[50];
  sprintf (buf, "\E[%d;%dH", x, y);

  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  write (terminal, buf, strlen (buf));
  close (terminal);

  return 0;
}