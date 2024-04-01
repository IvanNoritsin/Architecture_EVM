#include "mySimpleComputer.h"
#include "myTerm.h"

void
printFlags (void)
{
  int value;
  char reg1[5];
  char reg2[5];
  char reg3[5];
  char reg4[5];
  char reg5[5];

  mt_gotoXY (1, 88);
  mt_setfgcolor (RED);
  mt_printText ("Регистр флагов");
  mt_setdefaultcolor ();

  sc_regGet (0, &value);
  if (value == 0)
    {
      sprintf (reg1, "_ ");
    }
  else
    {
      sprintf (reg1, "P ");
    }

  sc_regGet (1, &value);
  if (value == 0)
    {
      sprintf (reg2, "_ ");
    }
  else
    {
      sprintf (reg2, "0 ");
    }

  sc_regGet (2, &value);
  if (value == 0)
    {
      sprintf (reg3, "_ ");
    }
  else
    {
      sprintf (reg3, "M ");
    }

  sc_regGet (3, &value);
  if (value == 0)
    {
      sprintf (reg4, "_ ");
    }
  else
    {
      sprintf (reg4, "T ");
    }

  sc_regGet (4, &value);
  if (value == 0)
    {
      sprintf (reg5, "_ ");
    }
  else
    {
      sprintf (reg5, "E ");
    }

  mt_gotoXY (2, 90);
  mt_printText (reg1);
  mt_gotoXY (2, 92);
  mt_printText (reg2);
  mt_gotoXY (2, 94);
  mt_printText (reg3);
  mt_gotoXY (2, 96);
  mt_printText (reg4);
  mt_gotoXY (2, 98);
  mt_printText (reg5);
}