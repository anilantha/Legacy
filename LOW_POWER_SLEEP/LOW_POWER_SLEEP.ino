#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <LowPower.h>
#include <IRremote.h>

int sensor = A0;
float VOLTS;
//float TMP;
int TEMP;

int VAL = 0;

// Define the pin number for the external interrupt
#define INT_PIN 2
IRrecv irrecv(INT_PIN);
decode_results results;

// Declare the interrupt service routine for the external interrupt
void __vector_0 () {
  // This function will be called when the interrupt is triggered
  // Do any necessary processing here
  delay(200);

  Serial.println("Waking up...");
  delay(200);

  // This function will be called when the interrupt is triggered
  // Do any necessary processing here
  delay(50);
  Serial.println("Interrupt Fired");//Print message to serial monitor
  //sleep_disable();//Disable sleep mode
  detachInterrupt(digitalPinToInterrupt(INT_PIN)); //Removes the interrupt from pin 2;
  delay(50);
  digitalWrite(INT_PIN, LOW);//set interrupt pin low again
}

void setup() {
  // Set pin 2 as input


  Serial.begin(9600); // Initialize serial communication
  while (!Serial) {} // Wait for serial port to connect
  delay(50);
  Serial.println("Starting up...");
  delay(50);

  // Enable external interrupt on pin 2
  attachInterrupt(digitalPinToInterrupt(INT_PIN), __vector_0, CHANGE);

  // Enable global interrupts
  sei();
}

void loop() {
  Serial.println("Going to sleep...");
  delay(50);

  // Put the Arduino to sleep
  delay(10);

  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  // The Arduino will wake up when the external interrupt on pin 2 is triggered
  // Do any necessary processing here
}
