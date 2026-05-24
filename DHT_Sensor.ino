#include <DHT.h> // Include DHT library

#define DHTPIN A0       // Pin where the sensor is connected
#define DHTTYPE DHT11   // Sensor type

// Initialize the DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  // Start the DHT sensor
  dht.begin();
}

void loop() {
  // Wait 1 second between readings
  delay(1000);

  // Read relative humidity
  float humidity = dht.readHumidity();
  // Read temperature in Celsius (default)
  float temperature = dht.readTemperature();

  // Check for reading errors
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Could not read data from DHT11 sensor");
    return;
  }

  Serial.print("RH(%):");
  Serial.print(humidity);
  Serial.print(" Temp:");
  Serial.print(temperature);
  Serial.print(" *C ");
}
