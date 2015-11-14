#include "RASBase.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/linesensor.h>

static tLineSensor *ls;
static tBoolean initialized = false;

enum DIRECTION {
    RIGHT,
    STRAIGHT,
    LEFT
};

void initI2CLineSensor(void) {
    tI2C *bus;
    
    // don't initialize this if we've already done so
    if (initialized) {
        return;
    } 
    
    initialized = true;

    // initialize an I2C bus with a couple of pins
    bus = InitializeI2C(PIN_B3, PIN_B2);
    
    // intialize a line sensor to be on the I2C bus at address 0
    ls = InitializeI2CLineSensor(bus, 0);
}

int sensedoselines(void) {
     
    // loop as long as the user doesn't press a key 
    int i;
    // turn tells whether to continue forward, turn left, or turn right 
    int turn;
    float line[8];

    // put the values of the line sensor into the 'line' array 
    LineSensorReadArray(ls, line);
    Printf("Line Sensor: [");

    for (i = 0; i < 8; i++) {
        Printf("%01.4f ", line[i]);
    }

    Printf("\b]        \r");
  
    Printf("\n");
    
    // Cases
    // Straight
    if (line[2] >= 0.5 && line[3] >= 0.75 && line[4] >= 0.75 && line[5] >= 0.5) {
        turn = STRAIGHT;
    }
    // Right
    else if (line[5] >= 0.6 && line[6] >= 0.75 && line[7] >= 0.6) {
        turn = RIGHT;
    }
    // Left
    else if (line[0] >= 0.6 && line[1] >= 0.75 && line[2] >= 0.6) {
        turn = LEFT;
    }
    return turn;
}

