/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "shoulder.h"
#include "claw.h"
#include "elbow.h"
#include "wrist.h"
#include "homeshoulder.h"
#include "homeElbow.h"
#include "jointcontrol.h"
#include "math.h"


 void operatorControl() {

   Encoder encoder;
   Encoder yeet;

   int counts;
   int counts2;

   int power;
   int turn;
   int shoulderPower;
   int pot = 0;

   int xVal = 2;
   int zVal = 20; //constant

   bool is_reversed = true;
   encoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, is_reversed);
   yeet = encoderInit(QUAD_TOP_PORTT, QUAD_BOTTOM_PORTT, is_reversed);

   // encoderReset(encoder);
   // encoderReset(yeet);

   // printf("Hello %d", (counts));
   // printf("Hello %d", (counts2));

   while (1) {
      printf("the encoder value %d \n", encoderGet(yeet));
      printf("the encoder that supposedly works %d \n", encoderGet(encoder));
      delay(1000);

      if (joystickGetDigital(1, 8, JOY_LEFT) == 1) {
        homeShoulder(190, encoder);
        homeElbow(80, yeet);
      }

      if(joystickGetDigital(1, 8, JOY_RIGHT)== 1){

        determineAngles(xVal, zVal, forearm, bicep); //stays constant
        drawLine(*determineAngles(), encoder, yeet;

      }
       power = joystickGetAnalog(1, 1); // vertical axis on left joystick
       turn  = joystickGetAnalog(1, 2); // horizontal axis on right joystick
       motorSet(3, power + turn); // set left wheels
       motorSet(2, power - turn); // set right wheels


       if(joystickGetDigital(1, 8, JOY_UP) == 1) {
         clawSet(127); // pressing up, so lift should go up
       }
       else if(joystickGetDigital(1, 8, JOY_DOWN) == 1) {
         clawSet(-127); // pressing down, so lift should go down
       }
       else {
         clawSet(0);
       }

       // SHOULDER CONTROL

      if(joystickGetDigital(1, 7, JOY_UP) == 1) {
        shoulderSet(127); // pressing up, so lift should go up
      }
      else if(joystickGetDigital(1, 7, JOY_DOWN) == 1) {
        shoulderSet(-127); // pressing down, so lift should go down
      }

      else {
        shoulderSet(0);
      }

      // ELBOW CONTROL

      if(joystickGetDigital(1, 6, JOY_UP) == 1) {
        elbowSet(127); // pressing up, so lift should go up
      }
      else if(joystickGetDigital(1, 6, JOY_DOWN) == 1) {
        elbowSet(-127); // pressing down, so lift should go down

      }
      else {
        elbowSet(0);
      }

      // WRIST CONTROL

      if(joystickGetDigital(1, 5, JOY_UP) == 1) {
        wristSet(127); // pressing up, so lift should go up
      }
      else if(joystickGetDigital(1, 5, JOY_DOWN) == 1) {
        wristSet(-127); // pressing down, so lift should go down
      }
      else {
        wristSet(0);
      }

      counts = encoderGet(encoder);
      counts2 = encoderGet(yeet);
      pot = analogRead(5);
      // printf("the pot value %d \n", pot);
      //printf("the encoder value %d \n", counts);
    //  printf("the encoder value %d \n", encoderGet(yeet));


int angleNew = determineAngles(x,y l1 and l2)
    drawLine(*determineAngles(), encoder, yeet  )//the astrisk UNPACKS what is returned.
      delay(1000);

    }
}
