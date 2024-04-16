#include "mySimpleComputer.h"

void
printDecodedCommand (int value)
{
  char buf[50];
  char buf_bin[50];
  int index = 0;

  sprintf (buf, "dec: %d | oct: %o | hex: %X     ", value, value, value);

  for (int i = 14; i >= 0; i--)
    {
      if (value & (1 << i))
        {
          buf_bin[index++] = '1';
        }
      else
        {
          buf_bin[index++] = '0';
        }
    }

  mt_gotoXY (17, 2);
  mt_printText (buf);
  mt_printText ("bin: ");
  mt_printText (buf_bin);
}
