#include <IRremote.h>

int RECV_PIN = 11;
int ADD =0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {

     ADD  = results.address;
   //  Serial.println(ADD);

    // Ensure the received data has 28 bits
    if (results.address == 0xABC0) 
    {
      long payload = results.value;  // Example payload value without "0x" prefix

      // Extract temperature, capacity, node ID, and PV from the payload
      int temperature = (payload >> 24) & 0xFF;
      float extractedCap = (payload >> 16) & 0xFF;
      int extractedNodeID = (payload >> 8) & 0xFF;
      float PV = payload & 0xFF;

      // Print the extracted values
      Serial.print("Temp: ");
      Serial.print(temperature);
      Serial.print("; ");
      Serial.print("Capacity: ");
      Serial.print(extractedCap/10);
      Serial.print("; ");
      Serial.print("Node ID: ");
      Serial.print(extractedNodeID);
      Serial.print("; ");
      Serial.print("PV: ");
      Serial.println(PV/10);
      ADD =0;
      payload = 0;
      extractedNodeID = 0;
      delay(1000);
    
      results.address = 0x000;
          results.value = 0;
    results.address = 0;
    delay(2);
    irrecv.resume();//clear Cache
     // payload = 0;
    //  extractedNodeID = 0;
    irrecv.resume(); // Receive the next value
  }
  else {
        irrecv.resume(); // Receive the next value
  }
  }
}
