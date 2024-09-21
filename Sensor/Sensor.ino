const int trigPin = 10;  // Trigger pin for HC-SR04
const int echoPin = 11;   // Echo pin for HC-SR04

void setup() {
  Serial.begin(9600);      // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigPin as output
  pinMode(echoPin, INPUT);  // Set echoPin as input
}

void loop() {
  long duration, distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by sending a 10 microsecond HIGH pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = (duration * 0.0343) / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Wait for 1 second before the next measurement
}
