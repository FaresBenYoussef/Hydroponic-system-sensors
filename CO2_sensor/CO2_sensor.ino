void setup() {
  Serial.begin(9600);
}

float min_voltage = 0.0;   // Minimum voltage the sensor outputs (0 ppm CO2)
float max_voltage = 5.0;   // Maximum voltage the sensor outputs (5000 ppm CO2)
float min_co2 = 0;         // Minimum CO2 concentration in ppm
float max_co2 = 5000;      // Maximum CO2 concentration in ppm

float voltage_to_co2(float voltage) {
    // Linear interpolation between min_co2 and max_co2
    float slope = (max_co2 - min_co2) / (max_voltage - min_voltage);
    float intercept = min_co2 - slope * min_voltage;
    float co2 = slope * voltage + intercept;
    return co2;
}

void loop() {
  // Reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A2);

  // Convert the analog value to voltage (0-5V range)
  float voltage = analogValue * (5.0 / 1023.0);

  // Convert voltage to CO2 concentration
  float co2_concentration = voltage_to_co2(voltage);

  // Print the result
  Serial.print("Analog reading = ");
  Serial.print(analogValue);
  Serial.print(" (");
  Serial.print(voltage);
  Serial.print(" V) - CO2 concentration = ");
  Serial.print(co2_concentration);
  Serial.println(" ppm");

  delay(1000);
}

