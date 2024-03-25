#include "mySimpleComputer.h"

int
main ()
{

  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  sc_memorySet (0, 6589);
  sc_memorySet (15, 426);
  sc_memorySet (44, 9862);
  sc_memorySet (72, 13548);
  sc_memorySet (94, 56);
  sc_memorySet (113, 3568);

  for (int i = 0; i < 128; i++)
    {
      if (i % 10 == 0)
        {
          printf ("\n");
        }
      printCell (i);
    }

  printf ("\n");
  printf ("------------------------------------------------------------\n");

  sc_memorySet (224, 16548);

  printf ("------------------------------------------------------------\n");

  sc_regSet (OVERFLOW, 1);
  sc_regSet (IMPULS, 1);

  printFlags ();

  printf ("------------------------------------------------------------\n");

  sc_regSet (NULL_DEL, 215);

  printf ("------------------------------------------------------------\n");

  sc_accumulatorSet (7861);

  printAccumulator ();

  printf ("\n");
  printf ("------------------------------------------------------------\n");

  sc_accumulatorSet (154119);

  printf ("------------------------------------------------------------\n");

  sc_icounterSet (21);

  printCounters ();

  printf ("\n");
  printf ("------------------------------------------------------------\n");

  sc_icounterSet (659595);

  printf ("------------------------------------------------------------\n");

  int mem_value, mem_sign, mem_command, mem_operand;
  sc_memoryGet (72, &mem_value);
  sc_commandDecode (mem_value, &mem_sign, &mem_command, &mem_operand);
  printf ("Memory: %X|%04X|%04X", mem_sign, mem_command, mem_operand);

  printf ("\n");

  int acum_value, acum_sign, acum_command, acum_operand;
  sc_accumulatorGet (&acum_value);
  sc_commandDecode (acum_value, &acum_sign, &acum_command, &acum_operand);
  printf ("Accumulator: %X|%04X|%04X", acum_sign, acum_command, acum_operand);

  printf ("\n");
  printf ("------------------------------------------------------------\n");

  int enc_value;
  int enc_sign = 0;
  int enc_command = 0x3A;
  int enc_operand = 0x59;

  sc_commandEncode (enc_sign, enc_command, enc_operand, &enc_value);
  printDecodedCommand (enc_value);

  printf ("------------------------------------------------------------\n");

  return 0;
}