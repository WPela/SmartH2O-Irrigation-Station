//AIS - Initial version

#include "RTClib.h"
#include <Wire.h>

RTC_DS3231 RTC;

int relayPin = 8;    // Relay Pin
int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
const int AirValue = 662; //output value when sensor in the air
const int WaterValue = 282;  //output value when sensor in the water

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
 Serial.print("  ");
 output_value = map(output_value,AirValue,WaterValue,0,100);
 Serial.print("Mositure : ");
 Serial.print(output_value);
 Serial.println("%");

if(now.hour() > 20 && now.hour() <= 9){ //night break
digitalWrite(relayPin, LOW);
digitalWrite(13,LOW);
 if(output_value>45){
  digitalWrite(relayPin, LOW);
 }
 else
 {
  digitalWrite(13, HIGH);
  digitalWrite(relayPin, HIGH);
  Serial.print("Powering water pump");
  delay(2000);
  digitalWrite(relayPin, LOW);
  delay(30000);         
 }
 delay(1000);
}
}
