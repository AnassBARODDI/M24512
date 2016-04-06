# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# M24512
# This code is designed to work with the M24512_I2CMEM I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/I2C-Memory?sku=M24512_I2CMEM#tabs-0-product_tabset-2

import time
import smbus

# Get I2C bus
bus = smbus.SMBus(1)

# M24512 address, 0x50(80)
# Select write address
#		0x0001(01)
# Select write data
#		0x30(48)
bus.write_i2c_block_data(0x50, 0x00, [0x01 , 0x30])

time.sleep(0.5)

# M24512 address, 0x50(80)
# Select read address
bus.write_i2c_block_data(0x50, 0x00, [0x01])

time.sleep(0.5)

# M24512 address, 0x50(80)
# Read data back
data = bus.read_byte(0x50)

# Output data to screen
print "Input Data : ",data
