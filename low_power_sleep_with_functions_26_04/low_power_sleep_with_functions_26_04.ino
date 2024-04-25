#include <LowPower.h>
#include <IRremote.h>
//
//int RECV_PIN = 2;
//IRrecv irrecv(RECV_PIN);
//decode_results results;

const int interruptPin = 2;
const int Receiver = 9;
int VAL = 0;

void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
  pinMode(Receiver, OUTPUT);
  digitalWrite(Receiver, HIGH);


  Serial.begin(9600);
}

void loop() {
//  delay(100);
//    int interruptPin = 2;
//   delay(100); 
//  pinMode(interruptPin, INPUT_PULLUP);
//   delay(100); 
//  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
//   delay(400); 
//   
//  Serial.println("Going to sleep...");
//  delay(1000); // Add delay for stability
 
  // Enter sleep mode
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  // Code execution resumes here when interrupt is triggered
//  Serial.println("Interrupt triggered!");
//  delay(100); // Add delay for stability

  // Do whatever you need to do here
//  Serial.println("Executing code...");
//  delay(100); // Add delay for stability
//
// // int interruptPin = 2;
//   delay(100); 
//  pinMode(interruptPin, INPUT_PULLUP);
//   delay(100); 
//  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
//   delay(100); 
  // Go back to sleep
}

void wakeUp() {

  detachInterrupt(digitalPinToInterrupt(interruptPin));
  delay(100);
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
  VAL = 0;
  delay(10);

 // while (true)
  {
    if (irrecv.decode(&results))
    { digitalWrite(Receiver, LOW);
     // Serial.print("value is  ");
      delay(10);
     // Serial.println(results.value, HEX);
      delay(10);
     // Serial.print("address is  ");
      delay(10);
     // Serial.println(results.address, HEX);
      irrecv.resume(); // Receive the next value
      delay(200);
    //  break; // exit the while loop
    }


   
        VAL = results.value;
//        Serial.println(VAL);
        delay(10);

      //  digitalWrite(Receiver, LOW);
        delay(10);


    
    if (VAL == -17487) {Serial.println ("Command 1"); delay(10); 
     digitalWrite(Receiver, LOW);
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);VAL = 0;results.value = 0;}
  delay(100);
    if (VAL == -17486) {Serial.println ("Command 2"); delay(10); 
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);;VAL = 0;results.value = 0;}
  delay(100);
    if (VAL == -17485) {Serial.println ("Command 3"); delay(10); 
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);VAL = 0;results.value = 0;}
  delay(100);
    if (VAL == -17483) {Serial.println ("Command 4"); delay(10); 
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);VAL = 0;results.value = 0;}
  delay(100);
    if (VAL == -17481) {Serial.println ("Command 5"); delay(10); 
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);VAL = 0;results.value = 0;}
  
    else {}
//    //Serial.println ("Noise"); 
//  delay(10); delay(5);LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);VAL = 0;results.value = 0; irrecv.resume(); delay(100);}

    
       results.value = 0;
          delay(10);
        irrecv.resume();//clear Cache
  }
  // Do nothing, just wake up from sleep
    delay(400); 
    digitalWrite(Receiver, HIGH);
    delay(100); 

      delay(100);
    int interruptPin = 2;
   delay(100); 
  pinMode(interruptPin, INPUT_PULLUP);
   delay(100); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
   delay(400); 
}
