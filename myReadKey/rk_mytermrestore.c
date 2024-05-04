#include "myReadKey.h"

int
rk_mytermrestore (void)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  struct termios term;

  FILE *save;

  if ((save = fopen ("termsettings", "rb")) == NULL)
    {
      return -1;
    }

  if (fread (&term, sizeof (term), 1, save) > 0)
    {
      if (tcsetattr (terminal, TCSAFLUSH, &term) != 0)
        {
          return -1;
        }
    }
  else
    {
      return -1;
    }

  return 0;
}