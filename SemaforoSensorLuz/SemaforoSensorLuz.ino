int ldr = A3; // funcciona para ldr
int ledVerde = 7;
int ledAmarelo = 9;
int ledVermelho = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  int luz = analogRead(ldr); //qtd bits por segundo
  Serial.println(luz);

  delay(1000);

  if(luz > 160){
      digitalWrite(ledVerde, HIGH);
      delay(1000);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, HIGH);
      delay(500);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, HIGH);
      delay(1000);
      digitalWrite(ledVermelho, LOW);
  }else{
    digitalWrite(ledAmarelo, HIGH);
    delay(250);
    digitalWrite(ledAmarelo, LOW);
  }



}
