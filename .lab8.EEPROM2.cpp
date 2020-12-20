#include <Arduino.h>
#include <EEPROM.h>
struct provinces {
  char name[35];
  long male[35];
  long female[35];
} data;
char male1[20];
char female1[20];
long m[20];
long f[20];
int i = 0, k = 0, j = 0, l = 0;
String str;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("..............Enter Data..............");

}

void loop() {
  MEM();
}
void MEM() {
  if (i <= 19) {
    if (Serial.available() > 0) {
      str = Serial.readString();
      i++;
      for (int i = 0; i < str.length(); i++) {
        if (str.charAt(i) == '0' || str.charAt(i) == '1' || str.charAt(i) == '2'
            || str.charAt(i) == '3' || str.charAt(i) == '4' || str.charAt(i) == '5'
            || str.charAt(i) == '6' || str.charAt(i) == '7' || str.charAt(i) == '8'
            || str.charAt(i) == '9') {
          str.substring(0, i - 1).toCharArray(data.name, 20);
          Serial.println(data.name);
          break;
        }
        j++;
      }

      for ( l = j; i < str.length(); l++) {
        if (str.charAt(l) == ' ') {
          str.substring(j, l).toCharArray(male1, 20);
          Serial.println(male1);
          break;
        }
      }

      str.substring(l + 1, str.length()).toCharArray(female1, 20);
      Serial.println(female1);
      l = 0; j = 0;
    }
  }
}
