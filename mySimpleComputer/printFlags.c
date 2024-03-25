#include "mySimpleComputer.h"

void
printFlags (void)
{
  int value;

  sc_regGet (0, &value);
  if (value == 0)
    {
      printf ("_ ");
    }
  else
    {
      printf ("P ");
    }

  sc_regGet (1, &value);
  if (value == 0)
    {
      printf ("_ ");
    }
  else
    {
      printf ("0 ");
    }

  sc_regGet (2, &value);
  if (value == 0)
    {
      printf ("_ ");
    }
  else
    {
      printf ("M ");
    }

  sc_regGet (3, &value);
  if (value == 0)
    {
      printf ("_ ");
    }
  else
    {
      printf ("T ");
    }

  sc_regGet (4, &value);
  if (value == 0)
    {
      printf ("_ ");
    }
  else
    {
      printf ("E ");
    }

  printf ("\n");
}