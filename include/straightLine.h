#ifndef _STRAIGHTLINE_H_
#define _STRAIGHTLINE_H_
#include "main.h"


double determineAngles(x, z, forearm, buffBicep){

    double pi = 3.141592653589783238462643383;
    double D = ((x*x)+(z*z)-(forearm*forearm) - (buffBicep*buffBicep))/(2*forearm*buffBicep);
    double ang1 = atan((sqrt(1-D))/D);
    double ang2 = atan(x/z)+ atan((forearm*sin(ang1))/(buffBicep+forearm*cos(ang1)));
    return (ang1*180)/pi; //returns radians in degrees
    return (ang2*180)/pi; // returns radians in degrees
}


double drawLine(ang1, ang2){



}







#endif
