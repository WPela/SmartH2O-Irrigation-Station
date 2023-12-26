//AIS - version 5

//Libraries
#include "RTClib.h"
#include <Wire.h>
RTC_DS3231 RTC;

int relayPin = 8;    // Relay Pin
int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value;
const int AirValue = 550;
const int WaterValue = 10;

//Start setup
void setup()
{ 
  Serial.begin(9600);                 
  Wire.begin();
  RTC.begin();
  pinMode(relayPin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.println("Powering Arduino System...");
  delay(2000);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  pinMode(13, OUTPUT);
}


void loop()
{
 DateTime now = RTC.now();  //Current date

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

//Soil moisture sensor reading
 output_value= analogRead(sensor_pin);
 output_value = map(output_value,AirValue,WaterValue,0,100);
 Serial.print("Mositure : ");
 Serial.print(output_value);
 Serial.println("%");

if(now.hour() < 9){     //night break - pomp will not turn on between noon and 9am
  digitalWrite(relayPin, LOW);
  Serial.print("Night   ");
}
else
{
 if(output_value>47){   //trigger value when pump will be turned on
  digitalWrite(relayPin, LOW);
 }
 else
 {
  Serial.print("Powering water pump");  //pump will be turned on for 1,2sec, then 5sec of delay so the soil will absorb and 1sec of watering again
  delay(1000);
  digitalWrite(relayPin, HIGH);
  delay(1000);
  digitalWrite(relayPin, LOW);
  delay(10000);
  digitalWrite(relayPin, HIGH);
  Serial.print("Powering water pump...");
  delay(1000);
  digitalWrite(relayPin, LOW);
  delay(10000);    //additional 6 sec break to absorb water, when sensor reading shows more then trigger value, pump will not be turned on
 }
}
delay(1000);
}
