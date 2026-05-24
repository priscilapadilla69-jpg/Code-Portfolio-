#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9,8);
int res = 0;        // variable entera para indicar la resistencia
int counter = 0;   // variable entera para contar los objetos
int LED_state = 0; // variable para definir el estado binario del LED Azul

 void setup()
{
  pinMode(3,OUTPUT); // Entrada del LED Azul
  pinMode(6,OUTPUT);//velocidad
  pinMode(4,OUTPUT);//giro
  pinMode(2,OUTPUT);//giro
  
  lcd.begin(16,2); // Columnas x Filas
  lcd.setCursor(0,1);
  lcd.print("Objetos:");
}

void Count_object(){ // Este void es cuando un objeto atraviesa el haz del laser
  digitalWrite(3,HIGH);
    lcd.setCursor(9,1);
    lcd.print(counter);// Imprimir el numero de ojetos en pantalla LDC
    counter = counter +1;
    delay(50);
}
void No_object(){ // Este void es para cuando no hay una interrupcion del haz del laser
   digitalWrite(3,LOW);
    lcd.setCursor(9,1);
    lcd.print(counter);// Imprimir el numero de ojetos en pantalla LDC
    counter = counter;
    delay(50);
}
void Dont_count(){ // Este void es para cuando el objeto se mantiene interrumpiendo el haz del laser
  digitalWrite(3,HIGH);
     lcd.setCursor(9,1);
     lcd.print(counter);// Imprimir el numero de ojetos en pantalla LDC
    counter = counter;
    delay(50);
}
void adelante(){
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    analogWrite(6, 140);
}
void atras(){
   digitalWrite(4, HIGH);
   digitalWrite(2, LOW);
   analogWrite(6, 140);
}
void stop(){
  analogWrite(6,0);
}

void loop()
{
  res = analogRead(A0);// se digitaliza y se convierte
                           // en un numero binario
  LED_state = digitalRead(3); // Definir el estado del led de manera binaria
                              // para asi poder comparar valores
 if(counter<6){
  adelante();
  first(); 
 }
 else if (counter>=5 & counter<=15){
  atras();
  first();
 }
 else{
  stop();
 }
}

void first(){
  if (res >=300){ // Si la resistencia es (res >=60) ejecutar void No_object
    No_object(); 
  }
  
  else if (res < 300 & LED_state == 1) { // Si res < 60 y el LED esta encendido
   Dont_count();                        // entonces ejercutar void Dont_count
  }                                                       
  
  else {
   Count_object(); 
  }
}
