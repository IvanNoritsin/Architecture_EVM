#include "myBigChars.h"
#include "myInterface.h"
#include "myReadKey.h"
#include "mySignal.h"
#include "mySimpleComputer.h"
#include "myTerm.h"

void interface ();
int keyHandler (enum keys key);

int
main (int argc, char *argv[])
{

  mt_clrscr ();

  if (isatty (0) == 0)
    {
      return -1;
    }

  struct winsize win_size;
  ioctl (STDOUT_FILENO, TIOCGWINSZ, &win_size);
  if (win_size.ws_row < 24 || win_size.ws_col < 101)
    {
      printf ("ОШИБКА! СЛИШКОМ МАЛЕНЬКИЙ РАЗМЕР ОКНА!\n");
      return -1;
    }

  int fd;
  if (argc == 1)
    {
      fd = open ("font.bin", O_RDONLY);
      if (fd == -1)
        {
          printf ("ОШИБКА ОТКРЫТИЯ ФАЙЛА!\n");
          return -1;
        }
    }

  else if (argc == 2)
    {
      fd = open (argv[2], O_RDONLY);
      if (fd == -1)
        {
          printf ("ОШИБКА ОТКРЫТИЯ ФАЙЛА!\n");
          return -1;
        }
    }

  else
    {
      printf ("ОШИБКА! НЕВЕРНО УКАЗАН ПАРАМЕТР КОМАНДНОЙ СТРОКИ!\n");
      return -1;
    }

  int count;

  bc_bigcharread (fd, font_array, 18, &count);

  close (fd);

  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();
  mc_cacheInit ();
  sc_regSet (IMPULS, 1);
  rk_mytermregime (0, 0, 1, 1, 1);

  enum keys key;

  do
    {
      interface (font_array);
      rk_readkey (&key);
      keyHandler (key);
    }
  while (key != ESC_KEY);

  return 0;
}

void
interface (int font_array[][2])
{
  for (int i = 0; i < 128; i++)
    {
      printCell (i, WHITE, BLACK);
    }

  bc_box (1, 1, 13, 59, WHITE, BLACK, " Оперативная память ", RED, BLACK);

  printAccumulator ();
  bc_box (1, 62, 1, 21, WHITE, BLACK, " Аккумулятор ", RED, BLACK);

  printFlags ();
  bc_box (1, 85, 1, 21, WHITE, BLACK, " Регистр флагов ", RED, BLACK);

  int memory_get;
  sc_memoryGet (currentMC, &memory_get);
  printCell (currentMC, BLACK, WHITE);
  printDecodedCommand (memory_get);
  bc_box (16, 1, 1, 59, WHITE, BLACK, " Редактируемая ячейка (формат) ", RED,
          WHITE);

  printCounters ();
  bc_box (4, 62, 1, 21, WHITE, BLACK, " Счётчик команд ", RED, BLACK);

  printCommand ();
  bc_box (4, 85, 1, 21, WHITE, BLACK, " Команда ", RED, BLACK);

  bc_box (7, 62, 10, 44, WHITE, BLACK, " Редактируемая ячейка (увеличено) ",
          RED, WHITE);
  printBigCell (font_array);

  bc_box (19, 66, 5, 9, WHITE, BLACK, " IN--OUT ", GREEN, WHITE);

  bc_box (19, 1, 5, 63, WHITE, BLACK, " Кэш процессора ", GREEN, WHITE);
  printCache ();

  bc_box (19, 77, 5, 29, WHITE, BLACK, " Клавиши ", GREEN, WHITE);
  mt_gotoXY (20, 78);
  mt_printText ("l - load  s - save  i - reset");
  mt_gotoXY (21, 78);
  mt_printText ("r - run   t - step           ");
  mt_gotoXY (22, 78);
  mt_printText ("ESC - выход                  ");
  mt_gotoXY (23, 78);
  mt_printText ("F5 - accumulator             ");
  mt_gotoXY (24, 78);
  mt_printText ("F6 - instruction counter     ");

  mt_gotoXY (27, 1);
}

