#include "mySimpleComputer.h"
#include <stdio.h>
#include <stdlib.h>

FILE *assemblerFile = NULL;

void
loadFile (const char *filename)
{
  assemblerFile = fopen (filename, "r");
  if (assemblerFile == NULL)
    {
      printf ("Ошибка! Не удалось открыть файл!\n");
      exit (0);
    }
}

void
translatorSA (const char *filename)
{
  char *addressChar = NULL, *commandChar = NULL, *operandChar = NULL;
  int address, msc_sign, msc_command, msc_operand;
  int value, msc_value;
  int command, operand;
  char line[255];
  char *ptr;

  while (fgets (line, sizeof (line), assemblerFile) != NULL)
    {
      if (line[0] == '\n' || line[0] == '\0')
        continue;

      ptr = strtok (line, " ");
      addressChar = ptr;

      ptr = strtok (NULL, " ");
      commandChar = ptr;

      ptr = strtok (NULL, " ");
      operandChar = ptr;

      ptr = strtok (NULL, " ");

      if (ptr != NULL && ptr[0] != ';')
        {
          printf ("Ошибка синтаксиса!\n");
          exit (0);
        }

      if (addressChar == NULL || commandChar == NULL || operandChar == NULL)
        {
          printf ("Ошибка синтаксиса!\n");
          exit (0);
        }

      address = atoi (addressChar);

      if (address < 0 || address > 127)
        {
          printf ("Недопустимое значение адреса!\n");
          exit (0);
        }

      if (commandChar[0] == '=')
        {
          if (operandChar[0] != '+' && operandChar[0] != '-')
            {
              printf ("Ошибка синтаксиса!\n");
              exit (0);
            }
          else if (strlen (operandChar) != 5 && strlen (operandChar) != 6)
            {
              printf ("Ошибка синтаксиса!\n");
              printf ("%ld", strlen (operandChar));
              exit (0);
            }

          ptr = strtok (operandChar, "+-");
          sscanf (ptr, "%x\n", &value);

          if (operandChar[0] == '+')
            {
              msc_sign = 0;
            }
          else
            {
              msc_sign = 1;
            }

          msc_command = value >> 8;
          msc_operand = value & 0x7F;

          if (msc_command < 0 || msc_command > 0x7F || msc_operand < 0
              || msc_operand > 0x7F)
            {
              printf ("Недопустимое значение ячейки памяти!\n");
            }

          sc_commandEncode (msc_sign, msc_command, msc_operand, &msc_value);
        }

      else
        {
          operand = atoi (operandChar);
          if (operand < 0 || operand > 127)
            {
              printf ("Недопустимое значение операнда!\n");
              exit (0);
            }
        }

      if (!strcmp (commandChar, "NOP"))
        {
          command = 0x00;
        }
      else if (!strcmp (commandChar, "CPUINFO"))
        {
          command = 0x01;
        }
      else if (!strcmp (commandChar, "READ"))
        {
          command = 0x0A;
        }
      else if (!strcmp (commandChar, "WRITE"))
        {
          command = 0x0B;
        }
      else if (!strcmp (commandChar, "LOAD"))
        {
          command = 0x14;
        }
      else if (!strcmp (commandChar, "STORE"))
        {
          command = 0x15;
        }
      else if (!strcmp (commandChar, "ADD"))
        {
          command = 0x1E;
        }
      else if (!strcmp (commandChar, "SUB"))
        {
          command = 0x1F;
        }
      else if (!strcmp (commandChar, "DIVIDE"))
        {
          command = 0x20;
        }
      else if (!strcmp (commandChar, "MUL"))
        {
          command = 0x21;
        }
      else if (!strcmp (commandChar, "JUMP"))
        {
          command = 0x28;
        }
      else if (!strcmp (commandChar, "JNEG"))
        {
          command = 0x29;
        }
      else if (!strcmp (commandChar, "JZ"))
        {
          command = 0x2A;
        }
      else if (!strcmp (commandChar, "HALT"))
        {
          command = 0x2B;
        }
      else if (commandChar[0] == '=')
        {
          sc_memorySet (address, msc_value);
          sc_memorySave (strdup (filename));
          continue;
        }
      else
        {
          printf ("Ошибка! Неверная команда!\n");
          exit (0);
        }

      sc_commandEncode (0, command, operand, &msc_value);
      sc_memorySet (address, msc_value);

      sc_memorySave (strdup (filename));
    }
}

int
main (int argc, char *argv[])
{
  sc_memoryInit ();
  loadFile (argv[1]);
  translatorSA (argv[2]);
  return 0;
}