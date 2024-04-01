#include "mySimpleComputer.h"
#include "myTerm.h"

void
printAccumulator (void)
{
  int value;
  char buf[50];

  mt_gotoXY (1, 67);
  mt_setfgcolor (RED);
  mt_printText ("Аккумулятор");
  mt_setdefaultcolor ();

  sc_accumulatorGet (&value);
  int sign, command, operand;
  sc_commandDecode (value, &sign, &command, &operand);

  sprintf (buf, "sc: +%02X%02X hex: %X", command, operand, value);
  mt_gotoXY (2, 63);
  mt_printText (buf);
}