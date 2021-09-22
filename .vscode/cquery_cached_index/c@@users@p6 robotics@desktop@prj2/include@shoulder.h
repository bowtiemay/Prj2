#ifndef _SHOULDER_H_
#define _SHOULDER_H_
#include "main.h"

void chassisSet(int left, int right);

void shoulderSet(int speed) {
  motorSet(4, speed);
}

#endif
