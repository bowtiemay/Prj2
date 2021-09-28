#ifndef _HOMESHOULDER_H
#define _HOMESHOULDER_H_
#include "main.h"
#include "shoulder.h"

void homeShoulder(int homePosition, Encoder encoder) {

  printf("homing started, stand by \n");

  if (joystickGetDigital(1, 7, JOY_UP == 1)) {
    shoulderSet(-50);
    printf("looking for limit switch");
  }

  encoderReset(encoder);

  while (encoderGet(encoder) < homePosition) {
    shoulderSet(50);
    printf("moving to home position");
  }

  encoderReset(encoder);

  printf("homing complete \n");
}


#endif
