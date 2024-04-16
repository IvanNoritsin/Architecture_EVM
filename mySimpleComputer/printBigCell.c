#include "mySimpleComputer.h"

void
printBigCell (int font_array[][2])
{

  int icounter_get;
  int memory_get;
  int sign, command, operand;

  sc_icounterGet (&icounter_get);
  sc_memoryGet (icounter_get, &memory_get);
  sc_commandDecode (memory_get, &sign, &command, &operand);

  if (sign == 0)
    {
      bc_printbigchar (font_array[16], 9, 63, WHITE, BLACK);
    }
  else
    {
      bc_printbigchar (font_array[17], 9, 63, WHITE, BLACK);
    }

  int code;
  for (int i = 0; i < 4; i++)
    {
      switch (i)
        {
        case 0:
          code = (command >> 4) & 0xF;
          break;
        case 1:
          code = command & 0xF;
          break;
        case 2:
          code = (operand >> 4) & 0xF;
          break;
        case 3:
          code = operand & 0xF;
          break;
        }
      bc_printbigchar (font_array[code], 9, 73 + 8 * i, WHITE, BLACK);
    }
}