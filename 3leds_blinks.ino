// Defining LEDs
int redLED = 5;
int yellowLED = 7;
int greenLED = 9;
int del = 400; // Milliseconds of delayment

void setup() {
// Making the LEDs outputs
pinMode(redLED,OUTPUT);
pinMode(yellowLED,OUTPUT);
pinMode(greenLED,OUTPUT);
}

void loop() {
// blink blonk
Serial.print("Blink Blonk");

// Making every LED blink.
digitalWrite(redLED,HIGH);
delay(del);
digitalWrite(redLED,LOW);
delay(del);
digitalWrite(yellowLED,HIGH);
delay(del);
digitalWrite(yellowLED,LOW);
digitalWrite(greenLED,HIGH);
delay(del);
digitalWrite(greenLED,LOW);
}