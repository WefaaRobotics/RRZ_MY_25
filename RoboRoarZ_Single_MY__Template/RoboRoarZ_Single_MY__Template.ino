// DO NOT DELETE / COMMENT THESE LINES !!!!

#include "HUSKYLENS.h"          // Library for HuskyLens
#include <smorphi_single.h>            // Library for Smorphi
#include "SoftwareSerial.h"     // Library for Software Serial
// Structure example to receive data
// Must match the sender structure
Smorphi_single my_robot;
HUSKYLENS huskylens;
//SoftwareSerial myHuskySerial(26, 27);
SoftwareSerial myHuskySerial(16, 17);

// DO NOT DELETE / COMMENT THESE LINES !!!!

// Setting up variables and required flags

 
int bottom_right_sensor_status;
int bottom_left_sensor_status;
// Husky color_detected status written as variable

int color_signature;
int command_block;

void setup() {
  //Initialize Serial Monitor
  Serial.begin(115200);
  myHuskySerial.begin(9600);                  //Baud rate for HuskyLens communication. Can change from GUI of the HuskyLens
  my_robot.BeginSmorphi_single();
  while (!huskylens.begin(myHuskySerial)) {
      Serial.println(F("Begin failed!"));
      delay(100);
  }
  my_robot.BeginSmorphi_single();
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  
// DO NOT DELETE / COMMENT THESE LINES !!!!
 
  red_on();
  delay(1000);
  led_off();
  green_on();
  delay(1000);
  led_off();
  blue_on();
  delay(1000);
  led_off();
  white_on();
  delay(1000);
  led_off();
  
}

void loop() {

  // DO NOT DELETE / COMMENT THESE LINES !!!!
  
    sensor_initialisation();
    int x = 0;
    if (huskylens.request()) {
      if (huskylens.available())  {
            // HUSKYLENSResult result = huskylens.read();
            // Serial.println(F("###########"));
            HUSKYLENSResult result = huskylens.read();
            printResult(result);
            if (result.command == COMMAND_RETURN_BLOCK) {
              x=result.ID;
            }
      }
  }else{
    Serial.println("Error!");
  }
    int i=1;
      switch (x){
        case 1:
          //Insert your code here for TagID1
          break;
        case 2:
          //Insert your code here for TagID2
          break;
        case 3:
          //Insert your code here for TagID3
          break;
        case 4:
          //Insert your code here for TagID4
          break;
        case 5:
          //Insert your code here for TagID5
          break;
        case 6:
          //Insert your code here for TagID6
          break;
        case 7:
          //Insert your code here for TagID7
          break;
        case 8:
          //Insert your code here for TagID8
          break;
        case 9:
          //Insert your code here for TagID9
          break;
        default:
          //Insert your code here for default action when no QR Tag is detected;
          1==1;  //DUMMY COMMAND (CAN IGNORE)
      }
}

void printResult(HUSKYLENSResult result){

  // DO NOT DELETE / COMMENT THESE LINES !!!!

  
    if (result.command == COMMAND_RETURN_BLOCK){
        // Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
        Serial.println(result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
      Serial.println("Wrong mode");
        // Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }
    else{
        Serial.println("Object unknown!");
    }
}

void red_on(){
  digitalWrite(25, HIGH);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
}



void green_on(){
  digitalWrite(25, LOW);
  digitalWrite(26, HIGH);
  digitalWrite(27, LOW);
}



void blue_on(){
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, HIGH);
}



void white_on(){
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
}

void led_off(){
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
}
