from machine import Pin, ADC, I2C
import time
from ssd1306 import SSD1306_I2C
from oled import Write, GFX, SSD1306_I2C
from oled.fonts import ubuntu_mono_15, ubuntu_mono_20
import utime

led_onboard = Pin(14, Pin.OUT)

output_pin = Pin(27, Pin.OUT)
input_pin = ADC(Pin(26))

threshold = 33000  # You can adjust this threshold value

WIDTH = 128
HEIGHT = 64
i2c=I2C(0, scl=Pin(1), sda=Pin(0), freq=200000)
oled = SSD1306_I2C(WIDTH,HEIGHT,i2c)
write15 = Write(oled, ubuntu_mono_15)
write20 = Write(oled, ubuntu_mono_20)

led_onboard.value(1)

while True:
    moisture_data = input_pin.read_u16()
    moisture_perc = (1-(moisture_data/65535))*100
    print(input_pin.read_u16())
    
    oled.fill(0)
    write15.text("MOISTURE: " + str(round(moisture_perc, 1)) + "%", 0, 0)
    write15.text("CURRENT:  " + str(moisture_data), 0, 18)
    write15.text("THRESHOLD:" + str(threshold), 0, 36)
    oled.show()

    if moisture_data > threshold:
        print("RUN")
        oled.fill(0)
        write20.text("RUN", 0, 20)
        oled.show()
        output_pin.value(1)
        time.sleep(1)
        oled.fill(0)
        output_pin.value(0)
        print("STOP and BREAK")
        write20.text("STOP", 0, 20)
        oled.show()
        time.sleep(10)
        oled.fill(0)
        write20.text("RUN", 0, 20)
        oled.show()
        time.sleep(1)
        oled.fill(0)
        
    time.sleep(1)
