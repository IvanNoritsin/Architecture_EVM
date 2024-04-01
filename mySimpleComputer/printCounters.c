#include "mySimpleComputer.h"

void
printCounters (void)
{
  int icounter_get;
  char buf[50];

  mt_gotoXY (4, 65);
  mt_setfgcolor (RED);
  mt_printText ("Счётчик  команд");
  mt_setdefaultcolor ();

  sc_icounterGet (&icounter_get);
  sprintf (buf, "IC: %04X", icounter_get);
  mt_gotoXY (5, 72);
  mt_printText (buf);
}