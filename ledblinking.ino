void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);  // LED ON
  delay(100);                  // wait 1 second
  digitalWrite(8, LOW);   // LED OFF
  delay(100);                  // wait 1 second
}
