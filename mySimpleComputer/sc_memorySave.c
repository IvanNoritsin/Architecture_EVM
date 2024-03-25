#include "mySimpleComputer.h"

int
sc_memorySave (char *filename)
{
  if (filename == NULL)
    {
      return -1;
    }

  FILE *writeFile = fopen (filename, "wb");
  if (writeFile == NULL)
    {
      return -1;
    }

  fwrite (memory, 128, sizeof (memory), writeFile);
  fclose (filename);
  return 0;
}