#include <DHT20.h> //DHT20 by RobTillaart
#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays
#include <Wire.h>

DHT20 DHT;
SSD1306 display(0x3c, 5, 4); //OLED(I2C, SDA, SCL) 1,3:ConnectorA 5,4:ConnectorB

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  //Start Temp-Humidity Sensor
  Wire.begin(33, 32); //Temp(SDA, SCL)1,3:ConnectorA 5,4:ConnectorB 
  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  Serial.print(String(Temperature) + "℃");
  Serial.print(" / ");
  Serial.println(String(Humidity) + "%");
  delay(200);
  float score = (Temperature) * 0.64 + (Humidity) * 0.175;
  Wire.end();
  
  //Start OLED
  Wire.begin(26, 25); //OLED(SDA, SCL)1,3:ConnectorA 5,4:ConnectorB 
  display.init(); //Initialization
  display.setFont(ArialMT_Plain_24); //Set Font
  display.drawString(0, 0, String(Temperature) + "°C"); //1st low
  display.drawString(0, 21, String(Humidity) + "%"); //2nd low

  if( score < 24){

    display.drawString(0, 42, "SAFE");

  }else if ( score >=24 && score < 27){

    display.drawString(0, 42, "GOOD");
    
  }else if ( score >= 27 && score < 30){

    display.drawString(0, 42, "TAKE LEST");

  }else if ( score >= 30) {

    display.drawString(0, 42, "don`t work");

  }

  display.display(); //Draw
  delay(1000);
  Wire.end();
}


