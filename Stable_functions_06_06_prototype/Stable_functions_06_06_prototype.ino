#include <LowPower.h>
#include <IRremote.h>

#define sensor A0

float VOLTS;
//float TMP;
float TEMP;
const int interruptPin = 2;
const int Receiver = 9;
int VAL = 0;
bool volt_m = false;
bool temp_m = false;

void setup() {
  IRsend irsend; 
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
  pinMode(Receiver, OUTPUT);
  digitalWrite(Receiver, HIGH);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {


  if (temp_m == 1) {Sense();}
  
  else {}
  
  delay(10);

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

    if (VAL == -17487) {
      Serial.println ("Display Logo");
//      pinMode(10, OUTPUT);
//      pinMode(11, OUTPUT);
//      digitalWrite(11, LOW);
//      digitalWrite(10, HIGH);
//      delay(1500);
//      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
//      delay(500);
//      digitalWrite(11, HIGH);
//      pinMode(10, INPUT_PULLUP);
//      delay(500);
//      digitalWrite(11, LOW);
//      digitalWrite(10, LOW);
//      delay(100);
      LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }
    
    if (VAL == -17486) {
      Serial.println ("Clear Logo"); delay(10);
//      pinMode(10, OUTPUT);
//      pinMode(11, OUTPUT);
//      digitalWrite(10, LOW);
//      delay(100);
//      digitalWrite(11, HIGH);
//      delay(500);
//      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
//      delay(500);
//      //digitalWrite(10, HIGH);
//      pinMode(11, INPUT_PULLUP);
//      delay(3000);
//      digitalWrite(11, LOW);
//      digitalWrite(10, LOW);
//      delay(100);
//      delay(10);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }
   
    if (VAL == -17482) {
      Serial.println ("Command 3"); delay(10);
//      digitalWrite(Receiver, LOW);
//      delay(50);
//      
//      temp_m = true;
//      delay(50);
//      VAL = 0; results.value = 0;
//      delay(10);
//      delay(100);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }
   
    if (VAL == -17483) {
      Serial.println ("Displaying LEVEL2"); delay(10);       
//      pinMode(6, OUTPUT);
//      pinMode(9, OUTPUT);
//      pinMode(8, OUTPUT);
//      digitalWrite(6, LOW);
//      digitalWrite(9, HIGH);
//      digitalWrite(8, HIGH);
//      delay(500);
//      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
//      delay(500);
//      digitalWrite(6, HIGH);
//      pinMode(9, INPUT_PULLUP);
//      pinMode(8, INPUT_PULLUP);
//      delay(500);
//      digitalWrite(6, LOW);
//      digitalWrite(9, LOW);
//      digitalWrite(8, LOW);
//      delay(100);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }
   
    if (VAL == -17481) {
      Serial.println ("Displaying LEVEL3");delay(10);
//      pinMode(6, OUTPUT);
//      pinMode(9, OUTPUT);
//      pinMode(8, OUTPUT);
//      pinMode(7, OUTPUT);
//      digitalWrite(6, LOW);
//      digitalWrite(9, HIGH);
//      digitalWrite(8, HIGH);
//      digitalWrite(7, HIGH);
//      delay(500);
//      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
//      delay(500);
//      digitalWrite(6, HIGH);
//      pinMode(9, INPUT_PULLUP);
//      pinMode(8, INPUT_PULLUP);
//      pinMode(7, INPUT_PULLUP);
//      delay(500);
//      digitalWrite(6, LOW);
//      digitalWrite(9, LOW);
//      digitalWrite(8, LOW);
//      digitalWrite(7, LOW);
//      delay(100);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }

     if (VAL == -17480) {
      Serial.println ("Displaying Clear"); delay(10);
//      pinMode(6, OUTPUT);
//      pinMode(9, OUTPUT);
//      pinMode(8, OUTPUT);
//      pinMode(7, OUTPUT);
//      digitalWrite(9, LOW);
//      digitalWrite(8, LOW);
//      digitalWrite(7, LOW);
//      digitalWrite(6, HIGH);
//      delay(500);
//      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
//      delay(500);
//      digitalWrite(9, HIGH);
//      digitalWrite(8, HIGH);
//      digitalWrite(7, HIGH);
//      pinMode(6, INPUT_PULLUP);
//      delay(500);
//      digitalWrite(6, LOW);
//      digitalWrite(9, LOW);
//      digitalWrite(8, LOW);
//      digitalWrite(7, LOW);
//      delay(100);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }

     if (VAL == -17485) {
      Serial.println ("Displaying LEVEL1"); delay(10);
//      pinMode(6, OUTPUT);
//      pinMode(9, OUTPUT);
//      digitalWrite(6, LOW);
//      digitalWrite(9, HIGH);
//      delay(500);
//      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
//      delay(500);
//      digitalWrite(6, HIGH);
//      pinMode(9, INPUT_PULLUP);
//      delay(500);
//      digitalWrite(6, LOW);
//      digitalWrite(9, LOW);
//      delay(100);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }

     if (VAL == -17479) {
   
      digitalWrite(Receiver, LOW);
      Serial.println("deep sleep");
      delay(10);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);

      delay(10);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }

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
  delay(50);
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  delay(100);// do not change value : stability PROMINI 3.3
  digitalWrite(interruptPin, LOW);
  delay(200);// do not change value : stability PROMINI 3.3

  digitalWrite(Receiver, HIGH);
  delay(50);
    IRsend irsend;
    delay(200);
  int reading = analogRead(sensor);
  VOLTS = reading * (2600 / 1024.0);
  TEMP = ((VOLTS - 500) / 10);
  //TEMP = TMP;
  Serial.print("Temperature (C): ");
  delay(20);
  Serial.println(TEMP);
   //TEMP = TEMP + 9;
  delay(20);

  for (int i = 0; i < 1; i++) {
    // irsend.sendPanasonic(0x4004, 0xABCDEF1);
    irsend.sendRC5(TEMP, 8);
    //irsend.sendSony(0xa90, 12);
    delay(40); //keep 40ms for sony !!!
  }
  
  delay(10);
  temp_m = false;
  delay(10);
  digitalWrite(Receiver, LOW);
  delay(10);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  delay(100);
  wakeUp();


}
