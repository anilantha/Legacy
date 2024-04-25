#include <LowPower.h>
#include <IRremote.h>
int sensor = A0;
float VOLTS;
int TEMP;
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

  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

}

void wakeUp() {

  detachInterrupt(digitalPinToInterrupt(interruptPin));
  delay(100);// do not change value : stability PROMINI 3.3
  digitalWrite(interruptPin, LOW);
  delay(200);// do not change value : stability PROMINI 3.3
  int RECV_PIN = 2;
  delay(400);// do not change value : stability PROMINI 3.3
  IRrecv irrecv(RECV_PIN);
  delay(400);// do not change value : stability PROMINI 3.3
  decode_results results;
  delay(400);// do not change value : stability PROMINI 3.3
  irrecv.enableIRIn(); // Start the receiver
  delay(400);// do not change value : stability PROMINI 3.3
  VAL = 0;
  delay(10);

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
      Sense();
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);VAL = 0;results.value = 0;}
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

       results.value = 0;
          delay(10);
        irrecv.resume();//clear Cache
  }
  
    delay(10); 
    digitalWrite(Receiver, HIGH);
    delay(50); 

      delay(10);
    int interruptPin = 2;
   delay(10); 
  pinMode(interruptPin, INPUT_PULLUP);
   delay(10); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
   delay(40); 
}

void Sense() {
  int reading = analogRead(sensor);
  VOLTS = (reading * 3.3) / 1024.0;
  TEMP = ((VOLTS - 0.5) * 100);
  Serial.print("Temperature (C): ");
  Serial.println(TEMP);

}
