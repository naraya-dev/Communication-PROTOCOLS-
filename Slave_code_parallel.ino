// Data Pins
const int dataPins[8] = {3, 4, 5, 6, 7, 8, 9, 10};
#define STB 11
#define ACK 12
#define LED 13

void setup() {
  Serial.begin(9600);

  // Data pins as INPUT
  for (int i = 0; i < 8; i++) pinMode(dataPins[i], INPUT);

  pinMode(STB, INPUT);
  pinMode(ACK, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(ACK, LOW);
}

byte readByte() {
  // Wait for STB HIGH
  while (digitalRead(STB) == LOW);

  // Read data pins
  byte data = 0;
  for (int i = 0; i < 8; i++) {
    data |= (digitalRead(dataPins[i]) << i);
  }

  // Signal ACK HIGH
  digitalWrite(ACK, HIGH);

  // Wait for STB LOW
  while (digitalRead(STB) == HIGH);

  // Reset ACK
  digitalWrite(ACK, LOW);

  return data;
}

void loop() {
  byte start = readByte();
  if (start == 0xAA) {
    int temp = readByte();
    int hum = readByte();
    byte end = readByte();

    if (end == 0x55) {
      Serial.print("Received Temp: ");
      Serial.print(temp);
      Serial.print(" C, Humidity: ");
      Serial.print(hum);
      Serial.println(" %");

      // Blink LED when data received
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
    }
  }
}
