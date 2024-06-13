/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// defining LEDs
int redLED = 3;
int yellowLED = 5;
int greenLED = 7;

// assigning LEDs outputs
void setup() {

  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
}

  // a LED on while others off 

void loop(){
  //blink once while other LEDs off with specific time intervals
 Serial.print("Blink once while other LEDs off");

 digitalWrite(redLED,HIGH);
 delay(1000);
 digitalWrite(redLED,LOW);
 delay(1000);
 digitalWrite(yellowLED,HIGH);
 delay(2000);
 digitalWrite(yellowLED,LOW);
 delay(2000);
 digitalWrite(greenLED,HIGH);
 delay(2500);
 digitalWrite(greenLED,LOW);
 delay(2500);
}
