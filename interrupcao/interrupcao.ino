int btInt = 2;
int x = 0;

volatile int printar = 1;

// handler da interrupção
// sem parametros, sem retorno
void tratamento()
{
  Serial.println("interrupacao!!");
  printar = !printar;
}

void setup()
{
  attachInterrupt(digitalPinToInterrupt(btInt), tratamento, RISING);
  Serial.begin(9600);
}

void loop()
{
  if(printar){
    Serial.println(x);
    x++;
  }
  delay(1000);
}