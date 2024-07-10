const int buttonPin = 2;            // Pin connected to the button
const int redLedPin = 3;            // Pin connected to the red LED
const int greenLedPin = 4;           // Pin connected to the blue LED
const int blueLedPin = 5;          // Pin connected to the green LED
const int debounceThreshold = 4;    // Threshold for debounce count

int lastButtonState = LOW;          // Previous state of the button
int debounceCounter = 0;            // Counter for debounce
int state = -2;                      // Current state for the LEDs. Was having issues so the -2 was to put all the leds off instead of starting from red led 
int buttonState;                    // the current reading fron the input pin. I added this but it turns out that I don't need it since I set the state to -2

void setup() {
  // Initialize the button pin as input
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize the LED pins as output
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  // Turn off all the leds
  digitalWrite(redLedPin, LOW);  // Changed to low
  digitalWrite(greenLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
}

void loop() {
  // Read the state of the button
  int reading = digitalRead(buttonPin);

  // Debounce the button
  if (reading == HIGH && lastButtonState == LOW) {
    debounceCounter++;
    if (debounceCounter >= debounceThreshold) {
      // Button press detected and debounced, change state
      state = (state + 1) % 3;

      // Update LEDs based on the current state
      switch (state) {
        case 0:
          digitalWrite(redLedPin, HIGH); 
          digitalWrite(greenLedPin, LOW);
          digitalWrite(blueLedPin, LOW);
          break;
        case 1:
          digitalWrite(redLedPin, LOW);
          digitalWrite(greenLedPin, HIGH);
          digitalWrite(blueLedPin, LOW);
          break;
        case 2:
          digitalWrite(redLedPin, LOW);
          digitalWrite(greenLedPin, LOW);
          digitalWrite(blueLedPin, HIGH);
          break;
      }

      debounceCounter = 0;
      lastButtonState = HIGH;
    }
  } else if (reading == LOW) {
    lastButtonState = LOW;
    debounceCounter = 0;
  }

  // Small delay to avoid bouncing effects
  delay(1);
}
