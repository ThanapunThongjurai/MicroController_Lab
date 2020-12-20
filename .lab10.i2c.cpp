#include <Arduino.h>
/*
 * Test TWI/I2C with PCF8574
 * 8-bit I/O Expender
 */
#include <Wire.h>

// Address PCF8574AP
//byte ADDRESS_PCF8574 = 0B0111000 | 0B000;    // address = 0x38
//byte ADDRESS_PCF8574 = 0B0111000 | 0B001;  // address = 0x39

// Address PCF8574T
  
//byte ADDRESS_PCF8574 = 0B0100000 | 0B001;  // address = 0x21

void setup() {
  Wire.begin();
  //Wire.setClock(100000);
  //Serial.begin(9600);
}

void busWrite(byte addr,byte io){
  Wire.beginTransmission(addr);   // begin transmission and set address
  Wire.write(io);                 // send data io
  Wire.endTransmission();         // end transmission
}

byte busRead(byte addr){
  byte io = 0x00;
  Wire.requestFrom(addr, 1);   // request data from address
  if (Wire.available()) {
    io = Wire.read();          // read data io
  }
  return io;
}

void loop() {
  byte io = busRead(ADDRESS_PCF8574);
  //Serial.println(io, BIN);
  //delay(500);
  if (io&0B10000000) {
    busWrite(ADDRESS_PCF8574,0B00000010);
    delay(500);
    busWrite(ADDRESS_PCF8574,0B11111101);
    delay(500);
  }
}
