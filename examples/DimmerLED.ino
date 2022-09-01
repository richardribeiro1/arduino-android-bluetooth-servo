/*
   30.08.2022
   Richard Ribeiro
   Sample to use with Android Orange Box App
   The default baud rate is 9600 for bluetooth module.
   See https://github.com/richardribeiro1/arduino-android-bluetooth-servo for more details.
*/

//Libraries
#include <SoftwareSerial.h>
#include <Servo.h>

#define RX 2                                           // Connect the HC-05 TX to Arduino pin 2 RX.
#define TX 3                                           // Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
#define ledPin 11  

SoftwareSerial bluetooth(RX, TX);

char Data[4] = "";
String dataString;
int ledOut;

void setup() {
  Serial.begin(9600);                                   // Debug purposes
  bluetooth.begin(9600);                                // Tested baudrate 9600
  pinMode(ledPin, OUTPUT);                              // Config led pin
  delay(200);                                           // Voltage stabilize
}

void loop() {
  if (bluetooth.available()) {
    for (int i = 0; i < 4; i++) {                       // For to build a 4-character string
      Data[i] = bluetooth.read();                       // Reading the bluetooth buffer
      dataString += Data[i];                            // Building a 4-character string
      delay(2);                                         // Tested delay for prevent data loss in 9600
    }

    if (Data[0] == 'A') {                               // Validation of data integrity
      dataString = dataString.substring(1);             // Substring the int value
      ledOut = dataString.toInt();                      // Convert String to Int
      if ( ledOut >= 0 && ledOut <= 180) {              // Second validation of data integrity
        ledOut = map(ledOut, 0, 180, 0, 255);           // Mapping the value to a 8-bit output (0-255);
        Serial.println(ledOut);                         // Debug purposes
        analogWrite(ledPin, ledOut);
      }
    }
    cleanBuffer();                                      // Clean buffer of variables: Data and dataString;
  }
}


// Clean buffer function
void cleanBuffer() {
  dataString = "";
  for (int i = 0; i < 4; i++) {
    Data[i] = ' ';
  }
}
