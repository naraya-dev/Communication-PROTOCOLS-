#include <SPI.h>

const int SS_PIN = 10;

void setup() {
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);     // deselect slave
  SPI.begin();                    // Master mode
}

void loop() {
  const char *msg = "Hello SPI\n";

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); // 1 MHz, mode 0
  digitalWrite(SS_PIN, LOW);       // select slave
  for (const char *p = msg; *p; ++p) {
    SPI.transfer((uint8_t)*p);
  }
  digitalWrite(SS_PIN, HIGH);      // deselect slave
  SPI.endTransaction();

  delay(500);
}
