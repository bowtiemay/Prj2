#ifndef _HOMESHOULDER_H
#define _HOMESHOULDER_H_
#include "main.h"
#include "shoulder.h"

void regulateJoint(int stayPosition, Encoder encoder) {

  printf("keeping the joint at ur specifide position lololol");

  int jointPosition = encoderGet(encoder);

  if (jointPosition < stayPosition) {
    shoulderSet(10);
  }
  else {
    shoulderSet(-10);
  }

  // while (jointPosition > stayPosition) {
  //   shoulderSet(-10);
  // }

  // if (jointPosition < stayPosition-50) {
  //   shoulderSet(10);
  // }
}


#endif
