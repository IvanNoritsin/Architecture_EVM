#include "mySimpleComputer.h"
#include "myTerm.h"

int
main ()
{

  mt_clrscr ();
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  sc_memorySet (0, 6589);
  sc_memorySet (15, 426);
  sc_memorySet (44, 9862);
  sc_memorySet (72, 13548);
  sc_memorySet (94, 56);
  sc_memorySet (113, 30568);

  for (int i = 0; i < 128; i++)
    {
      printCell (i, WHITE, BLACK);
    }

  sc_accumulatorSet (7861);
  printAccumulator ();

  sc_regSet (OVERFLOW, 1);
  sc_regSet (IMPULS, 1);
  printFlags ();

  int enc_value;
  int enc_sign = 0;
  int enc_command = 0x3A;
  int enc_operand = 0x59;

  sc_commandEncode (enc_sign, enc_command, enc_operand, &enc_value);
  printDecodedCommand (enc_value);

  sc_icounterSet (72);
  printCounters ();

  printCommand ();

  printTerm (73, 1);
  printTerm (74, 1);
  printTerm (75, 1);
  printTerm (76, 1);
  printTerm (0, 1);

  mt_gotoXY (27, 1);

  return 0;
}