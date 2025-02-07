#include "myInterface.h"
#include "mySimpleComputer.h"

void
printTerm (int address, int input)
{
  int sign, command, operand;
  int memory_get;
  char buf[50];

  if (input == 0)
    {
      sprintf (buf, "%02X<      ", address);
    }
  if (input == 1)
    {
      sc_memoryGet (address, &memory_get);
      sc_commandDecode (memory_get, &sign, &command, &operand);
      if (sign == 0)
        {
          sprintf (buf, "%02X> +%02X%02X", address, command, operand);
        }
      else
        {
          sprintf (buf, "%02X> -%02X%02X", address, command, operand);
        }
    }

  mt_gotoXY (25, 67);
  mt_printText (buf);
  mt_gotoXY (20, 68);
  mt_delline ();
}