#include <Arduino.h>
#include <string.h>
const int sensor = A0; 

float tempc; //variable to store temperature in degree Celsius
float tempf; //variable to store temperature in Fahreinheit
float vout; //temporary variable to hold sensor reading

void setup()
{
    pinMode(sensor, INPUT); 
    Serial.begin(9600);
}

void loop()
{
    vout = analogRead(sensor); 
    vout = (vout * 500) / 1023;
    tempc = vout; 
    tempf = (vout * 1.8) + 32; 
    Serial.print("in DegreeC=");
    Serial.print("\t");
    Serial.print(tempc);
    Serial.print(" ");
    Serial.print("in Fahrenheit=");
    Serial.print("\t");
    Serial.print(tempf);
    Serial.println();
    delay(500); 
}