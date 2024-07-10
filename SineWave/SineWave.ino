// Basic demo for configuring the MCP4728 4-Channel 12-bit I2C DAC
#include <Adafruit_MCP4728.h>
#include <Wire.h>
#include <math.h>  // Include math library for sine function

#define SineWave_h

Adafruit_MCP4728 adc;

unsigned long int n = 0;
uint16_t valueA, valueB, valueC, valueD;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10);  // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MCP4728 test!");

  // Try to initialize!
  if (!adc.begin()) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }

  // assigning values to the various channels
  adc.fastWrite(valueA, valueB, valueC, valueD);
}

void loop() {
  //Compute output
  float frequency = 50.0;     // setting the frequency to 1 Hz sine wave
  float amplitude = 1.0;      // setting amplidute to half of DAC max scale
  float sampleRate = 1000.0;  // Samples per second
  float angle = 2.0 * PI * frequency * (n / sampleRate);

  valueA = (uint16_t)((amplitude * sin(angle) + 1) * (4095.0 / 2.0));
  valueB = (uint16_t)((amplitude * sin(angle + (PI / 2)) + 1) * (4095.0 / 2.0));  // 90 degrees phase shift

  //valueC = (uint16_t)(amplitude * sin(angle + PI) + offset); // 180 degrees phase shift
  //valueD = (uint16_t)(amplitude * sin(angle + (3 * PI / 2)) + offset); // 270 degrees phase shift

  n++;

  // Write output
  adc.fastWrite(valueA, valueB, valueC, valueD);

  // Reading ADC values
  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print("\tValueA: ");
  Serial.print(valueA);
  Serial.print("\tValueB: ");
  Serial.println(valueB);
  //Serial.print("\tValueC: ");
  //Serial.print(valueC);
  //Serial.print("\tValueD: ");
  //Serial.println(valueD);

  // Print values to the serial plotter
  Serial.print(valueA);
  Serial.print(",");

  Serial.println(valueB);

  delay(1000 / sampleRate);  // Delay in Milliseconds
}
