#ifndef _HOMESHOULDER_H
#define _HOMESHOULDER_H_
#include "main.h"
#include "shoulder.h"

void homeShoulder(int homePosition, Encoder encoder) {
  delay(5);
  printf("homing started, stand by \n");

  while (digitalRead(LIMIT_SWITCH) == false) {  // while limit switch is not pressed
    shoulderSet(-50);
    printf("looking for limit switch");
  }

  //once the encoder is pressed, reset it
  encoderReset(encoder);

  //while the encoder position is less than the home position, move the shoulder towards th home position
  while (encoderGet(encoder) < homePosition) {
    shoulderSet(50);
    printf("moving to home position");
  }

  encoderReset(encoder);

  printf("homing complete \n");

  delay(10);
}


#endif
