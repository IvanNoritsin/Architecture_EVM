#include "mySimpleComputer.h"

void
printCache (void)
{
  char buf[150];
  int cacheDataLine, cache_sign, cache_command, cache_operand;
  for (int i = 0; i < CACHE_SIZE; i++)
    {
      if (cache[i].numberLine == 0)
        {
          sprintf (buf,
                   " %d:                                                      "
                   "     ",
                   cache[i].numberLine);
        }
      else
        {
          sprintf (buf,
                   "%d:                                                       "
                   "     ",
                   cache[i].numberLine);
        }
      mt_gotoXY (20 + i, 2);
      mt_printText (buf);
    }

  for (int i = 0; i < CACHE_SIZE; i++)
    {
      if (cache[i].isEmpty == 0)
        {
          for (int j = 0; j < CACHE_LINE_SIZE; j++)
            {
              cacheDataLine = cache[i].dataLine[j];
              sc_commandDecode (cacheDataLine, &cache_sign, &cache_command,
                                &cache_operand);
              if (cache_sign == 0)
                {
                  if (j != 9)
                    {
                      sprintf (buf, "+%02X%02X ", cache_command,
                               cache_operand);
                    }
                  else
                    {
                      sprintf (buf, "+%02X%02X", cache_command, cache_operand);
                    }
                }
              else
                {
                  if (j != 9)
                    {
                      sprintf (buf, "-%02X%02X ", cache_command,
                               cache_operand);
                    }
                  else
                    {
                      sprintf (buf, "-%02X%02X", cache_command, cache_operand);
                    };
                }
              mt_gotoXY (20 + i, 6 + 6 * j);
              mt_printText (buf);
            }
        }
    }
}