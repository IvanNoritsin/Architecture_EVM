#include "mySignal.h"

void
CU (void)
{
  int value = 0;
  int sign, command, operand;
  int memory_get;
  int acc_sign, acc_command, acc_operand;

  mc_controllerread (icounter, &value);

  if (sc_commandDecode (value, &sign, &command, &operand) != 0)
    {
      sc_regSet (WRONG_COMMAND, 1);
      sc_regSet (IMPULS, 1);
      return;
    }

  if ((command == 0x1E) || (command == 0x1F) || (command == 0x20)
      || (command == 0x21))
    {
      ALU (command, operand);
      return;
    }
  else if ((command == 0x00) || (command == 0x01) || (command == 0x0A)
           || (command == 0x0B))
    {
      INOUT (command, operand);
      return;
    }
  else
    {
      switch (command)
        {
        case 0x14:
          mc_controllerread (operand, &memory_get);
          sc_accumulatorSet (memory_get);
          break;

        case 0x15:
          mc_controllerwrite (operand, accumulator);
          break;

        case 0x28:
          icounter = operand;
          break;

        case 0x29:
          sc_commandDecode (accumulator, &acc_sign, &acc_command,
                            &acc_operand);
          if (acc_sign == 1)
            {
              icounter = operand;
            }
          break;

        case 0x2A:
          if (accumulator == 0)
            {
              icounter = operand;
            }
          break;

        case 0x2B:
          sc_regSet (IMPULS, 1);
          icounter = 0;
          break;

        default:
          sc_regSet (WRONG_COMMAND, 1);
          sc_regSet (IMPULS, 1);
          break;
        }
    }
}