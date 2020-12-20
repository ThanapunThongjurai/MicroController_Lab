#include <Arduino.h>
#include <avr/pgmspace.h> 
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
void setup()
{
  Serial.begin(9600);
}

int list_Control = 0;
void loop()
{
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[list_Control]))); // Necessary casts and dereferencing, just copy.
  Serial.print(list_Control + 1);
  Serial.println(buffer);
  list_Control++;
  delay(2000);
  if (list_Control > 21)
    list_Control = 0;
}