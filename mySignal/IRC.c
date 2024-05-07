#include "myInterface.h"
#include "mySignal.h"

void
signals (void)
{
  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);

  struct itimerval nval;
  nval.it_interval.tv_sec = 0;
  nval.it_interval.tv_usec = 500000;
  nval.it_value.tv_sec = 0;
  nval.it_value.tv_usec = 500000;

  setitimer (ITIMER_REAL, &nval, NULL);
}

void
IRC (int signum)
{
  if (signum == SIGALRM)
    {
      CU ();
      int impulsValue;
      sc_regGet (IMPULS, &impulsValue);
      if (impulsValue == 0)
        {
          if (icounter >= 0 && icounter < 127)
            {
              icounter++;
              currentMC = icounter;
            }
          else if (icounter >= 127)
            {
              icounter = 0;
            }
        }
      if (impulsValue == 1)
        {
          alarm (0);
        }
      interface (font_array);
    }
  else if (signum == SIGUSR1)
    {
      sc_memoryInit ();
      accumulator = 0;
      icounter = 0;
      sc_regSet (OVERFLOW, 0);
      sc_regSet (NULL_DEL, 0);
      sc_regSet (OUT_OF_MEMORY, 0);
      sc_regSet (WRONG_COMMAND, 0);
      sc_regSet (IMPULS, 1);
    }
}