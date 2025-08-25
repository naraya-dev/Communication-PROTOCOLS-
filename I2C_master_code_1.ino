#include <Wire.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Wire.begin(); 
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    Wire.beginTransmission(8); // Slave address
    Wire.print("T:");
    Wire.print(temp);
    Wire.print(" H:");
    Wire.print(hum);
    Wire.endTransmission();
  }
  delay(2000);
}
