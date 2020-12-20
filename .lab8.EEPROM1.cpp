#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Debounce.h>
unsigned long period = 10;
unsigned long last_time = 0;
String Province[20] = {"Kalasin", "Khon Kaen", "Chaiyaphum", "Nakhon Phanom", "NakhonRatchasima"
                       , "Bueng Kan", "Buriram", "Maha Sarakham", "Mukdahan", "Yasothon", "Roi Et"
                       , "Loei", "Sakon Nakhon", "Surin", "Sisaket", "Nong Khai", "Nong Bua Lamphu"
                       , "Udon Thani", "Ubon Ratchathani", "Amnat Charoen"
                      };
String data[20];
; LiquidCrystal_I2C lcd(0x27, 16, 2);
byte button1 = 7;
byte button2 = 8;
bool flag, flag1;
int count = 0;
Debounce Button1(button1);
Debounce Button2(button2);
void setup() {
  Serial.begin(19200);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  lcd.begin();
  lcd.backlight();
  for (byte i = 0; i <= 19; i++) {
    int k = i * 6 ;
    EEPROM.put(k, Province[i]);
  }
  for (byte i = 0; i <= 19; i++) {
    int k = i * 6 ;
    String p;
    EEPROM.get(k, p);
    data[i] = p;
  }
  Display(count);
}
void loop () {

  if (Button2.read() == 0 && flag == false) {
    flag = true;
    count++;
    if (count >= 18)count = 18;
    Display(count);
  } else if (Button2.read() == 1) {
    flag = false;
  }
  if (Button1.read() == 0 && flag1 == false) {
    flag1 = true;
    count--;
    if (count == -1)count = 0;
    Display(count);
  } else if (Button1.read() == 1) {
    flag1 = false;
  }
/*  Serial.print(Button2.read());
  Serial.print(" ");
  Serial.print(Button1.read());
  Serial.print(" ");
  Serial.println(count);*/
}
void Display(int count) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(data[count]);
  lcd.setCursor(0, 1);
  lcd.print(data[count + 1]);
}
