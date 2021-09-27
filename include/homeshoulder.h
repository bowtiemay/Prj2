#ifndef _HOMESHOULDER_H
#define _HOMESHOULDER_H_
#include "main.h"

void homeShoulder(int homePosition, Encoder encoder) {

  printf("homing started, stand by \n");

  while (LIMIT_SWITCH == 1) {
    shoulderSet(-10);
  }

  encoderReset(encoder);

  while (encoderGet(encoder) < homePosition) {
    shoulderSet(10);
  }

  encoderReset(encoder);

  printf("homing complete \n");
}


#endif