int
keyHandler (enum keys key)
{
  int impulsValue;
  int ignoreImpuls;
  sc_regGet (IMPULS, &impulsValue);
  if (impulsValue == 1)
    {
      switch (key)
        {
        case UP_KEY:
          if (currentMC <= 7)
            {
              currentMC = 120 + currentMC;
            }
          else if (currentMC == 8 || currentMC == 9)
            {
              currentMC = 110 + currentMC;
            }
          else
            {
              currentMC = currentMC - 10;
            }
          break;

        case DOWN_KEY:
          if (currentMC >= 120)
            {
              currentMC = currentMC - 120;
            }
          else if (currentMC == 118 || currentMC == 119)
            {
              currentMC = currentMC - 110;
            }
          else
            {
              currentMC = currentMC + 10;
            }
          break;

        case LEFT_KEY:
          if (currentMC % 10 == 0 && currentMC != 120)
            {
              currentMC = currentMC + 9;
            }
          else if (currentMC == 120)
            {
              currentMC = currentMC + 7;
            }
          else
            {
              currentMC = currentMC - 1;
            }
          break;

        case RIGHT_KEY:
          if ((currentMC + 1) % 10 == 0)
            {
              currentMC = currentMC - 9;
            }
          else if (currentMC == 127)
            {
              currentMC = currentMC - 7;
            }
          else
            {
              currentMC = currentMC + 1;
            }
          break;

        case L_KEY:
          mt_gotoXY (26, 1);
          mt_printText ("Введите имя файла для загрузки: ");
          rk_mytermregime (1, 0, 0, 1, 1);
          char bufLoad;
          scanf ("%s", &bufLoad);
          sc_memoryLoad (&bufLoad);
          mt_gotoXY (26, 1);
          mt_delline ();
          break;

        case S_KEY:
          mt_gotoXY (26, 1);
          mt_printText ("Введите имя файла для сохранения: ");
          rk_mytermregime (1, 0, 0, 1, 1);
          char bufSave;
          scanf ("%s", &bufSave);
          sc_memorySave (&bufSave);
          mt_gotoXY (26, 1);
          mt_delline ();
          break;

        case F5_KEY:
          mt_gotoXY (2, 68);
          int value_acum;
          if (rk_readvalue (&value_acum, 0) == -1)
            {
              break;
            }
          sc_accumulatorSet (value_acum);
          break;

        case F6_KEY:
          mt_gotoXY (5, 79);
          rk_mytermregime (0, 0, 4, 1, 1);
          int icounter_read = icounter;
          char buf[5];
          int terminal = open (TERM, O_RDWR);
          if (terminal == -1)
            {
              return -1;
            }
          int numRead = read (terminal, buf, sizeof (buf));
          buf[numRead] = '\0';
          sscanf (buf, "%X", &icounter_read);
          if (icounter_read < 0 || icounter_read > 127)
            {
              sc_regSet (OUT_OF_MEMORY, 1);
              icounter = icounter_read;
            }
          else
            {
              sc_regSet (OUT_OF_MEMORY, 0);
              icounter = icounter_read;
            }
          break;

        case ENTER_KEY:
          mt_gotoXY (cursorX, cursorY);
          int value;
          if (rk_readvalue (&value, 0) == -1)
            {
              break;
            }
          sc_memorySet (currentMC, value);
          break;

        case ESC_KEY:
          rk_mytermregime (0, 0, 1, 1, 1);
          break;

        default:
          break;
        }
    }

  switch (key)
    {
    case I_KEY:
      IRC (SIGUSR1);
      currentMC = 0;
      break;

    case R_KEY:
      sc_regGet (IMPULS, &ignoreImpuls);
      if (ignoreImpuls == 1)
        {
          sc_regSet (IMPULS, 0);
          signals ();
          IRC (SIGALRM);
        }
      else
        {
          sc_regSet (IMPULS, 1);
          alarm (0);
        }
      break;

    case T_KEY:
      IRC (SIGALRM);
      sc_icounterGet (&currentMC);
      break;

    default:
      break;
    }

  return 0;
}