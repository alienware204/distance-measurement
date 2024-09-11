#include <LiquidCrystal.h>

// Define the LCD object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define the pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);

  // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set up the serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration from the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters (you can change this for inches)
  float distance_cm = duration * 0.034 / 2;

  // Display the distance on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance_cm);
  lcd.print(" cm");

  // Print the distance to the serial monitor (optional)
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Add a delay before taking the next measurement
  delay(1000); // You can adjust this delay as needed
}