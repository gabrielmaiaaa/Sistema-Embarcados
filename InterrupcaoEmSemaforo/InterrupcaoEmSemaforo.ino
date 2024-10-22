int btInt = 2;
int x = 0;

int ledVermelhoPedestre = 6;
int ledVerdePedestre = 7;
int ledVermelhoCarro = 5;
int ledAmareloCarro = 4;
int ledVerdeCarro = 3;

volatile int liberarPedestre = 1;

// handler da interrupção
// sem parametros, sem retorno
void liberaPedestre()
{
  Serial.println("interrupacao!!");
  liberarPedestre = !liberarPedestre;
}

void alterarSemaforoCarro()
{
  digitalWrite(ledVerdePedestre, LOW);
  digitalWrite(ledVermelhoPedestre, HIGH);
  digitalWrite(ledVermelhoCarro, HIGH);
  digitalWrite(ledVerdeCarro, LOW);
  delay(1000);
  digitalWrite(ledAmareloCarro, HIGH);
  digitalWrite(ledVermelhoCarro, LOW);
  delay(1000);
  digitalWrite(ledVerdeCarro, HIGH);
  digitalWrite(ledAmareloCarro, LOW);
  delay(1000);
}

void fecharSemaforoCarro()
{
  digitalWrite(ledVerdeCarro, LOW);
  digitalWrite(ledVermelhoCarro, LOW);
  digitalWrite(ledAmareloCarro, LOW);
}

void abrirPedrestre()
{
  digitalWrite(ledVerdePedestre, HIGH);
  digitalWrite(ledVermelhoPedestre, LOW);
  delay(2000);
}

void setup()
{
  pinMode(ledVermelhoPedestre, OUTPUT);
  pinMode(ledVerdePedestre, OUTPUT);
  pinMode(ledVermelhoCarro, OUTPUT);
  pinMode(ledAmareloCarro, OUTPUT);
  pinMode(ledVerdeCarro, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(btInt), liberaPedestre, RISING);
  Serial.begin(9600);
}

void loop()
{
  if(liberarPedestre){
    alterarSemaforoCarro();
  }else{
    fecharSemaforoCarro();
    abrirPedrestre();
    liberarPedestre = !liberarPedestre;
  }
  delay(1000);
}