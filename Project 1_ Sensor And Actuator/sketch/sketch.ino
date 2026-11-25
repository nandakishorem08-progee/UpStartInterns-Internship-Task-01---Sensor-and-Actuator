#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22
#define LED_PIN 8
#define THRESHOLD_C 35.0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Sensor read failed");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");

    digitalWrite(LED_PIN, temp > THRESHOLD_C ? HIGH : LOW);
  }

  delay(2000); 
}