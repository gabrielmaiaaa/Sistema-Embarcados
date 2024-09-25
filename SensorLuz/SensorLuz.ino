int pot = 3; // funcciona para ldr
int led = 5;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pot); //qtd bits por segundo

  delay(1000);

  Serial.print(valor);
  Serial.print(" = ");
  Serial.println(valor * 0.0049);
  if(valor > 160){ // 290
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
}
