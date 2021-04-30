#include <ZACwire.h>

ZACwire<26> roomSensor(306);
const int heaterPin = 33; //Connected to the gate of the SSR
int heaterState = LOW;

void setup() {
  Serial.begin(500000);

  pinMode(heaterPin, OUTPUT);
  
  if (roomSensor.begin() == true) {     //check if a sensor is connected to the pin
    Serial.println("Signal found on 10");
  }

  delay(300);
}

void loop() {

  digitalWrite(heaterPin, heaterState);
  
  float roomInput = roomSensor.getTemp();
  
  if (roomInput == 222) {
    Serial.println("Reading failed on 10");
  }
  
  else if (roomInput == 221) {
    Serial.println("Sensor not connected on 10");
  }
  
  else {
    if (roomInput < 23){
      heaterState = HIGH; //Turns the heater on
    }
    else {
      heaterState = LOW; //Turns the heater off
    }
  }

  Serial.print("Heater state = ");
  Serial.print(heaterState);
  Serial.print("  Room temperature = ");
  Serial.println(roomInput);

  //Should hypothetically come out formatted like this: Heater state = 123  Room temperature = 123
  
  delay(100);
}
