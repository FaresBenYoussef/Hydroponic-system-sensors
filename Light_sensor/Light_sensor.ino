// Define analog pin for sensor
#define SENSOR_PIN A3

// Variable to hold light value
int lightValue;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // No need to set pinMode for analog pins
}

void loop() {
  // Read light value from sensor
  lightValue = analogRead(SENSOR_PIN);

  // Print light value to serial monitor
  Serial.print("Light value: ");
  Serial.println(lightValue);

  // Delay for 500 milliseconds (0.5 seconds)
  delay(1000);
}

