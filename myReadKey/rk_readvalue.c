#include "myReadKey.h"

int
rk_readvalue (int *value, int timeout)
{
  char buf[3];
  char sign_read;
  int sign, command, operand;
  rk_mytermregime (0, timeout, 1, 1, 1);

  int terminal = open (TERM, O_RDWR);
  if (terminal == -1)
    {
      return -1;
    }
  int numRead = read (terminal, buf, sizeof (buf));
  buf[numRead] = '\0';
  sscanf (buf, "%c", &sign_read);
  if (sign_read == '+')
    {
      sign = 0;
    }
  else if (sign_read == '-')
    {
      sign = 1;
    }
  else
    {
      return -1;
    }

  rk_mytermregime (0, timeout, 2, 1, 1);
  numRead = read (terminal, buf, sizeof (buf));
  buf[numRead] = '\0';
  sscanf (buf, "%X", &command);

  rk_mytermregime (0, timeout, 2, 1, 1);
  numRead = read (terminal, buf, sizeof (buf));
  buf[numRead] = '\0';
  sscanf (buf, "%X", &operand);

  if (command < 0 || command > 127)
    {
      return -1;
    }

  if (operand < 0 || operand > 127)
    {
      return -1;
    }

  *value = (sign << 14) | (command << 7) | operand;

  return 0;
}