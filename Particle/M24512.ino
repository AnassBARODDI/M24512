// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// M24512
// This code is designed to work with the M24512_I2CMEM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/I2C-Memory?sku=M24512_I2CMEM#tabs-0-product_tabset-2

#include <application.h>
#include <spark_wiring_i2c.h>

// I2C address of the M24512, 0x50(80)
#define Addr 0x50

int data = 0;
void setup()
{
    // Set variable
    Particle.variable("i2cdevice", "M24512");
    Particle.variable("data", data);
    
    // Initialise I2C communication as MASTER
    Wire.begin();
    // Initialise Serial Communication, set baud rate = 9600
    Serial.begin(9600);
    
    // Start I2C transmission
    Wire.beginTransmission(Addr); 
    // Select write address register
    Wire.write(0x00);
    Wire.write(0x01);
    // Write the data
    Wire.write(0x30);
    // End I2C transmission
    Wire.endTransmission();
    delay(300);
}

void loop() 
{
    // Start I2C transmission
    Wire.beginTransmission(Addr); 
    // Select data register
    Wire.write(0x00);
    Wire.write(0x01);
    // End I2C transmission
    Wire.endTransmission();
    
    // Request 1 byte of data
    Wire.requestFrom(Addr, 1);
    
    // Read 1 byte of data 
    if(Wire.available() == 1)
    {
        data = Wire.read();
    }
    
    // Output data to dashboard
    Particle.publish("Input data : ", String(data));
    delay(1000); 
}

