#include "myBigChars.h"

#define FILE_NAME "font.bin"

int
main ()
{
  int font_big_chars[][2] = {
    { 0x4242427E, 0x7E424242 }, { 0x606C7870, 0x60606060 },
    { 0x60643C18, 0xFF3E1C38 }, { 0x2040221C, 0x1C224038 },
    { 0x24242424, 0x2020203C }, { 0x1C04043C, 0x18242020 },
    { 0x1A022418, 0x18242226 }, { 0x3060407E, 0x204087C },
    { 0x18242418, 0x18242418 }, { 0x24242418, 0x18242038 },
    { 0x3C24243C, 0x24242424 }, { 0xE12221E, 0x1E22120E },
    { 0x2022418, 0x18240202 },  { 0x2424140C, 0xC142424 },
    { 0x7E027E7E, 0x7E7E027E }, { 0x3C047C7C, 0x404043C },
    { 0xFF181818, 0x181818FF }, { 0xFF000000, 0xFF },

  };

  int fd = open (FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd == -1)
    {
      printf ("Ошибка открытия файла!");
      return -1;
    }

  bc_bigcharwrite (fd, font_big_chars, 18);

  close (fd);

  return 0;
}