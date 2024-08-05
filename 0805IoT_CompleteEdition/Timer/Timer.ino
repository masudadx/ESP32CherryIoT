#include <Wire.h>
#include <SSD1306.h> 
SSD1306 display(0x3c, 26, 25); 
const int swPin = 32;
 
void setup() {

  Serial.begin(115200);
  pinMode(swPin, INPUT);

  display.init(); //Initialization　これで全消し
  display.setFont(ArialMT_Plain_24); 
  display.drawString(8, 0, "BunBun"); 
  display.drawString(5, 21, "Hello"); 
  display.drawString(2, 42, "Youtube"); 
  display.display(); //Draw これがないと表示されない
}
 
void loop() {

  display.init(); //Initialization　これで全消し
  display.setFont(ArialMT_Plain_24); 
  display.drawString(10, 0, "Push to"); 
  display.drawString(24, 21, "count");
  display.drawString(18, 42, "Start!!!!"); 
  display.display(); //Draw これがないと表示されない
  delay(5000);
  int endtime = 10;// 単位はsecond

  if (digitalRead(swPin) == HIGH) {

     for(int i = endtime; i >= 0  ; i-- ){

  display.init();
  display.drawString(4, 0,"Last Time");
  display.drawString(35, 21,String(i));
  display.drawString(13, 42,"Sconds");
  display.display(); //Draw これがないと表示されない
  delay(1000);

  }

  display.init();
  display.drawString(0, 0,"Time");
  display.drawString(10, 21," is");
  display.drawString(0, 42,"OVER!");
  display.display(); //Draw これがないと表示されない
  delay(10000);
   
  } 
 
}



