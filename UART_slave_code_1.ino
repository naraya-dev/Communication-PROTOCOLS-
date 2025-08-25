const int LED = 13;
String data = "";

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      Serial.print("Received: ");
      Serial.println(data);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      data = "";
    } else {
      data += c;
    }
  }
}
