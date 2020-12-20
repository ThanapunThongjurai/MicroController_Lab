#include <Arduino.h>

#define R 9
#define G 10
#define B 11
typedef struct RGB_color
{
    String name;
    byte Rparameter;
    byte Gparameter;
    byte Bparameter;
} Color;

Color myColor[16];

void setColor(int i, String name, unsigned long color)
{
    myColor[i].name = name;
    myColor[i].Rparameter = color >> 16;
    myColor[i].Gparameter = color >> 8 & 0xFF;
    myColor[i].Bparameter = color & 0xFF;
}

void setup()
{
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    Serial.begin(9600);
    setColor(0, "White", 0xFFFFFF);
    setColor(1, "Silver", 0xC0C0C0);
    setColor(2, "Gray", 0x808080);
    setColor(3, "Black", 0x000000);
    setColor(4, "Red", 0xFF0000);
    setColor(5, "Maroon", 0x800000);
    setColor(6, "Yellow", 0xFFFF00);
    setColor(7, "Olive", 0x808000);
    setColor(8, "Lime", 0x00FF00);
    setColor(9, "Green", 0x008000);
    setColor(10, "Aqua", 0x00FFFF);
    setColor(11, "Teal", 0x008080);
    setColor(12, "Blue", 0x0000FF);
    setColor(13, "Navy", 0x000080);
    setColor(14, "Fuchsia", 0xFF00FF);
    setColor(15, "Purple", 0x800080);
}
//strlen
void loop()
{
    for (int i = 0; i < 15; i++)
    {
        // PWM
        analogWrite(R, myColor[i].Rparameter);
        analogWrite(G, myColor[i].Gparameter);
        analogWrite(B, myColor[i].Bparameter);
        // Serial
        Serial.print(i + 1);
        Serial.print(". ");
        Serial.print(myColor[i].name);
        Serial.print("  R=");
        Serial.print((int)((myColor[i].Rparameter / 255.0) * 100));
        Serial.print("%  G=");
        Serial.print((int)((myColor[i].Gparameter / 255.0) * 100));
        Serial.print("%  B=");
        Serial.print((int)((myColor[i].Bparameter / 255.0) * 100));
        Serial.println("%");
        delay(2000);
    }
}
