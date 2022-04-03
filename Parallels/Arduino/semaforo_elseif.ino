int red_led=1, yellow_led=2, green_led=3, button=4, orange_led=5, blue_led=6, semaforo, read_button, control_button, tempo_pisca, pisca;

void setup()
{
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(button, INPUT_PULLUP); //Sem resitor pulldown 10k ohms
  pinMode(orange_led, OUTPUT);
  pinMode(blue_led, OUTPUT);

  semaforo=1; //Estado em que o semafaro está
  control_button=digitalRead(button); //Lê como está o botão

  tempo_pisca=0;
  pisca=HIGH;
}

void loop()
{
  read_button=digitalRead(button); //Vê o estado anterior do botão
  
  if(read_button==HIGH) && (control_button==LOW){
    if(semaforo<3){
      semaforo=semaforo+1; //Contador para trocar o estado do semaforo
    }else{
    semaforo=1;
     }
  }
  control_button=read_button;
  
  if(semaforo==1){
    digitalWrite(red_led,LOW);
    digitalWrite(yellow_led,LOW);
    digitalWrite(green_led,HIGH);
    digitalWrite(orange_led,HIGH);
    digitalWrite(blue_led,LOW);
  }else if(semaforo==2){
    digitalWrite(red_led,LOW);
    digitalWrite(yellow_led,HIGH);
    digitalWrite(green_led,LOW);
    
    tempo_pisca++;
    if(tempo_pisca==400){
      pisca=!pisca;  //Inverte o valor
      tempo=0; //reseta o contador
    }
    
    digitalWrite(orange_led,pisca);
    digitalWrite(blue_led,LOW);
  }else if(semaforo==3){
    digitalWrite(red_led,HIGH);
    digitalWrite(yellow_led,LOW);
    digitalWrite(green_led,LOW);
    digitalWrite(orange_led,LOW);
    digitalWrite(blue_led,HIGH);
  }
  delay(1);
}
