#!/usr/bin/env python3
import SmallBasicPIGPIO as gpio

gpio.SCD30_Open()
gpio.SCD30_SetInterval(2) # measurement interval 2s

for ii = 1 to 10

    'check if new data is available
    while(gpio.SCD30_DataAvailable() != 1)
        delay(100)
    wend

    'Read the data. A array with three elements will be returnd.
    'Element 0: CO2 in ppm; Element 1: Temperature in °C; Element 2: Humidity in %RH

    Measurement = gpio.SCD30_ReadData()

    print "CO2: "; round(Measurement(0)); "ppm | T: "; round(Measurement(1),1); "°C | H: "; round(Measurement(2));"%RH"

next

gpio.SCD30_Close()
