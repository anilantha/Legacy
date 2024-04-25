#include <IRremote.h>
#include <unordered_map>

int RECV_PIN = 11;
bool processedCorrectSignal = false; // Flag to track if correct signal has been processed

IRrecv irrecv(RECV_PIN);
decode_results results;

std::unordered_map<int, bool> processedNodeIDs; // Hashmap to store processed node IDs

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (!processedCorrectSignal && results.address == 0xABC0) {
      long payload = results.value;  // Example payload value without "0x" prefix

      // Extract temperature, capacity, node ID, and PV from the payload
      int temperature = (payload >> 24) & 0xFF;
      float extractedCap = (payload >> 16) & 0xFF;
      int extractedNodeID = (payload >> 8) & 0xFF;
      float PV = payload & 0xFF;

      // Check if the current extractedNodeID has already been processed
      if (processedNodeIDs.find(extractedNodeID) == processedNodeIDs.end()) {
        // If not processed, print the extracted values
        Serial.print("Temp: ");
        Serial.print(temperature);
        Serial.print("; ");
        Serial.print("Capacity: ");
        Serial.print(extractedCap / 10.0); // Convert to float
        Serial.print("; ");
        Serial.print("Node ID: ");
        Serial.print(extractedNodeID);
        Serial.print("; ");
        Serial.print("PV: ");
        Serial.println(PV / 10.0); // Convert to float

        // Mark the current node ID as processed
        processedNodeIDs[extractedNodeID] = true;
      }

      // Set the flag to true to indicate the correct signal has been processed
      processedCorrectSignal = true;

      delay(1000);
      irrecv.resume(); // Clear cache and prepare for the next value
    } else {
      irrecv.resume(); // Receive the next value
    }
  } else {
    // No IR signal received, reset the flag
    processedCorrectSignal = false;
  }
}
