int pot = 3;
int led = 6;

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  int valor = analogRead(pot);
  delay(10);

  analogWrite(led, valor/4);
}
