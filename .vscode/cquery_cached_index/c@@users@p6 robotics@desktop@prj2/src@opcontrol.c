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

#define LINESENSORVALUE1 1
#define LINESENSORVALUE2 2
#define LINESENSORVALUE3 3

 void operatorControl() {

   Encoder encoder;
   Encoder yeet;
   Ultrasonic sonar1;
   Ultrasonic sonar2;

   int counts;
   int counts2;

   int power;
   int turn;
   int shoulderPower;
   int pot = 0;

   int beep;

   bool is_reversed = true;
   encoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, is_reversed);
   yeet = encoderInit(QUAD_TOP_PORTT, QUAD_BOTTOM_PORTT, is_reversed);

   sonar1 = ultrasonicInit(1, 2);

   // encoderReset(encoder);
   // encoderReset(yeet);

   // printf("Hello %d", (counts));
   // printf("Hello %d", (counts2));
   int jointPositionE;
   int jointPositionS;

   int stayPositionS;
   int stayPositionE;
   int lock = encoderGet(encoder);



   while (1) {

      // jointPositionS = encoderGet(encoder);
      // jointPositionE = encoderGet(yeet);

      //HOMING

      printf("the encoder value %d \n", encoderGet(yeet));
      printf("the encoder that supposedly works %d \n", encoderGet(encoder));
      delay(100);

      if (joystickGetDigital(1, 8,  JOY_LEFT) == 1) {
        // homeShoulder(330, encoder);
        // homeElbow(210, yeet

        if (ultrasonicGet(sonar1) > 10 || ultrasonicGet(sonar1) == -1) { // if distance to sensor is less than 20
            motorSet(2, 50);
            motorSet(3, -50);
          }
          else if (ultrasonicGet(sonar1) < 5) {
            motorSet(2, -50);
            motorSet(3, 50);
          }
          else {
            motorSet(2, 0);
            motorSet(3, 0);
          }
      }

      //STAYING AT ONE POSITION

      if (joystickGetDigital(1, 6, JOY_UP) == 1) {
        lock = encoderGet(encoder);
        shoulderSet(127);
      }
      else if (joystickGetDigital(1, 6, JOY_DOWN) == 1) {
        lock = encoderGet(encoder);
        shoulderSet(-127);
      }
      else {
        shoulderSet( -2*(encoderGet(encoder) - lock));
      }

      //LINE FOLLOWING

      beep = analogRead(LINESENSORVALUE1);

      printf("line sensor 1 value %d \n", beep);
      delay(1000);

      while (joystickGetDigital(1, 7, JOY_RIGHT) == 1) {

        if (analogRead(LINESENSORVALUE1) > 1000) {
          motorSet(3, -50); //move left motor

        //  print("moving the robot a lil to the left");

        }
        else if (analogRead(LINESENSORVALUE3) < 10000) {
          motorSet(2, -50); //movr right motor
        //  print("moving the robot a lil to the right");
        }
        // else if (digitalRead(LINESENSORVALUE2)) {
        // //  print("no line detected");
        // }
        else {// this code sucks!!!!!!!
          motorSet(2, 50);
          motorSet(3, 50);
        }
      }

      //ULTRASONIC SENSOR FOLLOWING






      // if (joystickGetDigital(1, 8, JOY_RIGHT) == 1) {
      //   homeShoulder()
      // }
      // if (joystickGetDigital(1, 8, JOY_RIGHT) == 1) {
      // regulateJoint(560, encoder);
      // }

      // ROBOT MVMT CONTROLLED

       power = joystickGetAnalog(1, 1); // vertical axis on left joystick
       turn  = joystickGetAnalog(1, 2); // horizontal axis on right joystick
       motorSet(3, power + turn); // set left wheels
       motorSet(2, power - turn); // set right wheels

       //CLAW CONTROL

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
      delay(40);
}
}
