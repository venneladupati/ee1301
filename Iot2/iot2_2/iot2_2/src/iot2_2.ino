/*
 * Project iot2_2
 * Description:
 * Author:
 * Date:
 */

#include "Particle.h"
#include "neopixel.h"

int PIXEL_PIN = D4;
int PIXEL_COUNT = 1;
int PIXEL_TYPE = WS2812;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

#define COOL 0
#define OFF  1
#define HEAT 2

int mode = OFF;
int tempPIN = A0;
double tempC = 0.0;

void setup() {
  pinMode(tempPIN,INPUT);
  Serial.begin(9600);
  strip.begin();
  Particle.variable("temp",tempC);
  Particle.function("cF_setMode", setModeFromString);
}

void loop() {
  int ADCreading = analogRead(tempPIN);
  tempC = (ADCreading - 620) * 0.0806;
  Serial.print(ADCreading);
  Serial.print(", ");
   Serial.print(tempC);
  Serial.println(" degC");

    int PixelColorCyan = strip.Color(   255 , 0, 0);
    int PixelColorRed  = strip.Color(  0,   255,   0);
    int PixelColorGold = strip.Color(  0,  0,   255);
    Serial.print(mode);
    if (mode == COOL) {
        strip.setPixelColor(0, PixelColorCyan);
    }
    else if (mode == HEAT ){
        strip.setPixelColor(0, PixelColorRed);
    }
    else {
        strip.setPixelColor(0, PixelColorGold);
    }

  //Serial.printf("%4d, %6.3f degC\n",ADCreading,tempC);
  delay(500);
}

int setModeFromString(String inputString) {
    if (inputString == "Cool") {
        mode = COOL;
        return 0;
    } else if (inputString == "Off" ) {
        mode = OFF;
        return 1;
    } else if (inputString == "Heat") {
        mode = HEAT;
        return 2;
    } else {
        return -1; //If we get here return a Sentinel Value. -1 is common for errors.
    }
}
