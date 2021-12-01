#ifndef _FOLLOWLINE_H
#define _FOLLOWLINE_H_
#include "main.h"

void followLine(int targetDistance, Encoder encoder) {

  int distance = encoderGet(encoder);

  if (targetDistance > distance) {
    printf("distance is less than desired follow distance");
    motorSet(50);
  }

  else if (targetDistance < distance) {
    printf("distance is greater than desired follow distance");
    motorSet(-50)
  }
  else {
   motorSet(0);
  }
}


#endif
