/***************************************************
Simple example of reading the MCP3008 analog input channels and printing
them all out.

Author: Carter Nelson
License: Public Domain
****************************************************/
//integrating ADC and DAC chips
#include <Adafruit_MCP3008.h>
#include <Adafruit_MCP4728.h>
#include <Wire.h>
#include <math.h>  // Include math library for sine function


//initializing the chips
Adafruit_MCP3008 adc;
Adafruit_MCP4728 dac;

unsigned long int n = 0;
uint16_t valueA, valueB, valueC, valueD;

//int chan4, chan5, chan6, chan7;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    delay(10);

  Serial.println("MCP3008 simple test.");

  // Try to initialize ADC
  if (!adc.begin(2)) {
    Serial.println("Failed to find MCP3008 chip");
    while (1) {
      delay(10);
    }
  }

  // Try to initialize DAC
  if (!dac.begin()) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }
}

void loop() {
  // Compute output
  float frequency = 35.7;      // Setting the frequency to 1 Hz sine wave
  float amplitude = (4095.0 / 2);   // Setting amplitude to half of DAC max scale (12-bit DAC max value is 4095)
  float sampleRate = 1000.0;  // Samples per second
  float angle = 2.0 * PI * frequency * (n / sampleRate);

  //modify this equation 
  valueA = (uint16_t)((amplitude * sin(angle) + (4095.0 / 2.0)));
  valueB = (uint16_t)((amplitude * sin(angle + (0.5 * PI)) + (4095.0 / 2.0)));  // 90 degrees phase shift
  valueC = (uint16_t)((amplitude * sin(angle + PI) + (4095.0 / 2.0)));         // 180 degrees phase shift
  valueD = (uint16_t)((amplitude * sin(angle + (1.5 * PI)) + (4095.0 / 2.0))); // 270 degrees phase shift

  n++; // Increment sample number

  // Write output to DAC
  dac.setChannelValue(MCP4728_CHANNEL_A, valueA);
  dac.setChannelValue(MCP4728_CHANNEL_B, valueB);
  dac.setChannelValue(MCP4728_CHANNEL_C, valueC);
  dac.setChannelValue(MCP4728_CHANNEL_D, valueD);

  // Reading ADC values and printing them       /// making changes here to only print channels from the ADC 4-7
  for (int chan = 4; chan < 8; chan++) {
    int adcValue = adc.readADC(chan);  // making changes here 
      Serial.print(adcValue);
      Serial.print("\t");
      // Serial.print((char)(chan-4+'A'));
      // Serial.print(": ");
      //int adcValue4 = adc.readADC(adcValue4);
      //int adc_chan5 = adc.readADC(chan5);
      //int adc_chan6 = adc.readADC(chan6);
      //int adc_chan7 = adc.readADC(chan7);

      // Serial.print(chan4);
      // Serial.print(chan5);
      // Serial.print(chan6);
      // Serial.println(chan7);

      //Serial.print("\t");
      // }
      
    //Serial.print(adc.readADC(chan));
    // if (chan < 3) {
    //   Serial.print("\t");
    // } else {
    //   Serial.println();
    //}
}
Serial.print("\n");
//Serial.println("");

//  // Print values to the serial plotter
//   Serial.print(valueA);
//   Serial.print(",");
//   Serial.print(valueB);
//   Serial.print(",");
//   Serial.print(valueC);
//   Serial.print(",");
//   Serial.println(valueD);

  delay(100000 / sampleRate);  // Delay to maintain sample rate
  
}
