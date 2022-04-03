/*

 	bubble sort - implementado em sala

*/

#include <stdio.h>
#define TAMANHO 10

void bubbleSort(int *vetor, int tamanho, int ordem);
void imprime(int vetor[], int tamanho);
void trocaValores(int *v1, int *v2);
int decrescente(int a, int b);

int main(void) {         
	int vetor[TAMANHO] = {10, 9, 9, 0, -2, 2, 4, 7, 8, 10};
  int ordem;
	printf("\n1 crescente | 0 para decrescente\n");
	do{
  	scanf("%d", &ordem);
	} while(ordem > 1 || ordem < 0);
	puts("Vetor Original");
	imprime(vetor, TAMANHO);
  bubbleSort(vetor, TAMANHO, ordem);
	puts("Em ordem");
  imprime(vetor, TAMANHO);
  return 0;
}

void bubbleSort(int *vetor, int tamanho, int ordem){
  if(ordem == 1){
    for(int i = 0; i < tamanho - 1; i++){
      for(int j = 0; j < tamanho - i - 1; j++){
        if(vetor[j] > vetor[j + 1]){
          trocaValores(&vetor[j], &vetor[j + 1]);
        }
      }
    }
  } else{
    for(int i = 0; i < tamanho - 1; i++){
      for(int j = 0; j < tamanho - i - 1; j++){
        if(decrescente(vetor[j], vetor[j + 1])){
          trocaValores(&vetor[j], &vetor[j + 1]);
        }
      }
    }
  }
} 

void trocaValores(int *v1, int *v2){
  int aux = *v1;
  *v1 = *v2;
  *v2 = aux;
}

void imprime(int vetor[], int tamanho){
	for(int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
  }
  puts("");
}

int decrescente(int a, int b){
  return a < b;
}

/* era assim
	if (a < b){   
		return 1;
	} else {
		return 0;
	}
*/


/* 

1. 
Faça um programa que leia um vetor de inteiros e seu tamanho e imprima uma mensagem, informando se o vetor está ordenado de forma crescente ou não está ordenado

2.
Faca um programa que leia uma seqüência de 100 números da entrada padrão de forma desordenada. O programa deve imprimir, após a leitura, os números que se repetiram na seqüência, informando quantos vezes cada um deles apareceu.

3.	
Faça um programa que leia dois vetores ordenados, de 100 posições cada, e gere um terceiro vetor, também ordenado, com todos os elementos dos vetores anteriores.
Exemplo para vetores de 5 posições:
entrada: 	v1 = {1, 4, 5, 9, 111}
					v2 = (3, 3, 5, 8, 300}
saída:	v3 = {1, 3, 3, 4, 5, 5, 8, 9, 111, 300}

4.
Faça um programa que leia uma seqüência de números reais terminada por 0 (zero) (com, no máximo, 1000 números diferentes), e imprima o número de maior ocorrência. Note que pode-se ter mais do que 1000 números na entrada padrão de dados.


   *           *
  [ ][ ][ ][ ][ ]
	*crescente
	[            ]()()
aasdfasdfa	*&%&ˆ%ˆ&
	*decrescente
	[            ]()()


   0 -> Falso
	 1 -> Verdadeiro
	 

	 * e 
	 + ou



  i = 0 
   
	tam = 6;  tam - 1 = 5
	[0][1][2][3][4][5] 
   2  9  3  1  5  4  -> j = 0 -> (tam -i - 1) -> 6 - 0 - 1 = 5 =>j vai até 4
	  | 
   2  9  3  1  5  4
        |
   2  3  9  1  5  4
	         |
	 2  3  1  9  5  4
	           |
	 2  3  1  5  9  4
	              |
   2  3  1  5  4  9

// i = 1
----------------
  (2  1)  3  5 4 9 -> j = 0 -> (tam - i - 1) -> 6 - 1 - 1 = 5 =>j vai até 3
	  |
   2 (1 3) 5 4 9 -> j = 1
				 |
	 2  1 (3 4 )5 9 -> j = 2
	


*/

