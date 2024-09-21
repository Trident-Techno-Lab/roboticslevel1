// Global variables
const int motorAIn1 = 6;  // Control pin for Motor A (IN1)
const int motorAIn2 = 7;  // Control pin for Motor A (IN2)
const int motorBIn1 = 8;  // Control pin for Motor B (IN3)
const int motorBIn2 = 9;  // Control pin for Motor B (IN4)

void setup() {
  // Set motor control pins as outputs
  pinMode(motorAIn1, OUTPUT);
  pinMode(motorAIn2, OUTPUT);
  pinMode(motorBIn1, OUTPUT);
  pinMode(motorBIn2, OUTPUT);
}

void loop() {
  // Move motors forward
  moveForward(); // Activate motors
  delay(2000);   // Move for 2 seconds
  stopMotors();  // Stop the motors
  delay(1000);   // Wait for 1 second

  // Move motors backward
  moveBackward(); // Activate motors
  delay(2000);     // Move for 2 seconds
  stopMotors();    // Stop the motors
  delay(1000);     // Wait for 1 second
}

void moveForward() {
  // Set motor A to move forward
  digitalWrite(motorAIn1, HIGH);
  digitalWrite(motorAIn2, LOW);
  
  // Set motor B to move forward
  digitalWrite(motorBIn1, HIGH);
  digitalWrite(motorBIn2, LOW);
}

void moveBackward() {
  // Set motor A to move backward
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, HIGH);
  
  // Set motor B to move backward
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, HIGH);
}

void stopMotors() {
  // Stop both motors
  digitalWrite(motorAIn1, LOW);
  digitalWrite(motorAIn2, LOW);
  digitalWrite(motorBIn1, LOW);
  digitalWrite(motorBIn2, LOW);
}
