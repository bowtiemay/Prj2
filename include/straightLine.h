#ifndef _STRAIGHTLINE_H_
#define _STRAIGHTLINE_H_
#include "main.h"
//#include "homeshoulder.h"
//#include "homeElbow.h"



double determineAngles(int x, int z, int forearm, int buffBicep){ //forearm/bicep are the lenths of the robot

    double pi = 3.141592653589783238462643383;
    double D = ((x*x)+(z*z)-(forearm*forearm) - (buffBicep*buffBicep))/(2*forearm*buffBicep);
    double ang1 = atan((sqrt(1-D))/D); //elbow relative to shoulder
    double ang2 = atan(x/z)+ atan((forearm*sin(ang1))/(buffBicep+forearm*cos(ang1))); //shoulder relative to ground
    ang1 = ang1 + ang2; //since ang1 (below elbow) is relative to ang2( relative to base)
    double angle1 = (ang1*180)/pi; //returns radians in degrees
    return angle1;
    double angle2 = (ang2*180)/pi; // returns radians in degrees
    return angle2;
}

int drawLine(double ang1, double ang2, Encoder encoder, Encoder yeet){
  int encoderCount = encoderGet(encoder);
  int yeetCount = encoderGet(yeet);
  int errorShoulder = abs(encoderCount - ang1);
  int errorElbow = abs(yeetCount - ang2);

  while (1==1){
    int encoderCount = encoderGet(encoder);
    int yeetCount = encoderGet(yeet);
    int errorShoulder = abs(encoderCount - ang1);
    int errorElbow = abs(yeetCount - ang2);

      regulateJoint(ang1, encoderCount);
      regulateJoint(ang2, yeetCount);

      if (errorShoulder < 5){
        int x = x+2; //this is the x value going into the determineAngles functions
        return x;


      }

  // int newNumberInt = (int) round(oldNumberDouble)


//   if (encoderCount < ang1) {
//     shoulderSet(30);
//   }
//   else {
//     shoulderSet(-30);
//   }
//   if (yeetCount){
//     elbowSet(30);
//   }
//   else {
//     elbowSet(-30);
//   }
//
// }
// }
//


//given certain x and z values calclulate the determineAngles
//check that arm gets to the given position
//regulate joint at given position
//once arm reaches that position, increase the x value by 1



#endif
