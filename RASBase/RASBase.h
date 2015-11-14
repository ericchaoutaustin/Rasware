// Functions in Motors
void initMotors(void); 
void runforrestrun(int, int);

// Functions in Servos
void initServo(void);
void servos(void);

// Functions in LineSensor
void initI2CLineSensor(void);
int sensedoselines(void);

// Function in IRSensors
void initIRSensor(void);
float IRead(void);

// Functions in Encoders
void initEncoders(void);
void encoders(void);

// Function for UART
void uart(void);

// Functions in Sonar
void initSonar(void);
void sonar(void);

// Function for GPIO
void gpio(void);

// Functions for GPIOLineSensor
void initGPIOLineSensor(void);
void gpioLineSensor(void);
