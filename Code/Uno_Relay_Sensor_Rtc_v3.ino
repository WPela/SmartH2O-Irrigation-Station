//AIS - Initial version

#include "RTClib.h"
#include <Wire.h>

RTC_DS3231 RTC;

int relayPin = 8;    // Relay Pin
int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
const int AirValue = 550; 
const int WaterValue = 10;  

void setup()        
{ 
  Serial.begin(9600);                 
  Wire.begin();
  RTC.begin();
  pinMode(relayPin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  pinMode(13, OUTPUT);
}

void loop()
{
 DateTime now = RTC.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

 output_value= analogRead(sensor_pin);
 Serial.print(output_value);
 Serial.print(' ');
 output_value = map(output_value,AirValue,WaterValue,0,100);
 Serial.print("Mositure : ");
 Serial.print(output_value);
 Serial.println("%");

if(now.hour() < 9){ //night break
  digitalWrite(relayPin, LOW);
  Serial.print("Night   ");
}
else
{
 if(output_value>48){
  digitalWrite(relayPin, LOW);
 }
 else
 {
  digitalWrite(relayPin, HIGH);
  Serial.print("Powering water pump");
  delay(1000);
  digitalWrite(relayPin, LOW);
  delay(5000);
  digitalWrite(relayPin, HIGH);
  Serial.print("Powering water pump...");
  delay(1000);
  digitalWrite(relayPin, LOW);
  delay(5000);         
 }
}
delay(1000);
}
