#ifndef MY_BIG_CHARS_H
#define MY_BIG_CHARS_H

#include "myTerm.h"
#include <stdio.h>

#define ACS_CKBOARD "a"
#define ACS_ULCORNER "l"
#define ACS_URCORNER "k"
#define ACS_LLCORNER "m"
#define ACS_LRCORNER "j"
#define ACS_HLINE "q"
#define ACS_VLINE "x"

int bc_strlen (char *str);
int bc_printA (char *str);
int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);
int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_printbigchar (int big[2], int x, int y, enum colors fg, enum colors bg);
int bc_bigcharwrite (int fd, int big[][2], int count);
int bc_bigcharread (int fd, int big[][2], int need_count, int *count);

#endif