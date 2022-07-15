#include "thingProperties.h"
const int pinLED = 8;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  delay(1500); 

  pinMode(pinLED,OUTPUT);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
}

void onLedRojoChange()  {
  // Add your code here to act upon LedRojo change
  led_rojo = !led_rojo;
  Serial.print("Estado de led_rojo: ");
  
  if(led_rojo){
    digitalWrite(pinLED, HIGH);
    Serial.println("ON");
  }else{
    digitalWrite(pinLED, LOW);
    Serial.println("OFF");
  }
}
