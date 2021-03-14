#include <Arduino.h>
#include "DHT.h"

// Digital pin connected to the DHT sensor
#define DHTPIN 2

// Type of sensor
#define DHTTYPE DHT11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humidity = dht.readHumidity();

  // Read temperature as Celsius (the default)
  float tempCelsius = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(tempCelsius)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float heatIndex = dht.computeHeatIndex(tempCelsius, humidity, false);

  Serial.print(F("Humidity (%): "));
  Serial.println(humidity);

  Serial.print(F("Temp. (ºC): "));
  Serial.println(tempCelsius);

  Serial.print(F("Heat index (°C): "));
  Serial.println(heatIndex);

  Serial.println("---------");
}