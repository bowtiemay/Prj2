#ifndef _HOMESHOULDER_H
#define _HOMESHOULDER_H_
#include "main.h"
//#include "shoulder.h"
//#include "jointcontrol.h"

void homeShoulder(int homePosition, Encoder encoder) {
  printf("homing started (S), stand by \n");

  while (digitalRead(LIMIT_SWITCH) == true) {  // while limit switch is not pressed
    shoulderSet(-50);
    printf("looking for limit switch S \n");
    delay(20);
  }
    //once the encoder is pressed, reset it and stop arm mvmt
  shoulderSet(0);
  encoderReset(encoder);
  printf("encoder (S) has been reset");

  //while the encoder position is less than the home position, move the shoulder towards th home position
  while (encoderGet(encoder) < homePosition + 10) {
    shoulderSet(50);
    printf("moving to home (S) %d  \n", encoderGet(encoder));
    delay(20);
  }
  shoulderSet(0);
  encoderReset(encoder);

  delay(10);

  printf("homing complete (S) \n");

}


#endif
