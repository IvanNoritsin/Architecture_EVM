#include "mySimpleComputer.h"

void
printCommand (void)
{
  int icounter_get;
  int memory_get;
  int sign, command, operand;
  char buf[50];

  sc_icounterGet (&icounter_get);
  sc_memoryGet (icounter_get, &memory_get);
  sc_commandDecode (memory_get, &sign, &command, &operand);

  if (sign == 0)
    {
      if (sc_commandValidate (command) == 0)
        {
          sprintf (buf, "+ %02X : %02X", command, operand);
        }
      else
        {
          sprintf (buf, "! + %02X : %02X", command, operand);
        }
    }
  else
    {
      if (sc_commandValidate (command) == 0)
        {
          sprintf (buf, "- %02X : %02X", command, operand);
        }
      else
        {
          sprintf (buf, "! - %02X : %02X", command, operand);
        }
    }

  mt_gotoXY (5, 90);
  mt_printText (buf);
}