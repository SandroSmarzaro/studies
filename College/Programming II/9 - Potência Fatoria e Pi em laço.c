#include <stdio.h>

int powerPii(int x, int y);
int fatorial(int x);
float piPii(int precisao);

/*
      4     4     4
pi = --- - --- + --- - ...
      1     3     5



*/



int main(void) {
	int a;
	int b;

  //Potencia
  printf("\nEntre com um valor para a: ");
	scanf("%d", &a);
	printf("\nEntre com um valor para b: ");
  scanf("%d", &b);
  printf("%d ^ %d  = %d", a, b, powerPii(a, b));
  //fatorial

  printf("\nDigite um X para Calculo de Fatorial: ");
  scanf("%d", &a);
  printf("Fatorial de %d = %d \n", a, fatorial(a));
 
	printf("\nPrecisão para PI: ");
  scanf("%d", &a); 
  
	printf("Pi = %f", piPii(a)); // precisão de saída
  return 0;
}

int powerPii(int x, int y){
  int pot = 1;
  for(int i = 0; i < y; i++){
    pot *= x;
  }
  return pot;
}

/*
	0! = 1
	1! = 1
	2! = 2 * 1! = 2
	3! = 3 * 2! = 6

*/

int fatorial(int x){
  int num = 1;
  for(int i = num; i <= x; i++){
    num = num * i;
  }
  return num;
}

float piPii(int precisao){
	int sinal = 1;
	float pi = 0;
	for(int i = 1; i <= precisao; i += 2){
    pi += 4 / (float) i * sinal; 
    sinal *= -1;
  }
	
  return pi;
}


/*
      4     4     4
pi = --- - --- + --- - ...
      1     3     5



*/

	