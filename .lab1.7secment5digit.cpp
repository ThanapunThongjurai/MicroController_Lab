#include<Arduino.h>

#define d0Pin 0
#define d1Pin 1
#define d2Pin 2
#define d3Pin 3
#define d4Pin 4
#define sw0Pin 5
#define sw1Pin 6

// Global variables
byte count;
int delaytime = 450;
int steptime = 0;

// Variables will change:
int ledState = HIGH;       // the current state of the output pin
int buttonState;           // the current reading from the input pin
int lastButtonState = LOW; // the previous reading from the input pin

unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 10;   // the debounce time; increase if the output flickers

void setup()
{
    // put your setup code here, to run once:
    pinMode(d0Pin, OUTPUT);
    pinMode(d1Pin, OUTPUT);
    pinMode(d2Pin, OUTPUT);
    pinMode(d3Pin, OUTPUT);
    pinMode(d4Pin, OUTPUT);
    pinMode(sw0Pin, INPUT);
    pinMode(sw1Pin, INPUT);
    count = 32;
}

void loop()
{
    //!debouced
    int reading = digitalRead(sw1Pin);
    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (reading != buttonState)
        {
            buttonState = reading;
            if (buttonState == HIGH)
            {
                ledState = !ledState;
                steptime++;
            }
        }
    }
    lastButtonState = reading;

    if (steptime > 2)
    {
        steptime = 0;
    }

    if (steptime == 0)
    {
        delaytime = 650;
    }
    else if (steptime == 1)
    {
        delaytime = 250;
    }
    else if (steptime == 2)
    {
        delaytime = 450;
    }

    if (digitalRead(sw0Pin) == 1)
    { //digitalRead(sw0Pin) == HIGH
        digitalWrite(d0Pin, bitRead(count, 0));
        digitalWrite(d1Pin, bitRead(count, 1));
        digitalWrite(d2Pin, bitRead(count, 2));
        digitalWrite(d3Pin, bitRead(count, 3));
        digitalWrite(d4Pin, bitRead(count, 4));
        delay(delaytime);
        count--;
    }
}
