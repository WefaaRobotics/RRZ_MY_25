#include "HUSKYLENS.h" 
#include <smorphi_single.h>
#include "SoftwareSerial.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

HUSKYLENS huskylens;
SoftwareSerial myHuskySerial(19, 18);


BLECharacteristic *pCharacteristic; // Pointer to the BLE characteristic for notifications
bool deviceConnected = false;       // Flag to track BLE connection status
float txValue = 1;                  // Variable to store the value to be sent
String rxString;                    // Global variable to store the received String
Smorphi_single my_robot;                   // Smorphi object




#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif




#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

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


void handleBLEData(String data_received) 
{

    // ------------------- Forward Commands -------------------
    if (data_received == "[") 
    {
        my_robot.MoveForward(100);
        Serial.println("Executed Command: FWD fast");
        data_received = "";
    }
    else if (data_received == "A") 
    {
        my_robot.MoveForward(75);
        data_received = "";
        Serial.println("Executed Command: FWD midfast");
    }
    else if (data_received == "]") 
    {
        my_robot.MoveForward(50);
        data_received = "";
        Serial.println("Executed Command: FWD midslow");
    }
    else if (data_received == "^") 
    {
        my_robot.MoveForward(25);
        data_received = "";
        Serial.println("Executed Command: FWD slow");
    }

    // ------------------- Backward Commands -------------------
    else if (data_received == "_") 
    {
        my_robot.MoveBackward(100);
        data_received = "";
        Serial.println("Executed Command: BWD fast");
    }
    else if (data_received == "`") 
    {
        my_robot.MoveBackward(75);
        data_received = "";
        Serial.println("Executed Command: BWD midfast");
    }
    else if (data_received == "a") 
    {
        my_robot.MoveBackward(50);
        data_received = "";
        Serial.println("Executed Command: BWD midslow");
    }
    else if (data_received == "b") 
    {
        my_robot.MoveBackward(25);
        data_received = "";
        Serial.println("Executed Command: BWD slow");
    }

    // ------------------- Left Commands -------------------
    else if (data_received == "c") 
    {
        my_robot.MoveLeft(100);
        data_received = "";
        Serial.println("Executed Command: LEFT fast");
    }
    else if (data_received == "d") 
    {
        my_robot.MoveLeft(75);
        data_received = "";
        Serial.println("Executed Command: LEFT midfast");
    }
    else if (data_received == "e") 
    {
        my_robot.MoveLeft(50);
        data_received = "";
        Serial.println("Executed Command: LEFT midslow");
    }
    else if (data_received == "f") 
    { 
        my_robot.MoveLeft(25);
        data_received = "";
        Serial.println("Executed Command: LEFT slow");
    }

    // ------------------- Right Commands -------------------
    else if (data_received == "g") 
    {
        my_robot.MoveRight(100);
        data_received = "";
        Serial.println("Executed Command: RIGHT fast");
    }
    else if (data_received == "h") 
    {
        my_robot.MoveRight(75);
        data_received = "";
        Serial.println("Executed Command: RIGHT midfast");
    }
    else if (data_received == "i") 
    {
        my_robot.MoveRight(50);
        data_received = "";
        Serial.println("Executed Command: RIGHT midslow");
    }
    else if (data_received == "j") 
    {
        my_robot.MoveRight(25);
        data_received = "";
        Serial.println("Executed Command: RIGHT slow");
    }

    // ------------------- Up-Left Commands -------------------
    else if (data_received == "k") 
    {
        my_robot.MoveDiagUpLeft(100);
        data_received = "";
        Serial.println("Executed Command: UPLEFT fast");
    }
    else if (data_received == "l") 
    {
        my_robot.MoveDiagUpLeft(75);
        data_received = "";
        Serial.println("Executed Command: UPLEFT midfast");
    }
    else if (data_received == "m") 
    {
        my_robot.MoveDiagUpLeft(50);
        data_received = "";
        Serial.println("Executed Command: UPLEFT midslow");
    }
    else if (data_received == "n") 
    {
        my_robot.MoveDiagUpLeft(25);
        data_received = "";
        Serial.println("Executed Command: UPLEFT slow");
    }

    // ------------------- Up-Right Commands -------------------
    else if (data_received == "o") 
    {
        my_robot.MoveDiagUpRight(100);
        data_received = "";
        Serial.println("Executed Command: UPRIGHT fast");
    }
    else if (data_received == "p") 
    {
        my_robot.MoveDiagUpRight(75);
        data_received = "";
        Serial.println("Executed Command: UPRIGHT midfast");
    }
    else if (data_received == "q") 
    {
        my_robot.MoveDiagUpRight(50);
        data_received = "";
        Serial.println("Executed Command: UPRIGHT midslow");
    }
    else if (data_received == "r") 
    {
        my_robot.MoveDiagUpRight(25);
        data_received = "";
        Serial.println("Executed Command: UPRIGHT slow");
    }

    // ------------------- Down-Left Commands -------------------
    else if (data_received == "s") 
    {
        my_robot.MoveDiagDownLeft(100);
        data_received = "";
        Serial.println("Executed Command: DOWNLEFT fast");
    }
    else if (data_received == "t") 
    {
        my_robot.MoveDiagDownLeft(75);
        data_received = "";
        Serial.println("Executed Command: DOWNLEFT midfast");
    }
    else if (data_received == "u") 
    {
        my_robot.MoveDiagDownLeft(50);
        data_received = "";
        Serial.println("Executed Command: DOWNLEFT midslow");
    }
    else if (data_received == "v") 
    {
        my_robot.MoveDiagDownLeft(25);
        data_received = "";
        Serial.println("Executed Command: DOWNLEFT slow");
    }

    // ------------------- Down-Right Commands -------------------
    else if (data_received == "w") 
    {
        my_robot.MoveDiagDownRight(100);
        data_received = "";
        Serial.println("Executed Command: DOWNRIGHT fast");
    }
    else if (data_received == "x") 
    {
        my_robot.MoveDiagDownRight(75);
        data_received = "";
        Serial.println("Executed Command: DOWNRIGHT midfast");
    }
    else if (data_received == "y") 
    {
        my_robot.MoveDiagDownRight(50);
        data_received = "";
        Serial.println("Executed Command: DOWNRIGHT midslow");
    }
    else if (data_received == "z") 
    {
        my_robot.MoveDiagDownRight(25);
        data_received = "";
        Serial.println("Executed Command: DOWNRIGHT slow");
    }

    // ------------------- Pivot Commands -------------------
    else if (data_received == "{")
    {
        my_robot.CenterPivotLeft(270);
        data_received = "";
        Serial.println("Executed Command: PIVOT LEFT");
    }
    else if (data_received == "|")
    {
        my_robot.CenterPivotRight(270);
        data_received = "";
        Serial.println("Executed Command: PIVOT RIGHT");
    }

    // ------------------- Stop Command -------------------
    else if (data_received == "}") 
    {
        my_robot.stopSmorphi_single();
        Serial.println("Executed Command: STOP");
        data_received = "";
    }


    my_robot.sm_reset_M1();


}




