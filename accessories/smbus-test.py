#!/usr/bin/env python3
import smbus2
bus = smbus2.SMBus(1)
address = 0x68

# Try reading the CHIP_ID register (should return 0xD1 for BMI160)
chip_id = bus.read_byte_data(address, 0x00)
print(f"Chip ID: 0x{chip_id:X}")
