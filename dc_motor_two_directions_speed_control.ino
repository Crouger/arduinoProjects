/****************************************
* This code works on Arduino UNO.       *
* Drives a DC Motor with speed control  *
* on both directions.                   *
*****************************************/

//import libraries
/******************
*NOTHING TO IMPORT*
*******************/

//constant and variables
/********************************************
* "Enable" used to activate the motor.      *
* "logical_1 and logical_2 used on the      *
* BRIDGE to change the polarity (so the     *
* direction) on the motor.                  *
* "analog" helps to calibrate the speed     *
*********************************************/
const int enable = 11;
const int logical_1 = 7;
const int logical_2 = 8;
const int analog = A0;

//setup
/*******************************************
* On "setup" we declare the Mode of the    *
* PINS we are going to use. Also we have   *
* the "enable" PIN into LOW so when we     *
* first activate our board the motor will  *
* stay off.                                *
********************************************/

  void setup(){
    pinMode(enable, OUTPUT);
    pinMode(logical_1, OUTPUT);
    pinMode(logical_2, OUTPUT);
    digitalWrite(enable, LOW);
  }


//loop
/**********************************************
* In the "loop" we use two if-else statements *
* to drive our motor front and back. "Map"    *
* function helps to adjust the analog output  *
* into 0-255 scale for the PWM signal.        *
***********************************************/
  void loop(){
  int throtle = analogRead(analog);
    if(throtle <= 500){
      int front = 255 - map(analogRead(analog),500,0,255,0);
      analogWrite(enable, front);
      digitalWrite(logical_1, HIGH);
      digitalWrite(logical_2, LOW);
    }else if(throtle >=600){
      int back = map(analogRead(analog),600,1023,0,255);
      analogWrite(enable, back);
      digitalWrite(logical_1, LOW);
      digitalWrite(logical_2, HIGH);
    }else{
      analogWrite(enable, LOW);
    }
  }
