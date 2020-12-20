#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Debounce.h>
unsigned long period = 10;
unsigned long last_time = 0;
int s = 0, mm = 0, ms = 0;
byte button1 = 7;
byte button2 = 8;
int count = 0;
Debounce Button1(button1);
Debounce Button2(button2);
bool flag;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int MM1, MM2, S1, S2 , MS1, MS2;
void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("<StopWatch>");
  Serial.begin(9600);
}
void loop() {

  Serial.print(Button2.read());
  Serial.print(" ");
  Serial.print(Button1.read());
  Serial.print(" ");
  Serial.print(count);
  Serial.print(" ");
  Serial.print(mm);
  Serial.print(" ");
  Serial.print(s);
  Serial.print(" ");
  Serial.println(ms);
  MM1 = mm / 10;
  MM2 = mm % 10;
  S1 = s / 10;
  S2 = s % 10;
  MS1 = ms / 10;
  MS2 = ms % 10;
   if (Button1.read() == 0 ) {
    mm=0;
    ms=0;;
    s=0;
    count =1;
  } 
  if (Button2.read() == 0 && flag == false) {
    flag = true;
    count++;
  } else if (Button2.read() == 1) {
    flag = false;
  }
  if (count == 2){
    if ( millis() - last_time > period) {
    last_time = millis();
    ms++;
  }
  if (ms == 100) {
    s++;
    ms = 0;
  }
  if (s == 60) {
    mm++;
    s = 0;
  }
  }
  
  if (count > 2){
    count = 1;
  } 
  Display();
}
void Display(void) {
  lcd.setCursor(4, 1);
  lcd.print(MM1);
  lcd.print(MM2);
  lcd.print(":");
  lcd.print(S1);
  lcd.print(S2);
  lcd.print(":");
  lcd.print(MS1);
}
