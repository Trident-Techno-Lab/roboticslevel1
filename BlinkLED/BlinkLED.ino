// Global variables
int buttonPin = 7;    // Button connected to Pin 7
int ledPin = 13;      // LED connected to Pin 13
int buttonState = 0;  // Variable to store the button state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set buttonPin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);           // Set ledPin as output
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the state of the button

  // Check if the button is pressed
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);  // Turn the LED on
  } else {
    digitalWrite(ledPin, LOW);   // Turn the LED off
  }
}
