#include <LiquidCrystal.h>

// Initialize LCD with pin numbers (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int sensorValue = 0;   // Stores the raw analog reading from the photoresistor
int counter = 0;       // Counts how many objects have passed through the beam
int ledState = 0;      // Stores the current HIGH/LOW state of the blue LED

void setup()
{
  pinMode(3, OUTPUT);  // Blue LED — lights up when an object is detected
  pinMode(6, OUTPUT);  // Motor speed control (PWM pin)
  pinMode(4, OUTPUT);  // Motor direction control pin A
  pinMode(2, OUTPUT);  // Motor direction control pin B

  lcd.begin(16, 2);        // Initialize a 16-column, 2-row LCD
  lcd.setCursor(0, 1);     // Move cursor to start of row 1
  lcd.print("Objects:");   // Print static label on the LCD
}

// Called when an object breaks the laser beam (new object detected)
void objectDetected() {
  digitalWrite(3, HIGH);      // Turn on blue LED to signal detection
  lcd.setCursor(9, 1);        // Position cursor after the "Objects:" label
  lcd.print(counter);         // Display current object count on LCD
  counter = counter + 1;      // Increment the object counter
  delay(50);                  // Short delay to debounce the sensor
}

// Called when no object is blocking the laser beam
void noObject() {
  digitalWrite(3, LOW);       // Turn off blue LED (beam is clear)
  lcd.setCursor(9, 1);        // Position cursor after the "Objects:" label
  lcd.print(counter);         // Display current count (unchanged)
  delay(50);                  // Short delay for stability
}

// Called when an object is still blocking the beam (already counted, don't count again)
void objectHolding() {
  digitalWrite(3, HIGH);      // Keep blue LED on while object is still present
  lcd.setCursor(9, 1);        // Position cursor after the "Objects:" label
  lcd.print(counter);         // Display current count (unchanged)
  delay(50);                  // Short delay for stability
}

// Moves the conveyor belt forward
void forward() {
  digitalWrite(4, LOW);       // Set direction pin A to LOW
  digitalWrite(2, HIGH);      // Set direction pin B to HIGH (forward direction)
  analogWrite(6, 140);        // Set motor speed (0–255); 140 = medium speed
}

// Moves the conveyor belt backward
void backward() {
  digitalWrite(4, HIGH);      // Set direction pin A to HIGH
  digitalWrite(2, LOW);       // Set direction pin B to LOW (reverse direction)
  analogWrite(6, 140);        // Set motor speed to medium
}

// Stops the conveyor belt motor
void stopMotor() {
  analogWrite(6, 0);          // Set motor speed to 0 (full stop)
}

void loop()
{
  // Read the photoresistor value (0–1023); lower value = beam is blocked
  sensorValue = analogRead(A0);

  // Read the current state of the blue LED (HIGH = object was just detected)
  ledState = digitalRead(3);

  // Belt logic based on object count:
  if (counter < 6) {
    forward();          // Fewer than 6 objects counted — move belt forward
    checkSensor();
  }
  else if (counter >= 5 && counter <= 15) {
    backward();         // Between 5 and 15 objects — reverse the belt
    checkSensor();
  }
  else {
    stopMotor();        // More than 15 objects — stop the belt
  }
}

// Reads sensor state and decides which action to take
void checkSensor() {
  if (sensorValue >= 300) {
    // High sensor value = beam is unobstructed = no object present
    noObject();
  }
  else if (sensorValue < 300 && ledState == 1) {
    // Low sensor value AND LED already on = object still blocking beam (don't double-count)
    objectHolding();
  }
  else {
    // Low sensor value AND LED was off = new object just detected
    objectDetected();
  }
}
