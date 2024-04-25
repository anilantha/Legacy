#include <LowPower.h>
#include <IRremote.h>
#define sensor A0
#define storage A1
//int sensor = A0;
float VOLTS;
//float TMP;
float TEMP;
float voltage;
const int interruptPin = 2;
const int Receiver = 9;
int VAL = 0;
int ADD = 0;
bool volt_m = false;
bool temp_m = false;

void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
  pinMode(Receiver, OUTPUT);
  digitalWrite(Receiver, HIGH);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT); //Cap sense on
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (volt_m == 1) {
  Sense_storage();
  }
  else {}
  delay(10);
  if (temp_m == 1) {
  Sense();
  }
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
  delay(300);// do not change value : stability PROMINI 3.3
  irrecv.enableIRIn(); // Start the receiver
  delay(200);// do not change value : stability PROMINI 3.3
  VAL = 0;
  delay(5);

  {
    if (irrecv.decode(&results))
    { digitalWrite(Receiver, LOW);
//       Serial.print("value is  ");
//      delay(10);
//      Serial.println(results.value, HEX);
//      delay(10);
//       Serial.print("address is  ");
//      delay(5);
//       Serial.println(results.address, HEX);
      irrecv.resume(); // Receive the next value
      delay(200);// do not change value : stability PROMINI 3.3
    }
    VAL = results.value;
//            Serial.println(VAL);
//          delay(10);

        ADD  = results.address;
//            Serial.println(ADD);
//          delay(10);
    //  digitalWrite(Receiver, LOW);
    delay(5);
if (ADD == -21566){
    if (VAL == -17487) { 
      Serial.println ("Command 1"); 
      delay(10); // Narrow LED TX
      digitalWrite(Receiver, LOW);
      digitalWrite(10, HIGH); 
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(10);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;results.address = 0; // wait for a second
      delay(10);
      digitalWrite(3, LOW);
      digitalWrite(10, LOW); 
      delay(10);
      LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;results.address = 0;
    }
    delay(2);
    if (VAL == -17486) {
      Serial.println ("Command 2"); 
      delay(10); // Cap_voltage_measure
      volt_m = true;
      delay(10);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;results.address = 0;
    }
    delay(2);
    if (VAL == -17485) {
      Serial.println ("Command 3"); 
      delay(10); //Temperature measure & Transmission
      digitalWrite(Receiver, LOW);
      temp_m = true;
      delay(10);
      delay(10);
      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;results.address = 0;
    }
    delay(2);
    if (VAL == -17483) {
      Serial.println ("Command 4"); 
      delay(10);
      digitalWrite(Receiver, LOW);
      digitalWrite(8, HIGH); 
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(10);
      LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0; // wait for a second
      delay(10);
      digitalWrite(3, LOW);
      digitalWrite(8, LOW); 
      delay(10);
      LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;
    }
    delay(2);
    if (VAL == -17481) {
      Serial.println ("Command 5"); 
      delay(10);
      digitalWrite(Receiver, LOW);

      LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); VAL = 0; results.value = 0;results.address = 0;
      EN_TX();
    
    }

    else {}

    results.value = 0;
    results.address = 0;
    delay(2);
    irrecv.resume();//clear Cache
  }

      else {}

    results.value = 0;
    delay(2);
    irrecv.resume();//clear Cache
  }

  delay(2);
  digitalWrite(Receiver, HIGH);
  delay(10);

  delay(2);
  int interruptPin = 2;
  delay(2);
  pinMode(interruptPin, INPUT_PULLUP);
  delay(2);
  attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, FALLING);
  delay(2);
}

float Sense_storage() {
  digitalWrite(7, HIGH);   // Cap sense on (HIGH is the voltage level)
  delay(2);
  int sensorValue = analogRead(storage);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue *2* (3.3 / 1023.0);
  // print out the value you read:
  Serial.print("Cap Voltage ");
  delay(2);
  Serial.println(voltage);
  delay(2);
  digitalWrite(7, LOW);
  delay(2);
  volt_m = false;
  delay(2);

  return voltage; // Return the voltage value
}


void Sense() {
  delay(50);
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  delay(100);// do not change value : stability PROMINI 3.3
  digitalWrite(interruptPin, LOW);
  delay(200);// do not change value : stability PROMINI 3.3
  digitalWrite(Receiver, HIGH);
  delay(10);
    IRsend irsend;
    delay(200);
  int reading = analogRead(sensor);
  VOLTS = reading * (3000 / 1024.0);
  TEMP = ((VOLTS - 500) / 10);
  //TEMP = TMP;
  Serial.print("Temperature (C): ");
  delay(5);
  Serial.println(TEMP);
   //TEMP = TEMP + 9;
  delay(2);
  for (int i = 0; i < 1; i++) {
    // irsend.sendPanasonic(0x4004, 0xABCDEF1);
    irsend.sendRC5(TEMP, 8);
    //irsend.sendSony(0xa90, 12);
    delay(40); //keep 40ms for sony !!!
  } 
  delay(5);
  temp_m = false;
  delay(2);
  digitalWrite(Receiver, LOW);
  delay(10);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  delay(2);
  wakeUp();
}

void EN_TX() {
  float stor = Sense_storage();
  delay(2);

  if (stor >= 4.58) {
    while (stor > 3.60) {
      digitalWrite(10, HIGH);
      digitalWrite(3, HIGH);
      delay(2);
      for (int i = 0; i < 1; i++) {
        LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
      }
      delay(2);
      digitalWrite(3, LOW);
      digitalWrite(10, LOW);
      delay(3);
      stor = Sense_storage(); // Update the storage value after delay
    }
  } else {
    while (stor < 4.58) {
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      stor = Sense_storage(); // Update the storage value after delay
    }
  }
  delay(2);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  delay(2);
  wakeUp();
}
