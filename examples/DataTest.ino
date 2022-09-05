/*
   05.09.2022
   Richard Ribeiro
   Sample to use with Android Orange Box App to test the data consistency.
   The default baud rate is 9600 for bluetooth module.
   See https://github.com/richardribeiro1/arduino-android-bluetooth-servo for more details.
*/

//Libraries
#include <SoftwareSerial.h>

#define RX 2                                           // Connect the HC-05 TX to Arduino pin 2 RX.
#define TX 3                                           // Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.

SoftwareSerial bluetooth(RX, TX);

char Data[4] = "";
String dataString;
int out0, out1, out2, out3;

void setup() {
  Serial.begin(9600);                                   // Debug purposes
  bluetooth.begin(9600);                                // Tested baudrate 9600
  delay(200);                                           // Voltage stabilize
}

void loop() {
  if (bluetooth.available()) {
    for (int i = 0; i < 4; i++) {                       // For to build a 4-character string
      Data[i] = bluetooth.read();                       // Reading the bluetooth buffer
      dataString += Data[i];                            // Building a 4-character string
      delay(2);                                         // Tested delay to prevent data loss in 9600
    }

    if (Data[0] == 'A') {                               // Validation of data integrity
      dataString = dataString.substring(1);             // Substring the int value
      out0 = dataString.toInt();                        // Convert String to Int
      if (out0 >= 0 && out0 <= 180) {                   // Second validation of data integrity
        out0 = map(out0, 0, 180, 0, 255);               // Mapping the value to a 8-bit output (0-255);
      }
    }
    if (Data[0] == 'B') {                               // Validation of data integrity
      dataString = dataString.substring(1);             // Substring the int value
      out1 = dataString.toInt();                        // Convert String to Int
      if (out1 >= 0 && out1 <= 180) {                   // Second validation of data integrity
        out1 = map(out1, 0, 180, 0, 255);               // Mapping the value to a 8-bit output (0-255);
      }
    }
    if (Data[0] == 'C') {                               // Validation of data integrity
      dataString = dataString.substring(1);             // Substring the int value
      out2 = dataString.toInt();                        // Convert String to Int
      if (out2 >= 0 && out2 <= 180) {                   // Second validation of data integrity
        out2 = map(out2, 0, 180, 0, 255);               // Mapping the value to a 8-bit output (0-255);
      }
    }
    if (Data[0] == 'D') {                               // Validation of data integrity
      dataString = dataString.substring(1);             // Substring the int value
      out3 = dataString.toInt();                        // Convert String to Int
      if (out3 >= 0 && out3 <= 180) {                   // Second validation of data integrity
        out3 = map(out3, 0, 180, 0, 255);               // Mapping the value to a 8-bit output (0-255);
      }
    }

    // Debug purposes. Check the data transmission through Serial plotter
    Serial.print(out0);
    Serial.print(" , ");
    Serial.print(out1);
    Serial.print(" , ");
    Serial.print(out2);
    Serial.print(" , ");
    Serial.println(out3);

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
