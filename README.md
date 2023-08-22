# AIS_Arduino
Repository for Automated Irrigation System (AIS)

Repository contains code, schematics, plans and all versions of AIS. It is based on Arduino compatible board, with soil moisture sensor, RTC and water pump controlled by relay.

Link to repository: https://github.com/WPela/AIS_Arduino/tree/master/Code

List of parts:
 - Arduino Uno or compatible
 - Relay switch module (built in transistor and opto-isolator)
 - RTC module (DS3231 with battery)
 - Soil Moisture sensor (Capacitive)
 - Water pump (submersible, 3.3/5V)
 - Jumper wires
 - Power supply (power unit with 5/3.3V output)

Below diagram describes a way of all the connections between Arduino, Relay, RTC and Soil Moisture sensor. Sensor, Relay and RTC are powered with 5V but pump with 3,3V to decrese the flow of the water. 

![AIS_Diagram_v4](https://github.com/WPela/AIS_Arduino/assets/62253932/a57163c5-10df-4ddf-9d44-988934fc067a)<br>
*diagram made in Virtual Breadboard app*

![v4_21082023](https://github.com/WPela/AIS_Arduino/assets/62253932/7e102288-27ee-4a47-b0b2-f91f084e6931)

Photo and diagram as of 21st of August 2023

![Initial_03072023](https://github.com/WPela/AIS_Arduino/assets/62253932/cb6b5179-25cb-451b-88d8-314ccc06cb79)

Photo as of 3rd of July 2023


Please see https://github.com/users/WPela/projects/1 to check current status of the project.
