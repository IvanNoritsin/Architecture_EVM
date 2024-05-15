#include "mySimpleComputer.h"

void
printCounters (void)
{
  int icounter_get;
  char buf[50];

  sc_icounterGet (&icounter_get);
  sprintf (buf, "T: %02d       IC: %04X  ", tcounter, icounter_get);
  mt_gotoXY (5, 63);
  mt_printText (buf);
  mt_gotoXY (27, 1);
}