int sensor = A0;
float VOLTS;
//float TMP;
int TEMP;

class DigitalPin
{
  public:
    DigitalPin(int pin);
    void begin();
    void on();
    void off();
    void disp();
    void clean();

  private:
    int _pin;
};

DigitalPin::DigitalPin(int pin)
{
  _pin = pin;
}

void DigitalPin::begin()
{
  pinMode(_pin, OUTPUT);
}

void DigitalPin::off()
{
  pinMode(_pin, INPUT_PULLUP);
  digitalWrite(_pin, HIGH);
  delay(5);
}

void DigitalPin::on()
{
  digitalWrite(_pin, LOW);
  delay(50);
}

void DigitalPin::clean()
{
  digitalWrite(11, LOW);
  delay(50);
  digitalWrite(_pin, HIGH);
  delay(50);
  digitalWrite(_pin, LOW);
  delay(50);
}

void DigitalPin::disp()
{
  digitalWrite(_pin, HIGH);
  delay(3000);
  digitalWrite(_pin, LOW);
  pinMode(_pin, INPUT_PULLUP);
  delay(50);
}

DigitalPin DIGITC(11);
DigitalPin DIGIT1(4);
DigitalPin DIGIT2(5);
DigitalPin DIGIT3(6);
DigitalPin DIGIT4(7);
DigitalPin DIGIT5(8);
DigitalPin DIGIT6(9);
DigitalPin DIGIT7(10);


#include "LowPower.h"

#include <IRremote.h>
#include <avr/sleep.h>//this AVR library contains the methods that controls the sleep modes
#define interruptPin 2 //Pin we are going to use to wake up the Arduino
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);

int VAL = 0;

decode_results results;

void setup()
{

  //// enable clock prescaler changes
  //CLKPR = (1 << CLKPCE);
  //
  //// set clock prescaler to 8 (1 MHz with an 8 MHz crystal)
  //CLKPR = (0 << CLKPS3) | (1 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);


  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  Serial.begin(9600);//Start Serial Comunication
  //  pinMode(LED_BUILTIN, OUTPUT); //We use the led on pin 13 to indecate when Arduino is A sleep
  //  digitalWrite(LED_BUILTIN, HIGH); //turning LED on
  Serial.println("Enabling IRin");

  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");


  delay(100);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);



}

void loop()

