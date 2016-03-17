import com.pi4j.io.i2c.I2CBus;
// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// M24512
// This code is designed to work with the M24512_I2CMEM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/I2C-Memory?sku=M24512_I2CMEM#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;
import java.util.Scanner;

public class M24512
{
	public static void main(String args[]) throws Exception
	{
		// Create I2CBus
		I2CBus bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, M24512 I2C address is 0x50(80)
		I2CDevice device = bus.getDevice(0x50);

		// Select write register
		// data = 0x30(48)
		byte[] address = new byte[3];
		address[0] = 0x00;
		address[1] = 0x00;
		address[2] = 0x30;
		device.write(address, 0, 3);
		Thread.sleep(500);
		device.write(address, 0, 2);

		// Read 1 byte of data
		byte data = (byte)device.read();
		System.out.printf("Input Data : %d %n", data);
	}
}
