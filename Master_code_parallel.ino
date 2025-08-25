#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Data Pins
const int dataPins[8] = {3, 4, 5, 6, 7, 8, 9, 10};
#define STB 11
#define ACK 12

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Set data pins as OUTPUT
  for (int i = 0; i < 8; i++) pinMode(dataPins[i], OUTPUT);

  pinMode(STB, OUTPUT);
  pinMode(ACK, INPUT);

  digitalWrite(STB, LOW);
}

void sendByte(byte data) {
  // Put data on pins
  for (int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], (data >> i) & 0x01);
  }

  // Signal STB HIGH
  digitalWrite(STB, HIGH);

  // Wait for ACK HIGH from slave
  while (digitalRead(ACK) == LOW);

  // Reset STB
  digitalWrite(STB, LOW);

  // Wait for ACK LOW (handshake complete)
  while (digitalRead(ACK) == HIGH);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    Serial.print("Sending Temp: ");
    Serial.print(temp);
    Serial.print(" Humidity: ");
    Serial.println(hum);

    // Convert to integers for simplicity
    int t = (int)temp;
    int h = (int)hum;

    // Send message: Header + Temp + Humidity
    sendByte(0xAA); // Start byte
    sendByte(t);
    sendByte(h);
    sendByte(0x55); // End byte
  }

  delay(2000);
}
