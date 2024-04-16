#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"

void
printCell (int address, enum colors fg, enum colors bg)
{
  int value;
  int _x, _y;
  char buf[50];
  char space[] = " ";

  if (sc_memoryGet (address, &value) == 0)
    {
      int sign, command, operand;
      sc_commandDecode (value, &sign, &command, &operand);
      if (sign == 0)
        {
          _x = address / 10 + 2;
          _y = address % 10 * 6 + 2;
          sprintf (buf, "+%02X%02X", command, operand);
          mt_setfgcolor (fg);
          mt_setbgcolor (bg);
          mt_gotoXY (_x, _y);
          mt_printText (buf);
          mt_setdefaultcolor ();
          mt_printText (space);
        }
      else
        {
          _x = address / 10 + 2;
          _y = address % 10 * 6 + 2;
          sprintf (buf, "-%02X%02X", command, operand);
          mt_setfgcolor (fg);
          mt_setbgcolor (bg);
          mt_gotoXY (_x, _y);
          mt_printText (buf);
          mt_setdefaultcolor ();
          mt_printText (space);
        }
    }
  else
    {
      printf ("ERROR! INCORRECT ADDRESS: %04d\n", address);
    }
}