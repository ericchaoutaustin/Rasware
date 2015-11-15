#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include "RASBase.h"

// Blink the LED to show we're on
tBoolean blink_on = true;

void blink(void) {
    SetPin(PIN_F2, blink_on);
    SetPin(PIN_F1, blink_on);
    SetPin(PIN_D1, blink_on);
blink_on = !blink_on;
}


// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    initIRSensor();
    initMotors();
    initI2CLineSensor();
    // Maybe we'll need it to blink later
    // CallEvery(blink, 0, 0.5);
    
   // crapcrapcrapcarp
//poooooop 
    float irval = 0;
    int turn = 0;
    // Never stop
    while (1) {
        // Runtime code can go here
        // Read in stuff from the IRSensors
        irval = IRead();
        // Read in stuff from the LineSensor
        turn = 0; // sensedoselines();
        // Use that stuff in the Motor
        runforrestrun(irval, turn);  
    }
}
