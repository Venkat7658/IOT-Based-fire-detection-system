#include <LiquidCrystal_I2C.h>

// Pin Definitions
#define smoke_sensor A0
#define fire_sensor 8
#define buzzer 9

// LCD Initialization
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(fire_sensor, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  // Intro Display
  lcd.setCursor(0, 0);
  lcd.print(" FIRE AND SMOKE ");
  lcd.setCursor(0, 1);
  lcd.print("DETECTION SYSTEM");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" USING ARDUINO ");
  delay(2000);
  lcd.clear();
}

void loop() {
  int smoke = analogRead(smoke_sensor);
  bool fire = !digitalRead(fire_sensor);  // Flame sensor is active LOW

  Serial.print("Smoke level: ");
  Serial.println(smoke);

  lcd.setCursor(0, 0);
  lcd.print("SMOKE:         ");
  lcd.setCursor(8, 0);

  if (smoke <= 450) {
    lcd.print("LOW    ");
  } else if (smoke > 450 && smoke < 500) {
    lcd.print("MEDIUM ");
  } else {
    lcd.print("HIGH   ");
  }

  lcd.setCursor(0, 1);

  if (fire) {
    lcd.print("FIRE DETECTED  ");
    digitalWrite(buzzer, HIGH);
  } else {
    lcd.print("NO FIRE DETECTED");
    if (smoke <= 450) {
      digitalWrite(buzzer, LOW);
    } else if (smoke > 450 && smoke < 500) {
      for (int i = 0; i < 2; i++) {
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(500);
      }
    } else {
      digitalWrite(buzzer, HIGH);
    }
  }

  delay(500);
}
