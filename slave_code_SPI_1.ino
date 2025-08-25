#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN 7

volatile char rxBuf[64];
volatile uint8_t rxIdx = 0;
volatile bool lineReady = false;

ISR(SPI_STC_vect) {
  char c = SPDR;                     // byte received
  if (!lineReady) {                  // ignore if previous line not processed
    if (c == '\n') {
      if (rxIdx < sizeof(rxBuf)) rxBuf[rxIdx] = '\0';
      lineReady = true;
    } else if (rxIdx < sizeof(rxBuf) - 1) {
      rxBuf[rxIdx++] = c;
    } else {
      // overflow: reset safely
      rxIdx = 0;
    }
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  // ----- SPI slave init -----
  pinMode(MISO, OUTPUT);             // required in slave
  // Enable SPI + SPI interrupt + set slave mode (MSTR=0)
  SPCR = _BV(SPE) | _BV(SPIE);       // SPE: SPI enable, SPIE: interrupt enable
  // (MSTR bit is 0 by default -> slave)
  sei();                              // enable global interrupts
}

void loop() {
  if (lineReady) {
    digitalWrite(LED_PIN, HIGH);
    Serial.print("Received: ");
    Serial.println((char*)rxBuf);
    rxIdx = 0;
    lineReady = false;
    delay(200);
    digitalWrite(LED_PIN, LOW);
  }
}
