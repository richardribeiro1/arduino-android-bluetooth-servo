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

#define RX 2                                              // Connect the HC-05 TX to Arduino pin 2 RX.
#define TX 3                                              // Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
#define servoPin 6

SoftwareSerial bluetooth(RX, TX);
Servo servo;

char Data[4] = "";
String dataString;
int servoPosition;;

void setup() {
  bluetooth.begin(9600);                                  // Baudrate of the module for this application must be 9600. To config check the examples in GitHub Repo.                       
  servo.attach(servoPin);
  delay(200);
}

void loop() {
  if (bluetooth.available()) {                            // If there is data in buffer
    for (int i = 0; i < 4; i++) {                         // 'For' to build a 4-character string
      Data[i] = bluetooth.read();                         // Reading the bluetooth buffer
      dataString += Data[i];                              // Building a 4-character string
      delay(2);                                           // Tested delay for prevent data loss in 9600
    }
    Serial.println(dataString);

    //To use more axis, use the code bellow for check Data[0] == 'B', 'C' or 'D'
    if (Data[0] == 'A') {                                 // Validation of data integrity
      dataString = dataString.substring(1);               // Substring the int value
      servoPosition = dataString.toInt();                 // Convert String to Int
      if (servoPosition >= 0 && servoPosition <= 180) {   // Second validation of data integrity
        servo.write(servoPosition);
      }
    }
    else if (Data[0] == 'S' && Data[1] == '$') {           // Validation of data integrity
      dataString = dataString.substring(2);                // Substring the int value
      int speed = dataString.toInt();                      // Convert String to Int
      if (speed > 0 && speed <= 25) {                      // Second validation of data integrity
        //do something with speed;
      }
    }
  }
  cleanBuffer();
}


// Clean buffer function
void cleanBuffer() {
  dataString = "";
  servoPosition = 0;
  for (int i = 0; i < 4; i++) {
    Data[i] = ' ';
  }
}
