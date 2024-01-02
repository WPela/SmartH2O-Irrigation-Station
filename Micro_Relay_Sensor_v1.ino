//AIS Micro - version 1

//Libraries
#include <Wire.h>

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

//Soil moisture sensor reading
 output_value= analogRead(sensor_pin);
 output_value = map(output_value,AirValue,WaterValue,0,100);
 Serial.print("Mositure : ");
 Serial.print(output_value);
 Serial.println("%");

 if(output_value>46){   //trigger value when pump will be turned on
  digitalWrite(relayPin, LOW);
 }
 else
 {
  Serial.print("Powering water pump");  //pump will be turned on for 1,2sec, then 5sec of delay so the soil will absorb and 1sec of watering again
  delay(1000);
  digitalWrite(relayPin, HIGH);
  delay(1200);
  digitalWrite(relayPin, LOW);
  delay(10000);
  digitalWrite(relayPin, HIGH);
  Serial.print("");
  Serial.print("Powering water pump...");
  delay(1200);
  digitalWrite(relayPin, LOW);
  delay(20000);    //additional 20 sec break to absorb water, when sensor reading shows more then trigger value, pump will not be turned on
 }

}
