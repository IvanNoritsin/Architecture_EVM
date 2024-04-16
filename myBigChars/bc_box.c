#include "myBigChars.h"

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  int row, col;
  mt_getscreensize (&row, &col);
  if ((x1 <= 0) || (y1 <= 0) || (x1 >= row) || (y1 >= col))
    {
      return -1;
    }

  mt_setfgcolor (box_fg);
  mt_setbgcolor (box_bg);
  mt_gotoXY (x1, y1);
  bc_printA (ACS_ULCORNER);
  mt_gotoXY (x1 + x2 + 1, y1);
  bc_printA (ACS_LLCORNER);
  mt_gotoXY (x1 + x2 + 1, y1 + y2 + 1);
  bc_printA (ACS_LRCORNER);
  mt_gotoXY (x1, y1 + y2 + 1);
  bc_printA (ACS_URCORNER);

  for (int i = 1; i < x2 + 1; ++i)
    {
      mt_gotoXY (x1 + i, y1);
      bc_printA (ACS_VLINE);
      mt_gotoXY (x1 + i, y1 + y2 + 1);
      bc_printA (ACS_VLINE);
    }

  for (int i = 1; i < y2 + 1; ++i)
    {
      mt_gotoXY (x1, y1 + i);
      bc_printA (ACS_HLINE);
      mt_gotoXY (x1 + x2 + 1, y1 + i);
      bc_printA (ACS_HLINE);
    }
  mt_setdefaultcolor ();
  int len;

  if (bc_strlen (header) != 0)
    {
      len = bc_strlen (header);
      int shift = y1 - 1;
      int center = (y2 / 2) - (len / 2) + shift + 2;
      mt_gotoXY (x1, center);
      mt_setfgcolor (header_fg);
      mt_setbgcolor (header_bg);
      mt_printText (header);
      mt_setdefaultcolor ();
    }

  return 0;
}