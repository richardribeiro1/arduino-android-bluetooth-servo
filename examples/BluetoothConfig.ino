/*
   01.09.2022
   Richard Ribeiro
   This is a simple code to configure your bluetooth module.
   The default baud rate of my bluetooth module is 9600.
   See the datasheet of your bluetooth module for more information.
   See https://github.com/richardribeiro1/arduino-android-bluetooth-servo for more details.
*/

#include <SoftwareSerial.h>

#define RX 2                                           // Connect the HC-05 TX to Arduino pin 2 RX.
#define TX 3                                           // Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
SoftwareSerial bluetooth(RX, TX);

char Byte;
String message = "Select Both NL & CR in Serial Monitor.\n"
                 "Enter AT commands./n"
                 "Commands: \n"
                 "AT - feedback. return: OK \n"
                 "AT+VERSION - returns the firmware version. \n"
                 "AT+STATE - returns the current state \n"
                 "AT+UART=9600,0,0 - set baudrate \n"
                 "AT+PSWD=0000 - set PIN code \n"
                 "AT+NAME=HC-05 - set device name \n"
                 "For other commands check the datasheet\n";


void setup() {
  Serial.begin(9600);
  Serial.println(message);
  bluetooth.begin(9600);                               // Default baud rate: 38400
}
void loop() {
  if (bluetooth.available()) {                         // If there's data in the bluetooth buffer
    Byte = bluetooth.read();                           // Read from bluetooth module
    Serial.write(Byte);                                // Send to Serial Monitor
  }

  if (Serial.available()) {                            // If there's data in the serial buffer
    Byte = Serial.read();                              // Read from Serial Monitor
    bluetooth.write(Byte);                             // Send to bluetooth module
  }
}
