#include "HUSKYLENS.h"          // Library for HuskyLens
#include <smorphi.h>            // Library for Smorphi
#include "SoftwareSerial.h"     // Library for Software Serial
// Structure example to receive data
// Must match the sender structure
Smorphi my_robot;
HUSKYLENS huskylens;
//SoftwareSerial myHuskySerial(26, 27);
//SoftwareSerial myHuskySerial(16, 17);
SoftwareSerial myHuskySerial(19, 18);


// Setting up variables and required flags
//int front_sensor_status ; 
//int right_sensor_status = my_robot.module1_sensor_status(4);
int bottom_right_sensor_status;
//int rear_sensor_status ;
//int left_sensor_status = my_robot.module1_sensor_status(10);
int bottom_left_sensor_status;
//String last_action = "";
//String I_shape_done = "false";
//String O_shape_done = "false";
//String red_color_done = "false";
//String yellow_color_done = "false";
// Husky color_detected status written as variable
int count=0;
int color_signature;
int command_block;

void setup() {
  //Initialize Serial Monitor
  Serial.begin(115200);
  myHuskySerial.begin(9600);                  //Baud rate for HuskyLens communication. Can change from GUI of the HuskyLens
   my_robot.BeginSmorphi();
//  my_robot.BeginSmorphi_single();
  while (!huskylens.begin(myHuskySerial)) {
      Serial.println(F("Begin failed!"));
      delay(100);
  }
//  my_robot.BeginSmorphi_single();
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
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
    int maxSpeed=20;
    int maxAV=40;
      switch (x){
        case 1:
        red_on();
        delay(1500);
        led_off();
//        my_robot.CenterPivotRight(80);
//        delay(5800);
          // while(i<=maxSpeed){
            // my_robot.MoveForward(i++);
//            my_robot.CenterPivotLeft(270);
//            delay(1000);
//            my_robot.MoveForward(50);
//            delay(1500);
          // }
          // i=1;
//          digitalWrite(25, HIGH);
//          digitalWrite(26, LOW);
//          digitalWrite(27, LOW);
//          delay(1000);
//          digitalWrite(25, LOW);
//          digitalWrite(26, LOW);
//          digitalWrite(27, LOW);
          movements();
          break;
        case 2:
        green_on();
        delay(1000);
        led_off();
          // while(i<=maxSpeed){
            // my_robot.MoveBackward(i++);
            // delay(1000);
//            my_robot.CenterPivotLeft(270);
//            delay(1000);
//            my_robot.MoveForward(50);
//            delay(1500);
            

          // }
          // i=1;
//          digitalWrite(25, LOW);
//          digitalWrite(26, HIGH);
//          digitalWrite(27, LOW);
//          delay(1000);
//          digitalWrite(25, LOW);
//          digitalWrite(26, LOW);
//          digitalWrite(27, LOW);
          movements();
          break;
        case 3:
        blue_on();
        delay(1000);
        led_off();
//          my_robot.MoveForward(20);
//          delay(1500);
//          my_robot.CenterPivotRight(80);
//          delay(1300);
//          my_robot.MoveForward(20);
//          delay(2000);
//          my_robot.CenterPivotRight(80);
//          delay(800);
          // while(i<=maxSpeed){
            // my_robot.MoveLeft(i++);
//            if(count ==0){
//              my_robot.stopSmorphi_single();
//              delay(5000);
//              count++;
//            }

//            x=1;
//          white_on();
//          delay(1000);
////          led_off();
//          my_robot.MoveForward(60);
//          delay(600);
//          my_robot.CenterPivotLeft(270);
//          delay(1200);
//          my_robot.MoveForward(60);
//          delay(1000);
//          led_off();
//          movements();
//            my_robot.MoveForward(80);
          // }
          // i=1;
          movements();
          break;
        case 4:
        white_on();
        delay(1000);
        led_off();
            my_robot.CenterPivotLeft(270);
            delay(1600);
            my_robot.MoveForward(50);
            delay(1500);
            my_robot.CenterPivotLeft(270);
            delay(1600);
//          count=0;
          // while(i<=maxSpeed){
//            my_robot.MoveForward(50);
//            delay(1500);
            // my_robot.MoveRight(i++);
          // }
          // i=1;
//          digitalWrite(25, LOW);
//          digitalWrite(26, LOW);
//          digitalWrite(27, HIGH);
//          delay(1000);
//          digitalWrite(25, LOW);
//          digitalWrite(26, LOW);
//          digitalWrite(27, LOW);
//          white_on();
//          delay(1000);
//          my_robot.MoveForward(80);
//          delay(1500);
//          led_off();
//          movements();
          break;
        case 5:
        white_on();
        delay(1000);
        led_off();
            my_robot.MoveForward(50);;
            delay(1600);
            my_robot.MoveForward(50);
            delay(1500);
            my_robot.CenterPivotLeft(270);
            delay(1600);
          movements();
          break;
        case 6:
        white_on();
        delay(1000);
        led_off();
            my_robot.CenterPivotRight(270);
            delay(1600);
            my_robot.MoveForward(50);
            delay(1500);
            my_robot.CenterPivotRight(270);
            delay(1600);
          movements();
          break;
        case 7:
        white_on();
        delay(1000);
        my_robot.CenterPivotRight(270);
        delay(5500);
        
//          digitalWrite(25, LOW);
//          digitalWrite(26, LOW);
//          digitalWrite(27, LOW);
          movements();
//          movements();
          break;
        //default:
        case 8:
        white_on();
        delay(1000);
        led_off();
        my_robot.sm_reset_M1();
        my_robot.sm_reset_M2();
        my_robot.sm_reset_M3();
        my_robot.sm_reset_M4();
        my_robot.stopSmorphi();
        my_robot.I();
          // my_robot.stopSmorphi_single();
//            my_robot.CenterPivotRight(270);
//            delay(1000);
//            my_robot.MoveForward(50);
//            delay(1500);
//          digitalWrite(25, LOW);
//          digitalWrite(26, LOW);
//          digitalWrite(27, HIGH);

//          digitalWrite(25, LOW);
//          digitalWrite(26, LOW);
//          digitalWrite(27, LOW);
          movements();
          break;
        //default:
//        case 9:
////          my_robot.stopSmorphi_single();
//          my_robot.stopSmorphi();
////          digitalWrite(25, HIGH);
////          digitalWrite(26, HIGH);
////          digitalWrite(27, HIGH);
//          white_on();          
//          delay(1000);
////          digitalWrite(25, LOW);
////          digitalWrite(26, LOW);
////          digitalWrite(27, LOW);
//          led_off();
//          my_robot.CenterPivotRight(270);
//          delay(5500);
//          break;
        default:
          movements();
//          1==1;
      }
}

void printResult(HUSKYLENSResult result){
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
