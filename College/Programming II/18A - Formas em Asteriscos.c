#include <stdio.h>

#define TAMANHO 5
void inverter(int x, int vetor[]);
void quadrado(int tamanho);
void triangulo(int tamanho);

int main(void) {

	quadrado(TAMANHO);
	triangulo(TAMANHO);
  int vetor[TAMANHO];
	for (int i = 0; i < TAMANHO;i++){
			printf("informe valores: \n");
			scanf("%d",&vetor[i]);
	}
  inverter(TAMANHO, vetor);
  return 0;
}

void quadrado(int tamanho){
  for(int j = 0; j < tamanho; j++){
		for(int i = 0; i < tamanho; i++){
			printf(" *");
		}
   printf("\n"); 
  }
}

void triangulo(int tamanho){
	for(int i = 0; i < tamanho; i++){
    for(int j = 0; j <= i; j++){
			printf("* ");
    }
    puts(" ");
  }
}

void inverter(int x, int *vetor){
	int aux;
	int fim = x - 1;
	for(int j = 0 ; j < x  / 2; j++){
  	aux = vetor[j];
    vetor[j] = vetor[fim-j];
    vetor[fim-j]=aux;
	}
	for(int i = 0; i < x; i++){
		printf("V[%d] = %d ", i, vetor[i]);
	}
}

/*
[0] [1] [2] [3] [4] [5]
 2   4   6   8   9   3

 1. V[0] <- V[5], V[5] <- V[0]
 2. V[1] <- V[4], V[4] <- V[1]
 3. V[2] <- V[3], V[3] <- V[2]

* * * * *
* * * * *
* * * * * 
* * * * * 

*
* *
* * *
* * * *
* * * * *


void inverter(int x, int *vetor);
int main(int argc, char** argv) {
    int tamanho=0;
    int vetor[tamanho];
    printf("informe o tamanho do vetor:\n ");
    scanf("%d",&tamanho);
    for (int i=0;i<tamanho;i++){
        printf("informe valores: \n");
        scanf("%d",&vetor[i]);
    }
    inverter(tamanho,vetor);
    
    
    return 0;
}
void inverter(int x, int *vetor){
for(int j=x-1;j>=0;j--){
        printf("%d",vetor[j]);
    }
}
*/








/*
if for while
v[]

operadores relacionasi
> >= < <=
== !=



operadores lógicos:
&& || !

loop

contador
#define TAMANHO 10

for (int i = 0; i < TAMANHO; I++){

}

sentinela

while (continua != '0'){
	scanf("%c", &continua);
	..
}


'a' 'z'

Hoje é dia 03/12/2020.

while(!feof(arquivo)){
	fscan();
	if((caracterLido >= 'A' && caracterLido <= 'Z') || 
	   (caracterLido >= 'a' && caracterLido <= 'z') || (caracterLido == ' ')){
		strLida[i] = ...
	}
}
caracterLido
---------
|   H   |
---------

destino
Hojedia


m[i][j] = i + j

cont

m[i][j] = cont;
printf(ss, ee)
cont++;

*/