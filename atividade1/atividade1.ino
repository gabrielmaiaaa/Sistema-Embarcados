int ledVerde = 7; // porta onde está conectado
int ledAmarelo = 8;
int ledVermelho = 9;
int botaoA = 10;
int botaoB = 11;
int pedVerde = 12;
int pedVermelho = 13;
int pedAmarelo = 6;
int estado = 0;

void setup() {
  // informar que a porta 7 eh uma saida digital
  pinMode(ledVerde, OUTPUT); // porta, tipo (INPUT / OUTPUT)
  pinMode(ledAmarelo, OUTPUT); // porta, tipo (INPUT / OUTPUT)
  pinMode(ledVermelho, OUTPUT); // porta, tipo (INPUT / OUTPUT)
  pinMode(pedVermelho, OUTPUT); // porta, tipo (INPUT / OUTPUT)
  pinMode(pedVerde, OUTPUT); // porta, tipo (INPUT / OUTPUT)
  pinMode(botaoA, INPUT);
  pinMode(botaoB, INPUT);
}

void loop() {
  // flipflop
  int A = digitalRead(botaoA); // parta a ser lida
  int B = digitalRead(botaoB); // parta a ser lida
  delay(20);
  
  if(A == HIGH || estado == 1){
    // colocar 5V na porta do led
    estado = 1;
    digitalWrite(ledVermelho, HIGH); // porta, tipo (INPUT / OUTPUT)
    digitalWrite(pedVerde, HIGH); // porta, tipo (INPUT / OUTPUT)
    delay(2000);
    digitalWrite(ledVermelho, LOW); // porta, tipo (INPUT / OUTPUT)
    digitalWrite(pedVerde, LOW); // porta, tipo (INPUT / OUTPUT)
    digitalWrite(ledVerde, HIGH); // porta, nível lógico (HIGH / HIG
    digitalWrite(pedVermelho, HIGH); // porta, tipo (INPUT / OUTPUT)
    delay(2000);
    digitalWrite(ledVerde, LOW); // porta, nível lógico (HIGH / HIG
    digitalWrite(pedVermelho, LOW); // porta, tipo (INPUT / OUTPUT)vv
    digitalWrite(ledAmarelo, HIGH); // porta, nível lógico (HIGH / LOW)
    digitalWrite(pedAmarelo, HIGH); // porta, nível lógico (HIGH / LOW)
    delay(2000);
    digitalWrite(ledAmarelo, LOW); // porta, nível lógico (HIGH / LOW)
    digitalWrite(pedAmarelo, LOW); // porta, nível lógico (HIGH / LOW)
  }
  if(B == HIGH || estado == 0){
    estado = 0;
    digitalWrite(ledVermelho, LOW); // porta, tipo (INPUT / OUTPUT)
    digitalWrite(ledVerde, LOW); // porta, tipo (INPUT / OUTPUT)
    digitalWrite(ledAmarelo, LOW); // porta, nível lógico (HIGH / LOW)
    digitalWrite(pedVermelho, LOW); // porta, tipo (INPUT / OUTPUT)
    digitalWrite(pedVerde, LOW); // porta, tipo (INPUT / OUTPUT)
    digitalWrite(pedAmarelo, LOW); // porta, nível lógico (HIGH / LOW)
  }
    
}
