
#include <IRremote.h>
IRsend irsend;

 int RECV_PIN = 11;

String inputstring = "";     
bool stringComplete = false;  
char chars[100];
String Address = ""; 
unsigned long int code;
char add[10];
char copy[100];
int len = 101;
int count = 0;
unsigned long int PanasonicAddress;
void setup() {

  Serial.begin(9600);

  inputstring.reserve(200);
}

void loop() {
  if (stringComplete) {
     inputstring.toCharArray(chars,len); 
      code = strtoul(chars,0,16);
      delay(10);
    Address.toCharArray(add,5); 
    PanasonicAddress = strtoul(add,0,16);
    Serial.print("input string is "); 
    Serial.println(inputstring);
    Serial.print("address is "); 
    Serial.println(Address);
    Serial.print("code is "); 
    Serial.println(code);
    Serial.print("code in hex is ");
    Serial.println(code,HEX);
    Serial.print("panasonic address in hex is "); 
    Serial.println(  PanasonicAddress,HEX);
    delay(10);
    
     for (int i = 0; i <2; i++) {
        irsend.sendPanasonic(PanasonicAddress,code);//custm   
       delay(40);    
        }
       
    delay(20);
    Serial.flush();
    delay(1);   
    inputstring = "";
    Address = "";
    count = 0;
    stringComplete = false;  
  }
  delay(1);

  //delay(400); 

  receiver_mode(); 

  delay(1);
  
}

void serialEvent() {
  while (Serial.available()) {
   // digitalWrite(3, HIGH);
    delay(10);
    char inChar = (char)Serial.read();
    // Serial.println(  inChar);
    if (count < 4) {
      Address += inChar;
      }
    if ( count > 3 ) {
      
      inputstring += inChar;      
    }
     count = count+1;

      if (count == 11) {
      stringComplete = true;
    }
    }  
   
}

void receiver_mode() {

 
  delay(10);
  IRrecv irrecv(RECV_PIN);
  delay(50);
  decode_results results;
  delay(50);

  irrecv.enableIRIn(); // Start the receiver
  delay(50);


 for (int j =0 ; j<500 ;j++) {
 
  if (irrecv.decode(&results)) {
    Serial.print("Data from node "); 
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    delay(10);
  }
     }
  delay(10);
  
}
