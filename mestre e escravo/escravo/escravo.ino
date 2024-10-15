// ESCRAVO
#include <Wire.h>

int SLAVE1 = 47;

int led = 9;
int volatile valor;

void atualizaValor(int x){
  if(Wire.available()){
    valor = Wire.read();
  }
}

void setup() {
  pinMode(led, OUTPUT);
  
  Wire.begin(47); // iniciando o escravo: id = 47
  Wire.onReceive( atualizaValor );
}

void loop() {
  analogWrite(led, valor);

  delay(10);
}
