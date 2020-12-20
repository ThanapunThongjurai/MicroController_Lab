#include <Arduino.h>
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal EZ(rs, en, d4, d5, d6, d7);

const char string_0[] PROGMEM = "Kalasin"; // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "Khon Kaen";
const char string_2[] PROGMEM = "Chaiyaphum";
const char string_3[] PROGMEM = "Nakhon Phanom";
const char string_4[] PROGMEM = "Nakhon Ratchasima";
const char string_5[] PROGMEM = "Bueng Kan";
const char string_6[] PROGMEM = "Buriram";
const char string_7[] PROGMEM = "Maha Sarakham";
const char string_8[] PROGMEM = "Mukdahan";
const char string_9[] PROGMEM = "Bueng Kan";
const char string_10[] PROGMEM = "Yasothon";
const char string_11[] PROGMEM = "Roi Et";
const char string_12[] PROGMEM = "Loei";
const char string_13[] PROGMEM = "Sakon Nakhon";
const char string_14[] PROGMEM = "Surin";
const char string_15[] PROGMEM = "Sisaket";
const char string_16[] PROGMEM = "Nong Khai";
const char string_17[] PROGMEM = "Nong Bua Lamphu";
const char string_18[] PROGMEM = "Udon Thani";
const char string_19[] PROGMEM = "Ubon Ratchathani";
const char string_20[] PROGMEM = "Amnat Charoen";
const char *const string_table[] PROGMEM = {string_0,
                                            string_1,
                                            string_2,
                                            string_3,
                                            string_4,
                                            string_5,
                                            string_6,
                                            string_7,
                                            string_8,
                                            string_9,
                                            string_10,
                                            string_11,
                                            string_12,
                                            string_13,
                                            string_14,
                                            string_15,
                                            string_16,
                                            string_17,
                                            string_18,
                                            string_19,
                                            string_20};

char buffer[30]; // make sure this is large enough for the largest string it must hold

const int buttonPin_UP = 7;   // the number of the pushbutton pin
const int buttonPin_DOWN = 8; // the number of the pushbutton pin

// Variables will change:
int statusState_UP = LOW;       // the current state of the output pin
int buttonState_UP;             // the current reading from the input pin
int lastButtonState_UP = LOW;   // the previous reading from the input pin
int statusState_DOWN = LOW;     // the current state of the output pin
int buttonState_DOWN;           // the current reading from the input pin
int lastButtonState_DOWN = LOW; // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime_UP = 0;   // the last time the output pin was toggled
unsigned long debounceDelay_UP = 50;    // the debounce time; increase if the output flickers
unsigned long lastDebounceTime_DOWN = 0; // the last time the output pin was toggled
unsigned long debounceDelay_DOWN = 50;  // the debounce time; increase if the output flickers

void setup()
{
  pinMode(buttonPin_UP, INPUT);
  pinMode(buttonPin_DOWN, INPUT);

  EZ.begin(16, 2);

  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB
  Serial.println("OK");

  statusState_UP = HIGH;
}

int list_Control = 0;
void loop()
{
  
  int reading = digitalRead(buttonPin_UP);
  if (reading != lastButtonState_UP)
  {
    lastDebounceTime_UP = millis();
  }

  if ((millis() - lastDebounceTime_UP) > debounceDelay_UP)
  {
    if (reading != buttonState_UP)
    {
      buttonState_UP = reading;
      if (buttonState_UP == HIGH)
      {
        statusState_UP++;
      }
    }
  }
  lastButtonState_UP = reading;

  int reading_DOWN = digitalRead(buttonPin_DOWN);
  if (reading_DOWN != lastButtonState_DOWN)
  {
    lastDebounceTime_DOWN = millis();
  }

  if ((millis() - lastDebounceTime_DOWN) > debounceDelay_DOWN)
  {
    if (reading_DOWN != buttonState_DOWN)
    {
      buttonState_DOWN = reading_DOWN;
      if (buttonState_DOWN == HIGH)
      {
        statusState_DOWN++;
      }
    }
  }
  lastButtonState_DOWN = reading_DOWN;

  if (statusState_UP > 0)
  {
    statusState_UP = 0;
    EZ.clear();
    EZ.setCursor(0, 0);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[list_Control]))); // Necessary casts and dereferencing, just copy.
    Serial.print(list_Control + 1);
    Serial.println(buffer);
    EZ.print(list_Control + 1);
    EZ.print(buffer);

    EZ.setCursor(0, 1);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[list_Control + 1]))); // Necessary casts and dereferencing, just copy.
    Serial.print(list_Control + 1 + 1);
    Serial.println(buffer);
    Serial.println();
    EZ.print(list_Control + 1 + 1);
    EZ.print(buffer);

    list_Control++;
    if (list_Control > 19)
      list_Control = 0;
  }
  if (statusState_DOWN > 0)
  {
    statusState_DOWN = 0;
    EZ.clear();
    EZ.setCursor(0, 0);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[list_Control]))); // Necessary casts and dereferencing, just copy.
    Serial.print(list_Control + 1);
    Serial.println(buffer);
    EZ.print(list_Control + 1);
    EZ.print(buffer);

    EZ.setCursor(0, 1);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[list_Control + 1]))); // Necessary casts and dereferencing, just copy.
    Serial.print(list_Control + 1 + 1);
    Serial.println(buffer);
    Serial.println();
    EZ.print(list_Control + 1 + 1);
    EZ.print(buffer);

    list_Control--;
    if (list_Control < 0)
      list_Control = 19;
  }

  /*
  for (int i = 0; i < 21; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i]))); // Necessary casts and dereferencing, just copy.
    Serial.print(i+1);
    Serial.println(buffer);
    delay(500);
  }
 */
}