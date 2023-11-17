/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/venne/OneDrive/Documents/GitHub/ee1301/Iot2/iot2_5/src/iot2_5.ino"
/// EE1301
// iot lab2 microproject
// Vennela Dupati
// dupat003

// this code involves a particle photon with a button and led setup
// this code is intended to enable the led to turn on if and only if the button is pressed and held down.
// otherwise, the led turns off.

void setup();
void loop();
#line 10 "c:/Users/venne/OneDrive/Documents/GitHub/ee1301/Iot2/iot2_5/src/iot2_5.ino"
STARTUP(WiFi.selectAntenna(ANT_AUTO)); 

// declaring variables
int ButtonPIN = D2;
bool ButtonOut = FALSE;
int led1 = D0; 

void setup() {

    // setting inputs and outputs
    pinMode(ButtonPIN, INPUT_PULLDOWN);
    pinMode(led1, OUTPUT);

}

void loop() {

    // buttonOut reads signal from buttonpin
    ButtonOut = digitalRead(ButtonPIN);

    // if button is pressed, led is on
    // otherwise led remains off
    if(ButtonOut == HIGH) {
      digitalWrite(led1, HIGH);
    } 
    else {
      digitalWrite(led1, LOW);
    }

}