#ifndef _WRIST_H_
#define _WRIST_H_
#include "main.h"

void chassisSet(int left, int right) {};

void wristSet(int speed) {
  motorSet(6, speed);
}

#endif
