#include "mySimpleComputer.h"

void
printDecodedCommand (int value)
{
  char buf[70];
  char buf_bin[50];
  int index = 0;
  int sign, command, operand;

  sc_commandDecode (value, &sign, &command, &operand);

  if (value == 0)
    {
      sprintf (buf, "dec: 00000 | oct: 00000 | hex: 0000    ");
      sprintf (buf_bin, "000000000000000");
    }
  else
    {
      if (sign == 0)
        {
          sprintf (buf, "dec: %05d | oct: %05o | hex: %04X    ",
                   value & 0x3FFF, value & 0x3FFF, value & 0x3FFF);
        }
      else
        {
          sprintf (buf, "dec:-%05d | oct:-%05o | hex:-%04X    ",
                   value & 0x3FFF, value & 0x3FFF, value & 0x3FFF);
        }

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
    }

  mt_gotoXY (17, 2);
  mt_printText (buf);
  mt_printText ("bin: ");
  mt_printText (buf_bin);
}
