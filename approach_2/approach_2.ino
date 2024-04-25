#include <LowPower.h>
#include <IRremote.h>

#define INT_PIN 2
#define IR_PIN 2

IRrecv irrecv(IR_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  while (!Serial) {} // Wait for serial port to connect

  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), wakeUp, CHANGE);

  irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
 // Serial.println("Going to sleep...");
  delay(50);
 // irrecv.disableIRIn(); // Disable the IR receiver before sleeping
  delay(50);
 detachInterrupt(digitalPinToInterrupt(INT_PIN)); // Detach interrupt
  delay(50);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void wakeUp() {
  Serial.println("Interrupt triggered...");
  delay(50);
  detachInterrupt(digitalPinToInterrupt(INT_PIN)); // Detach interrupt
  delay(400);
  digitalWrite(INT_PIN, LOW);//set interrupt pin low again
  delay(400);
   IRrecv irrecv(IR_PIN);
  delay(400);
  decode_results results;

  delay(400);
 
  irrecv.enableIRIn(); // Re-enable the IR receiver
  delay(50);
  for (int i = 0; i < 10; i++) {

    if (irrecv.decode(&results)) {
   Serial.println(results.value, HEX);
      irrecv.resume(); // Receive the next value
    }
     delay(100);}
  delay(5000);
   //pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), wakeUp, CHANGE); // Re-attach interrupt
  delay(50);
  //Serial.println("Going back to sleep...");
}
