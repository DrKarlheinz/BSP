#!/usr/bin/env python3
from smbus2 import SMBus
bus = SMBus(1)

for addr in range(0x03, 0x77):
    try:
        bus.write_quick(addr)
        print(f"Found device at 0x{addr:02X}")
    except:
        pass
