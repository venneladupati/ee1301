/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// By holding down the button, you temporarily stop the flash and show a constant blue
// light on the D7 LED. However, the way the code is written is not advisable. It stalls
// the loop() function when the button is held down, and if the button is held down for
// too long, it causes a time-out.
// Try it: Hold down the button for about 20 seconds, and you will see that the 
// board loses cloud connectivity and stops breathing cyan.

int led = D7;    // The D7 on-board LED
int button = D3; // This is the input button (use an internal pull-down resistor)
int LedFreqState = 0;   // set to 0 for 0.50 Hz, set to 1 for 0.25 Hz
int prevButton = LOW;   // state variable to store if button was HIGH or LOW last time

// This program will blink the on-board D7 LED at 0.5 Hz. 
// It does not use the delay() function
// Note that there are two state variables -- one to store the next time to toggle
// the LED, and one to store the current LED state (ON/OFF)

// Declaring the state variables as global variables. 
// You could also declare state variables as local static variables inside the loop
// function (preferred).

bool LED_state = FALSE;

// This variable stores the next time to toggle the LED. 
// It will be initialized to 1 second in the future in the first iteration of the loop function
unsigned long int timeToToggleLED;

void setup() {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    timeToToggleLED = millis() + 1000;
}

void loop() {
    unsigned long int currentTime = millis();  // get the current time

    int curButton = digitalRead(button);
    if(curButton == HIGH && prevButton == LOW){
        // a transition happened -- the user has just pressed the button
        Serial.println("Button press detected.");  //Debugging printout
        
        // change the state of the LED blinking rate
        LedFreqState++;
        if(LedFreqState > 2){  // make sure it changes from 0 --> 1 --> 0 --> ...
            LedFreqState = 0;
        }
    }
    
    prevButton = curButton;   // keep track of previous button state for next time
    Serial.print(curButton);  // Debugging printout
    
    if(LedFreqState == 0){  // Rate 0: 0.5 Hz (on 1 sec, off 1 sec)
   // Check if it is time to toggle the LED “Are we there yet? Are we there yet? ..."
    if(currentTime > timeToToggleLED){  
        // Time to Toggle!
        LED_state = !LED_state;
        digitalWrite(led, LED_state);

        // Calculate and store the next time to toggle the LED
        timeToToggleLED += 1000;
    }
    }
    else if (LedFreqState == 1){	              // Rate 1: 0.25Hz (2 secs on, 2 secs off)
    // Check if it is time to toggle the LED “Are we there yet? Are we there yet? ..."
    if(currentTime > timeToToggleLED){  
        // Time to Toggle!
        LED_state = !LED_state;
        digitalWrite(led, LED_state);

        // Calculate and store the next time to toggle the LED
        timeToToggleLED += 2000;
    }
    }
    else if (LedFreqState == 2){	              // Rate 1: 1.0Hz (2 secs on, 2 secs off)
     // Check if it is time to toggle the LED “Are we there yet? Are we there yet? ..."
    if(currentTime > timeToToggleLED){  
        // Time to Toggle!
        LED_state = !LED_state;
        digitalWrite(led, LED_state);

        // Calculate and store the next time to toggle the LED
        timeToToggleLED += 500;
    }
    }

}
