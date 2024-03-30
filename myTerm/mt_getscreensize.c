#include <myTerm.h>

int
mt_getscreensize (int *rows, int *cols)
{
  struct winsize win_size;
  if (ioctl (1, TIOCGWINSZ, &win_size))
    {
      return -1;
    }

  *rows = win_size.ws_row;
  *cols = win_size.ws_col;

  return 0;
}