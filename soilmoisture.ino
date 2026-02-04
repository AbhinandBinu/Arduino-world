#define MOISTURE_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(MOISTURE_PIN);

  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue > 700) {
    Serial.println("Soil is DRY");
  }
  else if (moistureValue > 400) {
    Serial.println("Soil is MOIST");
  }
  else {
    Serial.println("Soil is WET");
  }

  delay(1000);
}