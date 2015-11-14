#include "RASBase.h"


#include <RASLib/inc/servo.h>
#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/time.h>

static tMotor *Motors[2];

enum{
    RIGHT,
    STRAIGHT,
    LEFT
};

void initMotors(void) {
      // Left
      Motors[0] = InitializeServoMotor(PIN_B6, false);
      // Right  
      Motors[1] = InitializeServoMotor(PIN_B7, true); 
} 

// Culture died in the 70's
// with Forrest Dump
// this method will take in two values from the IRSensors
// and the line sensor and decide what to do with the
// tires from there
void runforrestrun(int ir, int line) {
    // Cases:
    // Line and no wall
    // Wall and no line
    // No line and no wall
    
    // IRead returns a distance
    // Depending on the distance, the motors
    // will curve a hard-coded amount of time (2.5 seconds)

    // Right
    if ((ir == RIGHT) || (line == RIGHT)) {
       SetMotor(Motors[0],0.4f);
       SetMotor(Motors[1],0.1f);       
    }
    // Straight
    else if ((ir == STRAIGHT) || (line == STRAIGHT)) {
       SetMotor(Motors[0],0.4f);
       SetMotor(Motors[1],0.4f);
    }
    // Left
    else if ((ir == LEFT) || (line == LEFT)) {
       SetMotor(Motors[0],0.1f);
       SetMotor(Motors[1],0.4f);
    }    
}
