#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"

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

  int font_array[18][2];
  int count;

  bc_bigcharread (fd, font_array, 18, &count);

  close (fd);

  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  sc_memorySet (0, 6589);
  sc_memorySet (15, 426);
  sc_memorySet (44, 9862);
  sc_memorySet (72, 13548);
  sc_memorySet (94, 56);
  sc_memorySet (113, 30568);

  for (int i = 0; i < 128; i++)
    {
      printCell (i, WHITE, BLACK);
    }

  bc_box (1, 1, 13, 59, WHITE, BLACK, " Оперативная память ", RED, BLACK);

  sc_accumulatorSet (7861);
  printAccumulator ();
  bc_box (1, 62, 1, 21, WHITE, BLACK, " Аккумулятор ", RED, BLACK);

  sc_regSet (OVERFLOW, 1);
  sc_regSet (IMPULS, 1);
  printFlags ();
  bc_box (1, 85, 1, 21, WHITE, BLACK, " Регистр флагов ", RED, BLACK);

  sc_icounterSet (72);

  int icounter_get;
  int memory_get;

  sc_icounterGet (&icounter_get);
  sc_memoryGet (icounter_get, &memory_get);

  printDecodedCommand (memory_get);
  bc_box (16, 1, 1, 59, WHITE, BLACK, " Редактируемая ячейка (формат) ", RED,
          WHITE);

  printCounters ();
  bc_box (4, 62, 1, 21, WHITE, BLACK, " Счётчик команд ", RED, BLACK);

  printCommand ();
  bc_box (4, 85, 1, 21, WHITE, BLACK, " Команда ", RED, BLACK);

  printTerm (23, 1);
  printTerm (44, 1);
  printTerm (15, 1);
  printTerm (76, 1);
  printTerm (0, 1);
  printTerm (72, 1);
  printTerm (57, 1);

  printBigCell (font_array);

  printBigCell (font_array);

  bc_box (7, 62, 10, 44, WHITE, BLACK, " Редактируемая ячейка (увеличено) ",
          RED, WHITE);
  bc_box (19, 67, 4, 9, WHITE, BLACK, " IN--OUT ", GREEN, WHITE);

  mt_gotoXY (45, 1);

  return 0;
}