{

  delay(2);
  for (int i = 0; i < 4; i++) {

    if (irrecv.decode(&results)) {
      Serial.print("value is  ");
      Serial.println(results.value, HEX);
      Serial.print("address is  ");
      Serial.println(results.address, HEX);
      irrecv.resume(); // Receive the next value
    }
    VAL = results.value;

    // Serial.println(results.address);

    Serial.println(VAL);

    if (VAL == -17482) { //TX mode

      digitalWrite(5, LOW);
      Serial.println ("TX code received BBBBBB6");

      Sense();

      digitalWrite(5, HIGH);
      delay(10);
      Transmit();
    }
    delay(10);
    // / }

    if (VAL == -17487) { //LOGo on
      digitalWrite(5, LOW);
      Serial.println ("Displaying 1");


      pinMode(10, OUTPUT);
      pinMode(11, OUTPUT);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);

      delay(1500);

      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);

      delay(500);

      digitalWrite(11, HIGH);

      pinMode(10, INPUT_PULLUP);

      delay(500);

      digitalWrite(11, LOW);
      digitalWrite(10, LOW);

      delay(100);
      VAL = 0;
      results.value = 0;
      Serial.println("sleep");

      digitalWrite(5, HIGH);

      Going_To_Sleep();
    }

    if (VAL == -17486) { //Arranging display digits for 2

      digitalWrite(5, LOW);

      Serial.println ("Clear Logo");

      pinMode(10, OUTPUT);
      pinMode(11, OUTPUT);

      digitalWrite(10, LOW);
      delay(100);
      digitalWrite(11, HIGH);

      delay(500);

      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);

      delay(500);

      //digitalWrite(10, HIGH);

      pinMode(11, INPUT_PULLUP);

      delay(3000);

      digitalWrite(11, LOW);
      digitalWrite(10, LOW);

      delay(100);
      VAL = 0;
      results.value = 0;
      Serial.println("sleep");

      digitalWrite(5, HIGH);
      Going_To_Sleep();
    }

    if (VAL == -17485) { //Arranging display digits for 3
      digitalWrite(5, LOW);
      Serial.println ("Displaying 3");

      pinMode(13, OUTPUT);
      pinMode(9, OUTPUT);
      digitalWrite(13, LOW);
      digitalWrite(9, HIGH);

      delay(500);

      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);

      delay(500);

      digitalWrite(13, HIGH);

      pinMode(9, INPUT_PULLUP);

      delay(500);

      digitalWrite(13, LOW);
      digitalWrite(9, LOW);


      delay(100);
      VAL = 0;
      results.value = 0;
      Serial.println("sleep");

      digitalWrite(5, HIGH);
      Going_To_Sleep();
    }

    if (VAL == -17483) { //Arranging display digits for 3
      digitalWrite(5, LOW);
      Serial.println ("Displaying LEVEL2");

      pinMode(13, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(8, OUTPUT);
      digitalWrite(13, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);

      delay(500);

      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);

      delay(500);

      digitalWrite(13, HIGH);

      pinMode(9, INPUT_PULLUP);
      pinMode(8, INPUT_PULLUP);

      delay(500);

      digitalWrite(13, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);

      delay(100);
      VAL = 0;
      results.value = 0;
      Serial.println("sleep");
      digitalWrite(5, HIGH);
      Going_To_Sleep();
    }

    if (VAL == -17481) { //Arranging display digits for 3
      digitalWrite(5, LOW);
      Serial.println ("Displaying LEVEL2");

      pinMode(13, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(8, OUTPUT);
      pinMode(7, OUTPUT);
      digitalWrite(13, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);

      delay(500);

      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);

      delay(500);

      digitalWrite(13, HIGH);

      pinMode(9, INPUT_PULLUP);
      pinMode(8, INPUT_PULLUP);
      pinMode(7, INPUT_PULLUP);

      delay(500);

      digitalWrite(13, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);

      delay(100);
      VAL = 0;
      results.value = 0;
      Serial.println("sleep");
      digitalWrite(5, HIGH);
      Going_To_Sleep();
    }

    if (VAL == -17480) { //Arranging display digits for 3
      digitalWrite(5, LOW);
      Serial.println ("Displaying Clear");

      pinMode(13, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(8, OUTPUT);
      pinMode(7, OUTPUT);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      digitalWrite(13, HIGH);

      delay(500);

      LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);

      delay(500);

      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);

      pinMode(13, INPUT_PULLUP);

      delay(500);

      digitalWrite(13, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);

      delay(100);
      VAL = 0;
      results.value = 0;
      Serial.println("sleep");

      digitalWrite(5, HIGH);
      Going_To_Sleep();
    }

    if (VAL == -17479) { //Deep Sleep mode
      digitalWrite(5, LOW);

      Serial.println("deep sleep");

      delay(100);

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

      VAL = 0;
      results.value = 0;
      digitalWrite(5, HIGH);
      delay(10);
      Going_To_Sleep();
    }

  }

  Serial.println("sleep");
  Going_To_Sleep();

}

void Going_To_Sleep() {
  pinMode(interruptPin, INPUT_PULLUP); //Set pin d2 to input using the buildin pullup resistor
  delay(100);
  sleep_enable();//Enabling sleep mode
  attachInterrupt(0, wakeUp, LOW);//attaching a interrupt to pin d2
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  //  digitalWrite(LED_BUILTIN, LOW); //turning LED off
  delay(1000); //wait a second to allow the led to be turned off before going to sleep
  sleep_cpu();//activating sleep mode



  Serial.println("just woke up!");//next line of code executed after the interrupt

  //  // enable clock prescaler changes
  //CLKPR = (1 << CLKPCE);
  //
  //// set clock prescaler to 8 (1 MHz with an 8 MHz crystal)
  //CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
  //  //  digitalWrite(LED_BUILTIN, HIGH); //turning LED on
}

void wakeUp() {
  Serial.println("Interrrupt Fired");//Print message to serial monitor
  delay(50);
  sleep_disable();//Disable sleep mode
  delay(50);
  detachInterrupt(0); //Removes the interrupt from pin 2;
  delay(50);
  digitalWrite(interruptPin, LOW);//set interrupt pin low again
  delay(400);
  int RECV_PIN = 2;
  delay(400);
  IRrecv irrecv(RECV_PIN);
  delay(400);
  decode_results results;
  delay(400);
  irrecv.enableIRIn(); // Start the receiver
}


void Sense() {
  int reading = analogRead(sensor);
  VOLTS = (reading * 3.3) / 1024.0;
  TEMP = ((VOLTS - 0.5) * 100);
  //TEMP = TMP;
  Serial.print("Temperature (C): ");
  Serial.println(TEMP);

}

void Transmit() { // transmit fuction
  Serial.println("TX BBBBBB6 Day");
  IRsend irsend;
  delay (1700);

  for (int i = 0; i < 1; i++) {
    // irsend.sendPanasonic(0x4004, 0xABCDEF1);
    irsend.sendRC5(TEMP, 8);
    delay(40); //keep 40ms for sony !!!
  }
  VAL = 0;
  results.value = 0;

  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);

  Serial.println("sleep");
  Going_To_Sleep();

}
