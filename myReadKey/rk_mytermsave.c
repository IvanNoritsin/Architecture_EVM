#include "myReadKey.h"

int
rk_mytermsave (void)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  struct termios term;

  FILE *save;

  if (tcgetattr (terminal, &term) != 0)
    {
      return -1;
    }

  if ((save = fopen ("termsettings", "wb")) == NULL)
    {
      return -1;
    }

  fwrite (&term, sizeof (term), 1, save);
  fclose (save);

  return 0;
}