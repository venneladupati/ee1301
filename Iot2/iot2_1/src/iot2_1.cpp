/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/venne/OneDrive/Documents/GitHub/ee1301/Iot2/iot2_1/src/iot2_1.ino"
/*
 * Project iot2_2
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
int setModeFromString(String inputString);
#line 8 "c:/Users/venne/OneDrive/Documents/GitHub/ee1301/Iot2/iot2_1/src/iot2_1.ino"
int tempPIN = A0;
double tempC = 0.0;
int mode;

void setup() {
  pinMode(tempPIN,INPUT);
  Serial.begin(9600);
  Particle.variable("temp", tempC);
  Particle.function("cF_setMode", setModeFromString);
}

void loop() {
  int ADCreading = analogRead(tempPIN);
  tempC = (ADCreading - 620) * 0.0806;
  Serial.print(ADCreading);
  Serial.print(", ");
   Serial.print(tempC);
  Serial.println(" degC");
  //Serial.printf("%4d, %6.3f degC\n",ADCreading,tempC);
  delay(500);
}

int setModeFromString(String inputString) {
  
}