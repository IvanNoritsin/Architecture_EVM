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

  fread (memory, 128, sizeof (memory), filename);
  fclose (filename);
  return 0;
}