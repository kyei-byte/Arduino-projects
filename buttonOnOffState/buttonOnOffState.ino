// Constants
const int buttonPin = 7;    // Pin number for the button
const int ledPin = 10;      // Pin number for the LED

// Variables
bool ledState = false;      // To store the current state of the LED
bool buttonState = false;   // To store the current state of the button
bool lastButtonState = false; // To store the previous state of the button

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Initialize the button pin as an input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Start with the LED off
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the current state of the button
  buttonState = digitalRead(buttonPin) == LOW;  // Button is active-low

  // Check if the button is pressed (transition from high to low)
  if (buttonState && !lastButtonState) {
    // Change the state of the LED
    ledState = !ledState;

    // Update the LED based on the new state
    digitalWrite(ledPin, ledState ? HIGH : LOW);
  }

  // Update the last button state
  lastButtonState = buttonState;
}
