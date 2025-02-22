#include <CapacitiveSensor.h>

CapacitiveSensor   cs_6_7 = CapacitiveSensor(6,7);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

// Variables will change:
int buttonReading;
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 10;    // the debounce time; increase if the output flickers

//declare variables for the motor pins
int motorPin1 = 1;  // Blue   - 28BYJ48 pin 1
int motorPin2 = 2;  // Pink   - 28BYJ48 pin 2
int motorPin3 = 3;  // Yellow - 28BYJ48 pin 3
int motorPin4 = 10; // Orange - 28BYJ48 pin 4
                       // Red    - 28BYJ48 pin 5 (VCC)

int motorSpeed = 75;     //variable to set stepper speed

long runTime = 10000;

//////////////////////////////////////////////////////////////////////////////
void setup() {
   cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

//////////////////////////////////////////////////////////////////////////////
int i = 0;
int on = 0;
long total1;

void loop(){
    if (on == 1){
         counterclockwise();                     //go to the ccw rotation function
         
        if ((millis() - lastDebounceTime) > debounceDelay+runTime) {
          on = 0;
        }
    }
    else {    
      total1 =  cs_6_7.capacitiveSensor(30);
  
      if (total1>15){
        buttonReading = 1;
      }
      else {
        buttonReading = 0;
      }
      
    // If the switch changed, due to noise or pressing:
    if (buttonReading != lastButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    } 
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer
      // than the debounce delay, so take it as the actual current state:
  
      // if the button state has changed:
      if (buttonReading != buttonState) {
        buttonState = buttonReading;
  
        // only toggle the LED if the new button state is HIGH
        if (buttonState == HIGH) {
          on = 1;
        }
      }
    }
    lastButtonState = buttonReading;
  }
}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)

void counterclockwise (){
 // 1
 digitalWrite(motorPin1, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4, LOW);
 delayMicroseconds(motorSpeed);
 // 2
 digitalWrite(motorPin1, HIGH);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4, LOW);
 delayMicroseconds (motorSpeed);
 // 3
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4, LOW);
 delayMicroseconds(motorSpeed);
 // 4
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin4, LOW);
 delayMicroseconds(motorSpeed);
 // 5
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin4, LOW);
 delayMicroseconds(motorSpeed);
 // 6
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin4, HIGH);
 delayMicroseconds (motorSpeed);
 // 7
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4, HIGH);
 delayMicroseconds(motorSpeed);
 // 8
 digitalWrite(motorPin1, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4, HIGH);
 delayMicroseconds(motorSpeed);
}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 4 to 1
//delay "motorSpeed" between each pin setting (to determine speed)

void clockwise(){
 // 1
 digitalWrite(motorPin4, HIGH);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, LOW);
 delayMicroseconds(motorSpeed);
 // 2
 digitalWrite(motorPin4, HIGH);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, LOW);
 delayMicroseconds (motorSpeed);
 // 3
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, LOW);
 delayMicroseconds(motorSpeed);
 // 4
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin1, LOW);
 delayMicroseconds(motorSpeed);
 // 5
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin1, LOW);
 delayMicroseconds(motorSpeed);
 // 6
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin1, HIGH);
 delayMicroseconds (motorSpeed);
 // 7
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, HIGH);
 delayMicroseconds(motorSpeed);
 // 8
 digitalWrite(motorPin4, HIGH);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, HIGH);
 delayMicroseconds(motorSpeed);
}

