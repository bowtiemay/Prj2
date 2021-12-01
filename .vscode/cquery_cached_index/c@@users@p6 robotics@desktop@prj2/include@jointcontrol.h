#ifndef _JOINTCONTROL_H
#define _JOINTCONTROL_H_
#include "main.h"
#include "elbow.h"
#include "shoulder.h"

void regulateJoint(int stayPositionS, Encoder encoderS, int stayPositionE, Encoder encoderE) {

  printf("keeping the joints at your specified pos");

    int jointPositionS = encoderGet(encoderS);
    int jointPositionE = encoderGet(encoderE);


    if (jointPositionS < stayPositionS) {
      shoulderSet(20);
      printf("joint pos is less than the desired pos");
    }

    else if (jointPositionS > stayPositionS) {
      printf("joint pos is greater than the desired pos");
      shoulderSet(-20);
    }

    else if (jointPositionE > stayPositionE) {
      printf("joint pos is greater than the desired pos");
      elbowSet(-20);
    }

    else if (jointPositionE < stayPositionE) {
      elbowSet(20);
      printf("joint pos is less than the desired pos");
    }
  }



#endif
