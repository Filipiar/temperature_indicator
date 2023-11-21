const int analogInPin = A0;            // Analog input pin for the voltage divider
float knownResistor = 350.0;           // Replace with the actual resistance of the known resistor in ohms

// Steinhart-Hart coefficients for the thermistor
float A = 1.009249522e-03;
float B = 2.378405444e-04;
float C = 2.019202697e-07;

// Calibration values
const float calibrationResistance = 380.0;  // Replace with the actual resistance at a known temperature
const float calibrationTemperature = 20.0;    // Replace with the known temperature in Celsius

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(analogInPin); // Read the analog input

  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog value to voltage
  float resistance = (voltage * knownResistor) / (5.0 - voltage); // Calculate the unknown resistor value

  // Recalculate Steinhart-Hart coefficients based on calibration
  A = 1.009249522e-03;
  B = 2.378405444e-04;
  C = 2.019202697e-07;

  // Calculate temperature using the adjusted coefficients
  float temperatureC = 1.0 / (A + B * log(resistance) + C * pow(log(resistance), 3));

  // Offset the temperature based on calibration
  temperatureC -= calibrationTemperature;

  // Add a fixed offset of -575°C
  temperatureC -= 575.0;

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print("\tVoltage: ");
  Serial.print(voltage);
  Serial.print(" V\tResistance: ");
  Serial.print(resistance);
  Serial.println(" ohms");

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000); // Wait for a second (adjust as needed)
}