class MyServerCallbacks : public BLEServerCallbacks 
{

    void onConnect(BLEServer *pServer) 
    {
        deviceConnected = true;
    };

    void onDisconnect(BLEServer *pServer) 
    {
        deviceConnected = false;
    }

};




class MyCallbacks : public BLECharacteristicCallbacks 
{

    void onWrite(BLECharacteristic *pCharacteristic) 
    {

        std::string rxValue = pCharacteristic->getValue();
        rxString = String(rxValue.c_str());

        if (rxValue.length() > 0) 
        {
            Serial.println("________________________________");
            Serial.print("Received Data: ");
            Serial.println(rxString);
            handleBLEData(rxString);
            Serial.println("________________________________");
        }

    }

};




void setup() 
{

    Serial.begin(115200); 
    myHuskySerial.begin(9600);                  //Baud rate for HuskyLens communication. Can change from GUI of the HuskyLens
    my_robot.BeginSmorphi_single();
    while (!huskylens.begin(myHuskySerial)) {
        Serial.println(F("Begin failed!"));
        delay(100);
    }
    pinMode(25,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(27,OUTPUT);
    Wire.begin();   
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

    BLEDevice::init("Smorphi Single BLE"); 
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    BLEService *pService = pServer->createService(SERVICE_UUID);

    pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
    pCharacteristic->addDescriptor(new BLE2902());

    BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
    pCharacteristic->setCallbacks(new MyCallbacks());

    pService->start();
    pServer->getAdvertising()->start();

    Serial.println("Waiting for a client connection to notify...");
    

}




/*
void i2c()
{
    byte error, address; //variable for error and I2C address
    int nDevices;

    Serial.println("Scanning...");

    nDevices = 0;
    for (address = 1; address < 127; address++ )
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
        Serial.print("I2C device found at address 0x");
        if (address < 16)
            Serial.print("0");
        Serial.print(address, HEX);
        Serial.println("  !");
        nDevices++;
        }
        else if (error == 4)
        {
        Serial.print("Unknown error at address 0x");
        if (address < 16)
            Serial.print("0");
        Serial.println(address, HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
        Serial.println("done\n");

    delay(500); // wait 5 seconds for the next I2C scan
}
*/
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



void loop() 
{
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
        red_on();
        delay(500);
        led_off();
        break;
      case 2:
        //Insert your code here for TagID2
        green_on();
        delay(500);
        led_off();
        break;
      case 3:
        //Insert your code here for TagID3
        blue_on();
        delay(500);
        led_off();
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

    // For Debugging Purposes

    //  i2c();
    //  Serial.print(my_robot.sm_feedback(1));
    //  Serial.print(my_robot.sm_feedback(2));
    //  Serial.print(my_robot.sm_feedback(3));
    //  Serial.print(my_robot.sm_feedback(4));
    //  Serial.print(my_robot.sm_feedback(5));
    //  Serial.println(my_robot.sm_feedback(6));
    //  delay(10);

    //   my_robot.sm_reset_M1();
    //   my_robot.sm_reset_M2();
    //   my_robot.sm_reset_M3();
    //   my_robot.sm_reset_M4();
    //   delay(20);

}
