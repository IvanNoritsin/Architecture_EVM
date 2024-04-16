#include "mySimpleComputer.h"

void
printCounters (void)
{
  int icounter_get;
  char buf[50];

  sc_icounterGet (&icounter_get);
  sprintf (buf, "IC: %04X", icounter_get);
  mt_gotoXY (5, 74);
  mt_printText (buf);
}