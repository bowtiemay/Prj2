#ifndef _CLAW_H_
#define _CLAW_H_
#include "main.h"

void chassisSet(int left, int right);

void clawSet(int speed) {
  motorSet(7, speed);
}

#endif
