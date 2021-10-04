#ifndef _HOMESHOULDER_H
#define _HOMESHOULDER_H_
#include "main.h"
#include "shoulder.h"

void homeShoulder(int homePosition, Encoder encoder) {
  delay(500);
  printf("homing started, stand by \n");

  while (!(homePosition - 100 < encoderGet(encoder) < homePosition + 100)) {

    if (digitalRead(LIMIT_SWITCH) == false) {  // while limit switch is not pressed
      shoulderSet(-50);
      printf("looking for limit switch \n");
      delay(200);
    }
    //once the encoder is pressed, reset it and stop arm mvmt
    else {
      shoulderSet(0);
      encoderReset(encoder);
    }

    //while the encoder position is less than the home position, move the shoulder towards th home position
    if (encoderGet(encoder) < homePosition) {
      shoulderSet(50);
      printf("moving to home  \n");
      delay(200);
    }
    else if (encoderGet(encoder) > homePosition) {
      shoulderSet(-50);
      printf("moving to home  \n");
      delay(200);
    }
  // while (encoderGet(encoder) < homePosition) {
  //   shoulderSet(-50);
  //   printf("moving to home  \n");
  //   delay(200);
  // }

  //encoderReset(encoder);
    delay(10);
  }
  printf("homing complete \n");
}


#endif
