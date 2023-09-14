#include <Servo.h>

Servo wasteServo;  // define servo name
int soilPin = A0;  // Soil Sensor input pin
int soilValue = 0; // Variable to store soil sensor value
int dryThreshold = 300; // Threshold for dry soil
int wetThreshold = 700; // Threshold for wet soil

void setup() {
  Serial.begin(9600); // open serial port
  wasteServo.attach(9); // servo connected to pin 9
}

void loop() {
  soilValue = analogRead(soilPin); // read soil value
  Serial.println(soilValue); // print the value to serial monitor
  
  if (soilValue < dryThreshold) {
    // Soil is dry, move servo to place in 'Dry Waste' bin
    wasteServo.write(0); // 0 degree
  } 
  else if (soilValue > wetThreshold) {
    // Soil is wet, move servo to place in 'Wet Waste' bin
    wasteServo.write(180); // 180 degree
  }
  else {
    // Soil is neither dry nor wet, keep servo in neutral position
    wasteServo.write(90); // 90 degree
  }
  
  delay(1000); // Wait for 1 second
}
