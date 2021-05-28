#include "U8glib.h"

const int tombol = A0;
const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 5;
const int LED4 = 6;
const int LED5 = 7;
int sensorValue = 0;
char *tulisan;

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_profont22);
  u8g.setPrintPos(30, 37); 
  u8g.print(tulisan);
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  
}

void setup () {
  pinMode(tombol, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}
void loop () {
  sensorValue = analogRead(tombol);
  if (sensorValue == 0) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    tulisan = "Lampu 1";
  } else if (sensorValue == 30){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    tulisan = "Lampu 2";
  } else if (sensorValue == 86) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    tulisan = "Lampu 3";
  } else if (sensorValue == 164) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
    tulisan = "Lampu 4";
  } else if (sensorValue == 349) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
    tulisan = "Lampu 5";
  } else if (sensorValue == 1023) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    tulisan = "MATI";
  }
   u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(50);  
}
