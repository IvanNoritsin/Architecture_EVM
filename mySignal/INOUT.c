#include "myInterface.h"
#include "mySignal.h"

void
INOUT (int command, int operand)
{
  switch (command)
    {
    case 0x00:
      break;

    case 0x01:
      mt_gotoXY (26, 1);
      mt_printText ("Норицин Иван Алексеевич, ИА-232");
      break;

    case 0x0A:
      printTerm (operand, 0);
      interface (font_array);
      mt_gotoXY (24, 71);
      int value;
      if (rk_readvalue (&value, 0) == -1)
        {
          break;
        }
      sc_memorySet (operand, value);
      break;

    case 0x0B:
      printTerm (operand, 1);
      break;

    default:
      break;
    }
}