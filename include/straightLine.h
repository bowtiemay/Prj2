#ifndef _STRAIGHTLINE_H_
#define _STRAIGHTLINE_H_
#include "main.h"
//#include "math.h"
//#include "homeshoulder.h"
//#include "homeElbow.h"



double determineAngle2(int x, int z, int forearm, int buffBicep){ //forearm/bicep are the lenths of the robot
    printf("determining angle 2");
    double pi = 3.141592653589783238462643383;
    double D = ((x*x)+(z*z)-(forearm*forearm) - (buffBicep*buffBicep))/(2*forearm*buffBicep);
    double ang1 = atan((sqrt(1-D))/D); //elbow relative to shoulder
    double ang2 = atan(x/z)+ atan((forearm*sin(ang1))/(buffBicep+forearm*cos(ang1))); //shoulder relative to ground
    double angle2 = (ang2*180)/pi; // returns radians in degrees
    return angle2;
}

double determineAngle1(int x, int z, int forearm, int buffBicep, int angle2){
  printf("determining angle 1");
  double pi = 3.141592653589783238462643383;
  double D = ((x*x)+(z*z)-(forearm*forearm) - (buffBicep*buffBicep))/(2*forearm*buffBicep);
  double ang1 = atan((sqrt(1-D))/D); //elbow relative to shoulder
  double angle1 = (ang1*180)/pi; //returns radians in degrees
  angle1 = angle1 + angle2; //since ang1 (below elbow) is relative to ang2( relative to base)
  return angle1;

}

int drawLine(double ang1, double ang2, Encoder encoder, Encoder yeet, int xVal){
  printf("drawing line");
  int encoderCount = encoderGet(encoder);
  int yeetCount = encoderGet(yeet);
  int errorShoulder = abs(encoderCount - ang1);
  int errorElbow = abs(yeetCount - ang2);

  while (1==1){
    int encoderCount = encoderGet(encoder);
    int yeetCount = encoderGet(yeet);
    int errorShoulder = abs(encoderCount - ang1);
    int errorElbow = abs(yeetCount - ang2);

      regulateJoint(ang1, encoderCount, ang2, yeetCount);

      if (errorShoulder < 5){
        xVal = xVal+2; //this is the x value going into the determineAngles functions
        return xVal;


      }

  }

}



#endif
