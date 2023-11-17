/*
 * Project iot2_3A
 * Description:
 * Author:
 * Date:
 */

#include "Particle.h"
#include "neopixel.h"

int PIXEL_PIN = D4;
int PIXEL_COUNT = 3;
int PIXEL_TYPE = WS2812;
// int PIXEL_TYPE = WS2812;
// WS2812 NOTE: use WS2812 if you have them

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  strip.begin();

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  /* NOTE: Two versions of the color code are specified below for WS2811 and 
             WS2812 neopixels. Use the version according to the type of neopixels in 
             your kit and delete or comment the other version. */
    //Setup some colors, WS2811 version
    /*int PixelColorCyan = strip.Color(  0 , 255, 255);
    int PixelColorRed  = strip.Color(  255,   0,   0);
    int PixelColorGold = strip.Color(  60,  50,   5);
    *///Setup some colors, WS2812 version
    
    for (int temp=0;temp<251;temp+=50) {
    int PixelColorCyan = strip.Color(   0 , 0, temp);
    int PixelColorRed  = strip.Color(  0,   temp,   0);
    int PixelColorGold = strip.Color(  temp,  0,   0);
    //Set first pixel to cyan
    strip.setPixelColor(0, PixelColorRed);
    //set second pixel to red
    strip.setPixelColor(1, PixelColorGold);
    //set third pixel to Gopher Gold!
    strip.setPixelColor(2, PixelColorCyan);
    strip.show();
    delay(1000);  //wait 1sec
    }

    //flip the red and gold
    /* strip.setPixelColor(0, PixelColorCyan);
    strip.setPixelColor(1, PixelColorGold);
    strip.setPixelColor(2, PixelColorRed); */
    //strip.show(); 
    //delay(1000);  //wait 1sec
}
