#include <LowPower.h>
#include <IRremote.h>
//
//int RECV_PIN = 2;
//IRrecv irrecv(RECV_PIN);
//decode_results results;

const int interruptPin = 2;

void setup() {
//  pinMode(interruptPin, INPUT_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);


  Serial.begin(9600);
}

void loop() {

    int interruptPin = 2;
   delay(100); 
  pinMode(interruptPin, INPUT_PULLUP);
   delay(100); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
   delay(100); 
  Serial.println("Going to sleep...");
  delay(1000); // Add delay for stability
 
  // Enter sleep mode
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  // Code execution resumes here when interrupt is triggered
  Serial.println("Interrupt triggered!");
  delay(1000); // Add delay for stability

  // Do whatever you need to do here
  Serial.println("Executing code...");
  delay(100); // Add delay for stability

 // int interruptPin = 2;
   delay(100); 
  pinMode(interruptPin, INPUT_PULLUP);
   delay(100); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
   delay(100); 
  // Go back to sleep
}

void wakeUp() {

  detachInterrupt(digitalPinToInterrupt(interruptPin));
  delay(400);
  digitalWrite(interruptPin, LOW);
  delay(400);
  int RECV_PIN = 2;
  delay(400);
  IRrecv irrecv(RECV_PIN);
  delay(400);
  decode_results results;
  delay(400);
  irrecv.enableIRIn(); // Start the receiver
  delay(400);

 // while (true)
  {
    if (irrecv.decode(&results))
    { 
      delay(100);
      // Print the received code to the serial monitor
      Serial.print("Received code: 0x");
        delay(100);
      Serial.println(results.value, HEX);

      // Delay for stability
      delay(100);

      // Resume the receiver
      irrecv.resume();
      delay(100);
    //  break; // exit the while loop
    }
  }
  // Do nothing, just wake up from sleep
}
