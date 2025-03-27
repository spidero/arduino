#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "time.h"

struct tm timeinfo;
char czasStr[9]; 

// Adres LCD (sprawdź skanerem I2C, może być 0x27 lub 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define RELAY1 25  // Pin dla pierwszego przekaźnika
#define RELAY2 26  // Pin dla drugiego przekaźnika

void setup() {
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
    
    // Domyślnie wyłączamy przekaźniki
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, HIGH);

    struct tm t = {0};
    t.tm_year = 2024 - 1900; // Rok - 1900
    t.tm_mon  = 2 - 1;       // Miesiąc (0 = styczeń)
    t.tm_mday = 28;          // Dzień miesiąca
    t.tm_hour = 14;
    t.tm_min  = 30;
    t.tm_sec  = 0;

    time_t now = mktime(&t);
    struct timeval tv = { now, 0 };
    settimeofday(&tv, NULL);

    Wire.begin(21, 22); // Ustawienie pinów I2C (SDA = 21, SCL = 22)

    lcd.init();           // Inicjalizacja LCD
    lcd.backlight();      // Włączenie podświetlenia

    lcd.setCursor(0, 0);
    lcd.print("Duuuupa");

    lcd.setCursor(0, 1);
    lcd.print("Andrzej");
}

void loop() {
    //digitalWrite(RELAY1, HIGH); // Włącz przekaźnik 1
    //digitalWrite(RELAY2, LOW);  // Wyłącz przekaźnik 1

    // Efekt migania tekstu na drugim wierszu
    //delay(1000);

    //digitalWrite(RELAY1, LOW); // Włącz przekaźnik 2
    //digitalWrite(RELAY2, HIGH);  // Wyłącz przekaźnik 2

    getLocalTime(&timeinfo);
    snprintf(czasStr, sizeof(czasStr), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);


    //lcd.setCursor(0, 1);
    //lcd.print("                "); // Czyści drugi wiersz
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print(czasStr);
}
