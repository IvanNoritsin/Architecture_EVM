#ifndef MY_READ_KEY_H
#define MY_READ_KEY_H

#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <termios.h>

enum keys
{
  ESC_KEY,
  L_KEY,
  S_KEY,
  I_KEY,
  R_KEY,
  T_KEY,
  F5_KEY,
  F6_KEY,
  UP_KEY,
  DOWN_KEY,
  LEFT_KEY,
  RIGHT_KEY,
  ENTER_KEY,
  UNKNOWN_KEY,
};

int rk_readkey (enum keys *key);
int rk_mytermsave ();
int rk_mytermrestore ();
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readvalue (int *value, int timeout);

#endif