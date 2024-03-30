#ifndef MY_TERM_H
#define MY_TERM_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

#define TERM "/dev/tty"

enum colors
{
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  PURPLE,
  CYAN,
  WHITE,
};

int mt_clrscr ();
int mt_gotoXY (int x, int y);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors color);
int mt_setbgcolor (enum colors color);
int mt_setdefaultcolor ();
int mt_setcursorvisible (int value);
int mt_delline ();

#endif