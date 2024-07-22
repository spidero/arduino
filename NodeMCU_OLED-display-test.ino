#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definiowanie rozmiarów wyświetlacza OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Definiowanie pinów SDA i SCL

#define OLED_SDA 14
#define OLED_SCL 12

// Adres I2C wyświetlacza OLED
#define OLED_ADDR   0x3C

// Tworzenie obiektu dla wyświetlacza z wartością -1 dla OLED_RESET
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Inicjalizacja komunikacji I2C z wyświetlaczem
  Wire.begin(OLED_SDA, OLED_SCL);

  // Inicjalizacja wyświetlacza
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Wyczyść bufor
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);

  // Wyświetlenie tekstu
  display.println("==========");
  display.println("Display");
  display.println("TEST");
  display.println("==========");


  // Wyświetlenie bufora na ekranie
  display.display();
}

void loop() {
    
}
