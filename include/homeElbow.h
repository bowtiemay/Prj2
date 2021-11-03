#ifndef _HOMEELBOW_H
#define _HOMEELBOW_H_
#include "main.h"
#include "elbow.h"
#include "jointcontrol.h"

void homeElbow(int homePosition, Encoder encoder) {
  printf("elbow homing started, stand by \n");

  while (digitalRead(LIMIT_SWITCHH) == true) {  // while limit switch is not pressed
    elbowSet(-50);
    printf("looking for elbow limit switch \n");
    }
    //once the encoder is pressed, reset it and stop arm mvmt
  elbowSet(0);
  encoderReset(encoder);
  printf("elbow encoder has been reset");

  //while the encoder position is less than the home position, move the shoulder towards th home position
  while (encoderGet(encoder) != homePosition + 10) { // change != to less than
    elbowSet(50);
    printf("moving elbow to home %d  \n", encoderGet(encoder));
  }
  elbowSet(0);
  encoderReset(encoder);

  delay(10);

  printf("elbow homing complete \n");
}


#endif
