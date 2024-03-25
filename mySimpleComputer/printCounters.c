#include "mySimpleComputer.h"

void
printCounters (void)
{
  int icounter_get;

  sc_icounterGet (&icounter_get);

  printf ("T: %02X", icounter_get);
}