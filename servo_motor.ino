/****************************************
* This code works on Arduino UNO.       *
* Drives a Servo motor.                 *
*****************************************/

//import libraries
/**********************
*Import Servo library *
*and create object    *
***********************/
#include <Servo.h>
Servo steering;
//constant and variables
/*****************************************************
*"control" is the Pin connected to the potentiometer *
*"drive" is the Pin connected to the servo           *
*"leftRight" is the variable that will stores        *
*the values from the potentiometer                   *
******************************************************/
const int control = A0;
const int drive = 3;
int leftRight;

//setup
/*******************************************
* On "setup" we attach the servo on        *
* Pin "drive" to read the signal from the  *
* potentiometer.                            *
********************************************/

  void setup(){
    steering.attach(drive);
  }

//loop
/*************************************************
* In the "loop" we use an if-else statement      *
* to steer our servo motor right and left.       *
* "Map" function helps to adjust the analog      *
* output into 0-140 degrees for the servo angle. *
**************************************************/
  void loop(){
    leftRight = analogRead(control);
    delay(30);
    if(500 <= leftRight && leftRight <= 600){
      leftRight = 70;
      steering.write(leftRight);
    }else{
      leftRight = map(leftRight, 0,1023, 0,140);
      steering.write(leftRight);
    }
  }
