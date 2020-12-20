#include <Arduino.h>
//Master Arduino Code :
//SPI MASTER (ARDUINO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO
//CIRCUIT DIGEST

#include <SPI.h> //Library for SPI
#include <string.h>
#define LED 7
#define ipbutton 2
int buttonvalue;
int x;
void setup(void)

{
    Serial.begin(9600); //Starts Serial Communication at Baud Rate 115200

    pinMode(ipbutton, INPUT); //Sets pin 2 as input
    pinMode(LED, OUTPUT);     //Sets pin 7 as Output

    SPI.begin();                         //Begins the SPI commnuication
    SPI.setClockDivider(SPI_CLOCK_DIV8); //Sets clock for SPI communication at 8 (16/8=2Mhz)
    digitalWrite(SS, HIGH);              // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

String incomingByte;

void loop(void)
{
    
    char c;
    if (Serial.available() > 0)
    {
        incomingByte = Serial.readString();
        Serial.println(incomingByte);
        digitalWrite(SS, LOW);
        //SPI.transfer(incomingByte,30);incomingByte.c_str()
    }
    digitalWrite(SS, LOW);
    for (const char *p = (const char *)incomingByte.c_str(); c = *p; p++)
    {
        SPI.transfer(c);
        Serial.print(c);
    }
    digitalWrite(SS,HIGH);
    delay(2000);
}