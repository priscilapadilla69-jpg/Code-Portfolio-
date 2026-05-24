#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char letter = 'a';

// Custom characters (8x5 pixel bitmaps)
byte exclamation[] = {
  B00000, B11111, B11111, B01110,
  B00100, B00000, B00100, B00000
};
byte letterI[] = {
  B00010, B00100, B00000, B00100,
  B00100, B00100, B00100, B00000
};
byte letterO[] = {
  B00010, B00100, B00000, B01110,
  B10001, B10001, B01110, B00000
};
byte smileyFace[] = {
  B00000, B00000, B01010, B00000,
  B10001, B01110, B00000, B00000
};
byte alien[] = {
  B01010, B01110, B11111, B10101,
  B11111, B01110, B00100, B00000
};
byte star[] = {
  B00100, B00100, B01010, B10001,
  B01010, B00100, B00100, B00100
};

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  showUniversity();
  showFaculty();
  showCareer();
  showFirstName();
  scrollLeft2();
  lcd.home();
  lcd.setCursor(0, 1);
  showLastName();
  scrollLeft2();
  lcd.clear();
  showDate();
  showTime();
  delay(3000);
  lcd.clear();
}

void showUniversity() {
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.createChar(0, exclamation);
  lcd.setCursor(1, 0);
  lcd.print("Universidad de");
  lcd.setCursor(2, 1);
  lcd.print("las Americas");
  lcd.setCursor(14, 1);
  lcd.write(byte(0));
  delay(1000);
  lcd.clear();
}

void showFaculty() {
  lcd.setCursor(0, 0);
  lcd.print("Facultad de Ingenier a");
  lcd.createChar(1, letterI);
  lcd.setCursor(20, 0);
  lcd.write(byte(1));
  lcd.setCursor(0, 1);
  lcd.print("y Ciencias Aplicadas");
  delay(1000);
  scrollLeft();
  lcd.clear();
}

void showCareer() {
  lcd.setCursor(0, 0);
  lcd.print("Ingenieria en Electronica");
  lcd.createChar(1, letterI);
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.createChar(2, letterO);
  lcd.setCursor(20, 0);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.print("y Automatizacion");
  lcd.setCursor(20, 1);
  lcd.write(byte(2));
  delay(1000);
  scrollLeft();
  lcd.clear();
}

// Scroll display left 23 positions
void scrollLeft() {
  for (int x = 0; x < 23; x++) {
    lcd.scrollDisplayLeft();
    delay(600);
  }
}

// Scroll display left 3 positions
void scrollLeft2() {
  for (int x = 0; x < 3; x++) {
    lcd.scrollDisplayLeft();
    delay(600);
  }
}

// Print first name letter by letter
void showFirstName() {
  const char* firstName = "Priscila";
  lcd.setCursor(0, 0);
  for (int i = 0; i < 8; i++) {
    lcd.print(firstName[i]);
    lcd.leftToRight();
    delay(150);
  }

  const char* middleName = "Carolina";
  lcd.setCursor(10, 0);
  for (int i = 0; i < 8; i++) {
    lcd.print(middleName[i]);
    lcd.leftToRight();
    delay(150);
  }
}

// Print last name letter by letter
void showLastName() {
  const char* lastName = "Padilla";
  for (int i = 0; i < 7; i++) {
    lcd.print(lastName[i]);
    lcd.leftToRight();
    delay(150);
  }

  const char* secondLastName = "Collaguazo";
  lcd.setCursor(9, 1);
  for (int i = 0; i < 10; i++) {
    lcd.print(secondLastName[i]);
    lcd.leftToRight();
    delay(150);
  }
}

// Display date with blinking effect
void showDate() {
  lcd.createChar(3, smileyFace);
  lcd.setCursor(0, 0);
  lcd.write(byte(3));
  lcd.setCursor(1, 0);
  lcd.print("01 de Enero");
  lcd.setCursor(2, 1);
  lcd.print("del 2021");
  lcd.setCursor(11, 1);
  lcd.write(byte(3));
  // Blink twice
  for (int i = 0; i < 2; i++) {
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
  }
  lcd.clear();
}

// Display time with decorative custom characters
void showTime() {
  lcd.createChar(4, alien);
  lcd.createChar(5, star);
  lcd.setCursor(5, 0);
  lcd.print("18:06 PM");
  lcd.setCursor(5, 1);
  lcd.print("18:06 PM");
  lcd.setCursor(0, 0);
  lcd.write(byte(4));  // Alien top-left
  lcd.setCursor(0, 1);
  lcd.write(byte(5));  // Star bottom-left
  lcd.setCursor(15, 1);
  lcd.write(byte(4));  // Alien bottom-right
  lcd.setCursor(15, 0);
  lcd.write(byte(5));  // Star top-right
}
