/****************************************
* This code works on Arduino UNO.       *
* Drives a DC Motor on both directions. *
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
* "button_front" and "button_back" used     *
* to send the signal to the board (Arduino) *
* and depending of the "button" configure   *
* the polarity (direction).                 *
*********************************************/
const int enable = 11;
const int logical_1 = 2;
const int logical_2 = 3;
const int button_front = 5;
const int button_back = 6;



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
    pinMode(button_front, INPUT);
    pinMode(button_back, INPUT);
    digitalWrite(enable, LOW);
  }


//loop
/***************************************************
* In the "loop" we declare two variables "front"   *
* and "back". These two variables get the value    *
* of the buttons (when they are pressed or not).   *
* Two "if" statements helps us to activate, change *
* the polarity and also deactivate the motor.      *
****************************************************/

  void loop(){
    int front = digitalRead(button_front);
    int back = digitalRead(button_back);
    
    if(front == HIGH){
      analogWrite(enable, 255);
      digitalWrite(logical_1, HIGH);
      digitalWrite(logical_2, LOW);
    } else if((front == LOW) &&(back == LOW)) {
      digitalWrite(enable, LOW);
    }
  
    if(back == HIGH){
      analogWrite(enable, 255);
      digitalWrite(logical_1, LOW);
      digitalWrite(logical_2, HIGH);
    }else if((front == LOW) &&(back == LOW)){
      digitalWrite(enable, LOW);
    }
  }
