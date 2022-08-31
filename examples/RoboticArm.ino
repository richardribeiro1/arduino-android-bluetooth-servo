/*
   30.08.2022
   Richard Ribeiro
   Sample to use with Android Orange Box App for control a servo in range of 0 to 180.
   Feel free to use and adapt for your application.

   Components
   - Arduino UNO
   - HC-05 Bluetooth Module 
   - Micro-servo motor

   References   
    https://www.arduino.cc/reference/en/libraries/servo/
    https://docs.arduino.cc/learn/built-in-libraries/software-serial
    https://datasheetspdf.com/pdf-file/1418730/ITead/HC-05/1

   GitHub Repo:
    https://github.com/richardribeiro1/arduino-android-bluetooth-servo
*/

#include <SoftwareSerial.h>
#include <Servo.h>

#define RX 2
#define TX 3
#define servoPin 6

SoftwareSerial bluetooth(RX, TX);
Servo servo;

char Data[7] = "";
String dataString, positionString, speedString;
int servoPosition;;

void setup() {
  //for debug purposes
  //Serial.begin(9600); 
  bluetooth.begin(9600);
  servo.attach(servoPin);
  delay(200);
}

void loop() {
  //If there is data in buffer, it will be structured in a 7-character string
  if (bluetooth.available()) {
    for (int i = 0; i < 7; i++) {
      Data[i] = bluetooth.read();
      dataString += Data[i];
      delay(5);
    }

    //for debug purposes
    //Serial.print("Message: "); 
    //Serial.println(dataString);

    //string pattern validation for servo commands
    if (Data[0] == '/' && Data[2] == '$' && Data[6] == '&') {
      //SERVO COMMANDS
      if (Data[1] == 'A') {
        dataString = dataString.substring(3, 6);
        servoPosition = dataString.toInt();

        //validation of position
        if (servoPosition >= 0 && servoPosition <= 180) {          
          servo.write(servoPosition);
          //for debug purposes
          //Serial.print("Message: ");
          //Serial.println(servoPosition);
        }
      }
    }
    clearBuffer();
  }
}

//Clean data
void clearBuffer() {
  dataString = "";
  positionString = "";
  speedString = "";
  servoPosition = 0;
  for (int i = 0; i < 7; i++) {
    Data[i] = ' ';
  }
}
