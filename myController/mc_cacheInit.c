#include "myController.h"

int
mc_cacheInit (void)
{
  for (int i = 0; i < CACHE_SIZE; i++)
    {
      for (int j = 0; j < CACHE_LINE_SIZE; j++)
        {
          cache[i].dataLine[j] = 0;
        }
      cache[i].numberLine = -1;
      cache[i].lastAccess = 0;
      cache[i].isEmpty = 1;
    }
  return 0;
}