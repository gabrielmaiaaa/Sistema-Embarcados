// MESTRE
#include <Wire.h>

int SLAVE1 = 47;

int potenciometro = A0;
int valor;

void setup() {
  Wire.begin(); // iniciando o mestre
}

void loop() {
  valor = analogRead(potenciometro); // leitura

  // Envio do valor lido para o escravo
  Wire.beginTransmission( SLAVE1 );
  Wire.write(valor / 4);
  Wire.endTransmission();

  delay(50);
}