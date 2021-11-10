#ifndef _JOINTCONTROL_H
#define _JOINTCONTROL_H_
#include "main.h"
//#include "elbow.h"
//#include "shoulder.h"

void regulateJoint(int stayPosition, Encoder encoder) {

  printf("keeping the elbow joint at ur specified position lololol");

  int jointPosition = encoderGet(encoder);

  while (jointPosition > stayPosition) {
    printf("joint pos is greater than the desired pos");
    shoulderSet(-10);
  }

  while (jointPosition < stayPosition) {
    shoulderSet(10);
    printf("joint pos is less than the desired pos");
  }
}


#endif
