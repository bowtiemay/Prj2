#ifndef _STRAIGHTLINE_H_
#define _STRAIGHTLINE_H_
#include "main.h"
//#include "homeshoulder.h"
//#include "homeElbow.h"



double determineAngles(x, z, forearm, buffBicep){ //forearm/bicep are the lenths of the robot

    double pi = 3.141592653589783238462643383;
    double D = ((x*x)+(z*z)-(forearm*forearm) - (buffBicep*buffBicep))/(2*forearm*buffBicep);
    double ang1 = atan((sqrt(1-D))/D); //elbow relative to shoulder
    double ang2 = atan(x/z)+ atan((forearm*sin(ang1))/(buffBicep+forearm*cos(ang1))); //shoulder relative to ground
    ang1 = ang1 + ang2; //since ang1 (below elbow) is relative to ang2( relative to base)
    return (ang1*180)/pi; //returns radians in degrees
    return (ang2*180)/pi; // returns radians in degrees
}


double drawLine(ang1, ang2, encoder, yeet){
  int encoderCount = encoderGet(encoder);
  int yeetCount = endcoderGet(yeet);
  int errorShoulder = abs(encoderCount - ang1);
  int errorElbow = abs(yeetCount - ang2);

  while (1==1){
    int encoderCount = encoderGet(encoder);
    int yeetCount = endcoderGet(yeet);
    int errorShoulder = abs(encoderCount - ang1);
    int errorElbow = abs(yeetCount - ang2);

      regulateJoint(ang1, encoderCount);
      regulateJoint(ang2, yeetCount);

      if (errorShoulder < 5){
        x = x+2;


      }

  }


  if (encoderCount < ang1) {
    shoulderSet(30);
  }
  else {
    shoulderSet(-30);
  }
  if (yeetCount){
    elbowSet(30);
  }
  else {
    elbowSet(-30);
  }

}







#endif
