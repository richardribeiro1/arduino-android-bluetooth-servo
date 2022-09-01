<h1 align="center">
  <img src="https://user-images.githubusercontent.com/65542005/187566565-5d6df353-c9e5-4401-8713-d37f56f58836.png" alt="orange-box-app" width="50px">
  <br>
  Orange Box
</h1>

<p align="center">
Control your 4-axis robotic arm through Bluetooth
</p>

# Arduino Android Bluetooth Servo
This repository is a sample of how to use Android Orange Box application to control a 4-axis robotic arm using Arduino through Bluetooth commands.
With the Orange Box you can easilly command a 4-axis robotic arm, controlling the movement speed and sending 4 commands to you microcontroller.

## Components
- Arduino UNO
- HC-05 Bluetooth Module 
- Micro-servo motor

## Tutorial
1. Build the eletronic circuit.
<div align="center">
<img src="https://user-images.githubusercontent.com/65542005/187976370-e414fffe-040b-4535-91a6-142f2f65fcef.png" width="450px">
</div>

2. Use the example code for Arduino. 
- Configure your bluetooth module to 9600 baudrate. Use the datasheet and the ConfigBluetooth.ino example.

3. Download the Orange Box app on Google Play.

4. It's <strong> important</strong> you have paired your bluetooth device with your smartphone. The app only shows a list with already paired devices.
It's <strong>important</strong> you give the necessary permissions to your app.

5. Click in button "Paired Devices" to show the list of paired devices in app and click to connect to your bluetooth module. 

6. Once connected, you can control your servos, speed, send commands, dimmer LEDs and other.

<div align="center">
<video src="https://user-images.githubusercontent.com/65542005/187903210-35363d1e-ced0-4628-b4e8-f874c80e61e0.mp4" autoplay>
</div>

7. Feel free to use and adapt the command strings to your use. For example to dimmer a LED.

## Youtube Video Tutorial

## PDF with command strings and data pattern:
[Orange Box - String and Data Pattern - v1.0.pdf](https://github.com/richardribeiro1/arduino-android-bluetooth-servo/files/9469507/Orange.Box.-.String.and.Data.Pattern.-.v1.0.pdf)

## References
- https://www.arduino.cc/reference/en/libraries/servo/
- https://docs.arduino.cc/learn/built-in-libraries/software-serial
- https://datasheetspdf.com/pdf-file/1418730/ITead/HC-05/1
