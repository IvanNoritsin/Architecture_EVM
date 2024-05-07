#include "mySignal.h"

int
ALU (int command, int operand)
{
  int memory_get;
  int mem_sign, mem_command, mem_operand;
  int acc_sign, acc_command, acc_operand;
  int accumulatorValue, memoryValue;
  int result, newAcc_sign, newAcc_command, newAcc_operand, newAcc_value,
      newAccumulator;
  sc_memoryGet (operand, &memory_get);

  switch (command)
    {
    case 0x1E:
      sc_commandDecode (accumulator, &acc_sign, &acc_command, &acc_operand);
      sc_commandDecode (memory_get, &mem_sign, &mem_command, &mem_operand);

      accumulatorValue = accumulator & 0x3FFF;
      memoryValue = memory_get & 0x3FFF;

      if (acc_sign == 1)
        {
          accumulatorValue = -accumulatorValue;
        }

      if (mem_sign == 1)
        {
          memoryValue = -memoryValue;
        }

      result = accumulatorValue + memoryValue;

      if (result < -16383 || result > 16383)
        {
          sc_regSet (OVERFLOW, 1);
          sc_regSet (IMPULS, 1);
          break;
        }

      if (result < 0)
        {
          newAcc_sign = 1;
        }
      else
        {
          newAcc_sign = 0;
        }

      if (result < 0)
        {
          newAcc_value = -result;
        }
      else
        {
          newAcc_value = result;
        }

      newAcc_command = newAcc_value >> 7;
      newAcc_operand = newAcc_value & 0x7F;

      sc_commandEncode (newAcc_sign, newAcc_command, newAcc_operand,
                        &newAccumulator);
      sc_accumulatorSet (newAccumulator);
      break;

    case 0x1F:
      sc_commandDecode (accumulator, &acc_sign, &acc_command, &acc_operand);
      sc_commandDecode (memory_get, &mem_sign, &mem_command, &mem_operand);

      accumulatorValue = accumulator & 0x3FFF;
      memoryValue = memory_get & 0x3FFF;

      if (acc_sign == 1)
        {
          accumulatorValue = -accumulatorValue;
        }

      if (mem_sign == 1)
        {
          memoryValue = -memoryValue;
        }

      result = accumulatorValue - memoryValue;

      if (result < -16383 || result > 16383)
        {
          sc_regSet (OVERFLOW, 1);
          sc_regSet (IMPULS, 1);
          break;
        }

      if (result < 0)
        {
          newAcc_sign = 1;
        }
      else
        {
          newAcc_sign = 0;
        }

      if (result < 0)
        {
          newAcc_value = -result;
        }
      else
        {
          newAcc_value = result;
        }

      newAcc_command = newAcc_value >> 7;
      newAcc_operand = newAcc_value & 0x7F;

      sc_commandEncode (newAcc_sign, newAcc_command, newAcc_operand,
                        &newAccumulator);
      sc_accumulatorSet (newAccumulator);
      break;

    case 0x20:
      sc_commandDecode (accumulator, &acc_sign, &acc_command, &acc_operand);
      sc_commandDecode (memory_get, &mem_sign, &mem_command, &mem_operand);

      accumulatorValue = accumulator & 0x3FFF;
      memoryValue = memory_get & 0x3FFF;

      if (memoryValue == 0)
        {
          sc_regSet (NULL_DEL, 1);
          sc_regSet (IMPULS, 1);
          break;
        }

      if (acc_sign == 1)
        {
          accumulatorValue = -accumulatorValue;
        }

      if (mem_sign == 1)
        {
          memoryValue = -memoryValue;
        }

      result = accumulatorValue / memoryValue;

      if (result < -16383 || result > 16383)
        {
          sc_regSet (OVERFLOW, 1);
          sc_regSet (IMPULS, 1);
          break;
        }

      if (result < 0)
        {
          newAcc_sign = 1;
        }
      else
        {
          newAcc_sign = 0;
        }

      if (result < 0)
        {
          newAcc_value = -result;
        }
      else
        {
          newAcc_value = result;
        }

      newAcc_command = newAcc_value >> 7;
      newAcc_operand = newAcc_value & 0x7F;

      sc_commandEncode (newAcc_sign, newAcc_command, newAcc_operand,
                        &newAccumulator);
      sc_accumulatorSet (newAccumulator);
      break;

    case 0x21:
      sc_commandDecode (accumulator, &acc_sign, &acc_command, &acc_operand);
      sc_commandDecode (memory_get, &mem_sign, &mem_command, &mem_operand);

      accumulatorValue = accumulator & 0x3FFF;
      memoryValue = memory_get & 0x3FFF;

      if (acc_sign == 1)
        {
          accumulatorValue = -accumulatorValue;
        }

      if (mem_sign == 1)
        {
          memoryValue = -memoryValue;
        }

      result = accumulatorValue * memoryValue;

      if (result < -16383 || result > 16383)
        {
          sc_regSet (OVERFLOW, 1);
          sc_regSet (IMPULS, 1);
          break;
        }

      if (result < 0)
        {
          newAcc_sign = 1;
        }
      else
        {
          newAcc_sign = 0;
        }

      if (result < 0)
        {
          newAcc_value = -result;
        }
      else
        {
          newAcc_value = result;
        }

      newAcc_command = newAcc_value >> 7;
      newAcc_operand = newAcc_value & 0x7F;

      sc_commandEncode (newAcc_sign, newAcc_command, newAcc_operand,
                        &newAccumulator);
      sc_accumulatorSet (newAccumulator);
      break;

    default:
      break;
    }

  return 0;
}