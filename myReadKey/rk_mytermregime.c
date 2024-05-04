#include "myReadKey.h"

int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  struct termios curr;

  if (tcgetattr (terminal, &curr) != 0)
    {
      return -1;
    }

  if (regime == 1)
    {
      curr.c_lflag |= ICANON;
    }
  else if (regime == 0)
    {
      curr.c_lflag &= ~ICANON;
      curr.c_cc[VTIME] = vtime;
      curr.c_cc[VMIN] = vmin;

      if (echo == 1)
        {
          curr.c_lflag |= ECHO;
        }
      else if (echo == 0)
        {
          curr.c_lflag &= ~ECHO;
        }

      if (sigint == 1)
        {
          curr.c_lflag |= ISIG;
        }

      else if (sigint == 0)
        {
          curr.c_lflag &= ~ISIG;
        }
    }

  if (tcsetattr (terminal, TCSANOW, &curr) != 0)
    {
      return -1;
    }

  return 0;
}