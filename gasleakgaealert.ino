#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32   // use 64 if your display is 128x64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define MQ2_PIN A0
#define BUZZER_PIN 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("Air Quality System");
  display.setCursor(0, 12);
  display.println("Initializing...");
  display.display();

  delay(2000);
}

void loop() {
  int gasValue = analogRead(MQ2_PIN);

  Serial.print("MQ-2 Value: ");
  Serial.println(gasValue);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Air Quality: ");

  display.println(gasValue);
  // Air Quality Levels
  if (gasValue < 550) {
    display.setCursor(0, 16);
    display.println("Air: GOOD");
    noTone(BUZZER_PIN);
  }
  else if (gasValue < 700) {
    display.setCursor(0, 16);
    display.println("Air: MODERATE");
    tone(BUZZER_PIN, 1000);
    delay(200);
    noTone(BUZZER_PIN);
  }
  else {
    display.setCursor(0, 16);
    display.println("Air: POOR!");
    tone(BUZZER_PIN, 2000);
  }

  display.display();
  delay(500);
}
