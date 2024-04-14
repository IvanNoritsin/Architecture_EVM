#include "myBigChars.h"

int
bc_strlen (char *str)
{
  if (str == NULL)
    {
      return 0;
    }

  int length = 0;

  while (*str != '\0')
    {
      unsigned char first_byte = *str;

      if (first_byte < 128)
        {
          length++;
          str++;
        }

      else
        {
          int bytes = 0;
          if ((first_byte & 0xE0) == 0xC0)
            {
              bytes = 2;
            }
          else if ((first_byte & 0xF0) == 0xE0)
            {
              bytes = 3;
            }
          else if ((first_byte & 0xF8) == 0xF0)
            {
              bytes = 4;
            }
          else
            {
              return 0;
            }

          for (int i = 1; i < bytes; i++)
            {
              if ((str[i] & 0xC0) != 0x80)
                {
                  return 0;
                }
            }

          length++;
          str += bytes;
        }
    }

  return length;
}