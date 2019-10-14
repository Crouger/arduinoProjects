/**************************
 * import libraries*
 *************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/**************************
 * constants and variables*
 *************************/
const int switchPin = A0;
int switchState = 0;
int guess = 0;
int previousGuess = 0;
int reply;
String message;
/**************************
 * setup section*
 *************************/
void setup(){
  //for communication
  Serial.begin(9600); 

  //display configuration: this display is 16 digits with 2 row, so the message in each row cannot be more than 16 digits (incuding the spaces)
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("    Ask  the"); //"spaces" need to center the message
  lcd.setCursor(0,1);
  lcd.print("     Troll");
 }
/**************************
 * loop section*
 *************************/
void loop(){
      //take the signal from the sensor
      switchState = analogRead(switchPin);

      //scale it in bigger range to be easier to divide it
      int meter = map(switchState, 0, 1023, 0, 10000);

      //depending of the light scale the number "9850" higher or lower to calibrate the if statement (how sensitive to be)
  if((meter < 9850)&&(guess == previousGuess)){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" The Troll Says");
      guess++;
  }
      switchState = analogRead(switchPin);
      
      //depending of the light scale the number "9850" higher or lower to calibrate the if statement (how sensitive to be)
  if((meter > 9850)&&(guess != previousGuess)) {
      //this delay is only for display reason (so the message will appear after this (1000ms) time seems to be like thinking)
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" The Troll Says");
      lcd.setCursor(0,1);

       //produce a random number (from 0 to 12)
      reply = random(12);

      //total of 12 cases (number can change, but also the "random number range" placed above must change)
         switch(reply){
            case 0:
            message = "   o Giorgos";
            break;
            case 1:
            message = "   o Lazaros";
            break;
            case 2:
            message = "    Kanenas";
            break;
            case 3:
            message = "mallon o Giorgos";
            break;
            case 4:
            message = "mallon o Lazaros";
            break;
            case 5:
            message = "    kanenas";
            break;
            case 6:
            message = " oxi o Giorgos";
            break;
            case 7:
            message = " oxi o Lazaros";
            break;
            case 8:
            message = "plaka mas kaneis";
            break;
            case 9:
            message = "   kai oi dyo";
            break;
            case 10:
            message = " asto kalitera";
            break;
            case 11:
            message = " oi ginaikes sas";
            break;
          }
      lcd.print(message);

      //this delay will keep the message (for 5000ms) printed in the display from the "switch statement" before return back to the first message
      delay(5000);
      guess = 0;
  }
      switchState = analogRead(switchPin);
      
  if((meter > 9850)&&(guess == previousGuess)){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    Ask  the");
      lcd.setCursor(0,1);
      lcd.print("     Troll");
  }
 //this delay helps to see clearly the message in the display
 delay(100);
}
