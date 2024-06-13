// Defining LEDs
int redLED = 4; // the number of the first LED pin
int yellowLED = 7; // the number of the second LED pin
int greenLED = 9; // the number of the third LED pin

void setup() {
  // set the digital pins as outputs:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Blink the first LED
  digitalWrite(redLED, HIGH);
  delay(500);  // On for 500 milliseconds
  digitalWrite(redLED, LOW);

  // Blink the second LED
  digitalWrite(yellowLED, HIGH);
  delay(500);
  digitalWrite(yellowLED, LOW);

  // Blink the third LED
  digitalWrite(greenLED, HIGH);
  delay(500);
  digitalWrite(greenLED, LOW);
}


