void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, INPUT_PULLUP); //Sem resitor pulldown 10k ohms
}

void loop()
{
  int botao=digitalRead(4);
  
  digitalWrite(1, botao);
  digitalWrite(2, !botao);
}
