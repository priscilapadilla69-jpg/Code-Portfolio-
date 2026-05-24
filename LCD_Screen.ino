#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
char letter = 'a';
byte excla[] = {
  B00000,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00100,
  B00000
 };
byte i[] = {
  B00010,
  B00100,
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000
};
byte o[] = {
  B00010,
  B00100,
  B00000,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000
};
byte smile[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
byte ant[] = {
  B01010,
  B01110,
  B11111,
  B10101,
  B11111,
  B01110,
  B00100,
  B00000
};
byte star[] = {
  B00100,
  B00100,
  B01010,
  B10001,
  B01010,
  B00100,
  B00100,
  B00100
};
void setup() {
  lcd.begin(16, 2);  
}
void loop () {
  uni();
  
  faculty();
  
  career();
  
  nam();
  left2();
  lcd.home();
  lcd.setCursor(0,1);
  last();
  left2();
  lcd.clear();
  
  date();

  hour();
  delay(3000);

  lcd.clear();
  }
 void uni(){
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.createChar(0, excla);
  lcd.setCursor(1,0);
  lcd.print("Universidad de");
  lcd.setCursor(2,1);
  lcd.print("las Americas");
  lcd.setCursor(14,1);
  lcd.write(byte(0));
  delay(1000);
  lcd.clear();
 }
 void faculty(){ 
  lcd.setCursor(0,0);
  lcd.print("Facultad de Ingenier a");
  lcd.createChar(1, i);
  lcd.setCursor(20,0);
  lcd.write(byte(1));
  lcd.setCursor(0,1);
  lcd.print("y Ciencias Aplicadas");
  delay(1000);
  left();
  lcd.clear();
 }
 void career(){
  lcd.setCursor(0,0);
  lcd.print("Ingenier a en Electr nica");
  lcd.createChar(1, i);
  lcd.setCursor(8,0);
  lcd.write(byte(1));
  lcd.createChar(2, o);
  lcd.setCursor(20,0);
  lcd.write(byte(2));
  lcd.setCursor(6,1);
  lcd.print("y Automatizaci n");
  lcd.setCursor(20,1);
  lcd.write(byte(2));
  delay(1000);
  left();
  lcd.clear();
 }
void left(){
   for (int x = 0; x < 23; x++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    delay(600);
  }
}

void left2(){
   for (int x = 0; x < 3; x++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    delay(600);
  }
}

void nam(){
 lcd.setCursor(0,0);
 lcd.print('P');
 lcd.leftToRight();
 delay(150);
 lcd.print('r');
 lcd.leftToRight();
 delay(150);
 lcd.print('i');
 lcd.leftToRight();
 delay(150);
 lcd.print('s');
 lcd.leftToRight();
 delay(150);
 lcd.print('c');
 lcd.leftToRight();
 delay(150);
 lcd.print('i');
 lcd.leftToRight();
 delay(150);
 lcd.print('l');
 lcd.leftToRight();
 delay(150);
 lcd.print('a');
 
 lcd.setCursor(10,0);
 lcd.print('C');
 lcd.leftToRight();
 delay(150);
 lcd.print('a');
 lcd.leftToRight();
 delay(150);
 lcd.print('r');
 lcd.leftToRight();
 delay(150);
 lcd.print('o');
 lcd.leftToRight();
 delay(150);
 lcd.print('l');
 lcd.leftToRight();
 delay(150);
 lcd.print('i');
 lcd.leftToRight();
 delay(150);
 lcd.print('n');
 lcd.leftToRight();
 delay(150);
 lcd.print('a');
}

 void last(){
 lcd.print('P');
 lcd.leftToRight();
 delay(150);
 lcd.print('a');
 lcd.leftToRight();
 delay(150);
 lcd.print('d');
 lcd.leftToRight();
 delay(150);
 lcd.print('i');
 lcd.leftToRight();
 delay(150);
 lcd.print('l');
 lcd.leftToRight();
 delay(150);
 lcd.print('l');
 lcd.leftToRight();
 delay(150);
 lcd.print('a');
 
 lcd.setCursor(9,1);
 lcd.print('C');
 lcd.leftToRight();
 delay(150);
 lcd.print('o');
 lcd.leftToRight();
 delay(150);
 lcd.print('l');
 lcd.leftToRight();
 delay(150);
 lcd.print('l');
 lcd.leftToRight();
 delay(150);
 lcd.print('a');
 lcd.leftToRight();
 delay(150);
 lcd.print('g');
 lcd.leftToRight();
 delay(150);
 lcd.print('u');
 lcd.leftToRight();
 delay(150);
 lcd.print('a');
 lcd.leftToRight();
 delay(150);
 lcd.print('z');
 lcd.leftToRight();
 delay(150);
 lcd.print('o');
 }
 void date(){
  lcd.createChar(3, smile);
  lcd.setCursor(0,0);
  lcd.write(byte(3));
  lcd.setCursor(1,0);
  lcd.print("01 de Enero");
  lcd.setCursor(2,1);
  lcd.print("del 2021");
  lcd.setCursor(11,1);
  lcd.write(byte(3));
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  lcd.clear();
 }
 void hour(){
  lcd.createChar(4, ant);
  lcd.createChar(5, star);
  lcd.setCursor(5,0);
  lcd.print("18:06 PM");
  lcd.setCursor(5,1);
  lcd.print("18:06 PM");
  
  lcd.setCursor(0,0);
  lcd.write(byte(4));
  
  lcd.setCursor(0,1);
  lcd.write(byte(5));
  
  lcd.setCursor(15,1);
  lcd.write(byte(4));
  
  lcd.setCursor(15,0);
  lcd.write(byte(5));
 }
