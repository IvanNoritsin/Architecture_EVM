#include "myReadKey.h"

int
rk_readkey (enum keys *key)
{
  struct termios curr;
  char buf[5];
  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }

  if (tcgetattr (terminal, &curr) != 0)
    {
      return -1;
    }

  if (rk_mytermregime (0, 0, 1, 0, 1) != 0)
    {
      return -1;
    }

  read (terminal, buf, sizeof (buf));

  if (buf[0] == '\033')
    {
      switch (buf[1])
        {
        case '[':
          switch (buf[2])
            {
            case 'A':
              *key = UP_KEY;
              break;
            case 'B':
              *key = DOWN_KEY;
              break;
            case 'C':
              *key = RIGHT_KEY;
              break;
            case 'D':
              *key = LEFT_KEY;
              break;
            case '1':
              if (buf[3] == '5' && buf[4] == '~')
                {
                  *key = F5_KEY;
                }
              if (buf[3] == '7' && buf[4] == '~')
                {
                  *key = F6_KEY;
                }
              break;
            default:
              break;
            }
          break;
        default:
          *key = ESC_KEY;
          break;
        }
    }

  else if (buf[0] == '\n')
    {
      *key = ENTER_KEY;
    }

  else
    {
      switch (buf[0])
        {
        case 'l':
        case 'L':
          *key = L_KEY;
          break;
        case 's':
        case 'S':
          *key = S_KEY;
          break;
        case 'i':
        case 'I':
          *key = I_KEY;
          break;
        case 'r':
        case 'R':
          *key = R_KEY;
          break;
        case 't':
        case 'T':
          *key = T_KEY;
          break;
        default:
          *key = UNKNOWN_KEY;
          break;
        }
    }

  if (tcsetattr (terminal, TCSANOW, &curr) != 0)
    {
      return -1;
    }

  return 0;
}