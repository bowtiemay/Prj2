#ifndef _ELBOW_H_
#define _ELBOW_H_
#include "main.h"

void chassisSet(int left, int right);

void elbowSet(int speed) {
  motorSet(5, speed);
}

#endif
