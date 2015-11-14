#include "RASBase.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>

static tADC *adc[2];
static tBoolean initialized = false;

enum{
    RIGHT,
    STRAIGHT,
    LEFT
};

void initIRSensor(void) {
    // don't initialize this if we've already done so
    if (initialized) {
        return;
    }
    
    initialized = true;

    // initialize 2 pins to be used for ADC input
   adc[0] = InitializeADC(PIN_D2); // Left
   adc[1] = InitializeADC(PIN_D3); // Right
}

// Read in the IRSensor values
float IRead(void) {
    float leftIR = ADCRead(adc[0]);
    float rightIR  = ADCRead(adc[1]);
    Printf(
             "IR values:  %1.3f %1.3f\r",
             rightIR, leftIR
             );
    // Obstacle right, curve left
    if (rightIR > 0.6) return LEFT;
    // Obstacle left, curve right
    else if (leftIR > 0.6) return RIGHT;
    // No Obstacles in sight, STRAIGHT
    else return STRAIGHT;
}

