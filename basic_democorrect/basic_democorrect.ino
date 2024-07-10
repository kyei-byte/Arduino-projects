// Basic demo for configuring the MCP4728 4-Channel 12-bit I2C DAC
#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Analog Read Test!");

  // Set A0-A3 as input
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  // Try to initialize!
  if (!mcp.begin()) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }

  mcp.setChannelValue(MCP4728_CHANNEL_A, 4095); // setting channel A to max scale
  mcp.setChannelValue(MCP4728_CHANNEL_B, 2048); // setting channel B to mid - scale
  mcp.setChannelValue(MCP4728_CHANNEL_C, 1024); // setting channel C to quarter - scale
  mcp.setChannelValue(MCP4728_CHANNEL_D, 0);    // setting channel D to min scale
}

void loop() {
  // Read values from analog inputs A0-A3
  int valueA0 = analogRead(A0);
  int valueA1 = analogRead(A1);
  int valueA2 = analogRead(A2);
  int valueA3 = analogRead(A3);

  // Print values from A0-A3
  Serial.print("A0: "); Serial.print(5*valueA0/1023.0); Serial.println("V");
  Serial.print("A1: "); Serial.print(5*valueA1/1023.0); Serial.println("V");
  Serial.print("A2: "); Serial.print(5*valueA2/1023.0); Serial.println("V");
  Serial.print("A3: "); Serial.print(5*valueA3/1023.0); Serial.println("V");

  delay(1000); // delay in Milliseconds
}
