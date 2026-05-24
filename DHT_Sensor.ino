#include <DHT.h>// Incluimos librería
#define DHTPIN A0 // Definimos el pin digital donde se conecta el sensor
#define DHTTYPE DHT11 // Dependiendo del tipo de sensor
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
 Serial.begin(9600);
  // Comenzamos el sensor DHT
  dht.begin();
  
}
void loop() {
      // Esperamos 5 segundos entre medidas
  delay(1000);
   
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();

  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
  Serial.print("HR(%):");
  Serial.print(h);
  Serial.print("Temp:");
  Serial.print(t);
  Serial.print(" *C ");

 
}
