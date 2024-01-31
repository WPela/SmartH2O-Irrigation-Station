from machine import Pin, ADC
import time
import utime

led_onboard = Pin(14, Pin.OUT)
    
output_pin = Pin(27, Pin.OUT)
input_pin = ADC(Pin(26))

AAA = 35000  # You can adjust this threshold value

led_onboard.value(1)

while True:
    print(input_pin.read_u16())
    moisture_data = input_pin.read_u16()

    if moisture_data > AAA:
        output_pin.value(1)
        print("RUNNING")
        time.sleep(1)
        output_pin.value(0)
        print("STOP and BREAK")
        time.sleep(10)
