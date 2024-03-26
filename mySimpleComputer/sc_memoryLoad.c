#include "mySimpleComputer.h"

int
sc_memoryLoad (char *filename)
{
  if (filename == NULL)
    {
      return -1;
    }

  FILE *readFIle = fopen (filename, "rb");
  if (readFIle == NULL)
    {
      return -1;
    }

  fread (memory, sizeof (int), 128, readFIle);
  fclose (readFIle);
  return 0;
}