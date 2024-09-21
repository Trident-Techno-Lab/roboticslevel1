// Pin definitions
const int trigPin = 10;  // Trigger pin for HC-SR04
const int echoPin = 11;   // Echo pin for HC-SR04
const int motorAIn1 = 6;  // Control pin for Motor A (IN1)
const int motorAIn2 = 7;  // Control pin for Motor A (IN2)
const int motorBIn1 = 8;  // Control pin for Motor B (IN3)
const int motorBIn2 = 9;  // Control pin for Motor B (IN4)

// Threshold distance in cm
const int thresholdDistance = 20; // Change as needed

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigPin as output
  pinMode(echoPin, INPUT);  // Set echoPin as input
  pinMode(motorAIn1, OUTPUT); // Motor control pins
  pinMode(motorAIn2, OUTPUT);
  pinMode(motorBIn1, OUTPUT);
  pinMode(motorBIn2, OUTPUT);
}

void loop() {
  long distance = measureDistance(); // Get distance from ultrasonic sensor

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < thresholdDistance) {
    // If an obstacle is detected
    stopMotors();
    delay(500); // Pause before changing direction
    turnRight(); // Turn to avoid obstacle
  } else {
    // If no obstacle, move forward
    moveForward();
  }
}

// Function to measure distance
long measureDistance() {
  long duration, distance;
  
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = (duration * 0.0343) / 2; // Convert to cm
  return distance;
}

void moveForward() {
  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, HIGH);
  digitalWrite(motorBIn2, LOW);
}

void stopMotors() {
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, LOW);
}

void turnRight() {
  // Turn right by rotating Motor A forward and Motor B backward
  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, LOW);
  delay(500); // Adjust duration for turning
  stopMotors();
}
