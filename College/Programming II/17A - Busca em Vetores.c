#include <stdio.h>
#define TAM 5

void verificar(int *vetA, int *vetB, int *vetC, int valor);

int main(void) {
  int vetA[TAM]={0, 1, 2, 3, 4};
  int vetB[TAM]={4, 1, 6, 7, 8};
  int vetC[TAM]={8, 1, 10, 11, 12};
  int valor;
  
  printf("informe o valor que deseja verificar: ");
  scanf("%d", &valor);
  verificar(vetA, vetB, vetC, valor);
  return 0;
}

void verificar(int *vetA, int *vetB, int *vetC, int valor){
  int flagA;
  int flagB = 0;
  int flagC = 0;
	int posicao = 0;

  while(posicao++ < TAM && vetA[posicao] != valor);
	printf("\nvet[%d] = %d\n",posicao, vetA[posicao]);
	flagA = (posicao == TAM + 1) ? 0 : 1;
	
  posicao = 0;
  while(posicao < TAM && flagB == 0){
    if(vetB[posicao] == valor){
      flagB = 1;
    }else{
      posicao++;
    }
  }

  posicao = 0;
  while(posicao < TAM && flagC == 0){
    if(vetC[posicao] == valor){
      flagC = 1;
    }else{
      posicao++;
    }
  }
	
  if((flagA == 1) && (flagB == 1) && (flagC == 1)){
    printf("presente em todos os vetores");
  }else{
    if(flagA == 1){
      printf("presente no vetor A\n");
    }
    if(flagB == 1){
      printf("presente no vetor B\n");
    }
    if(flagC == 1){
      printf("presente no vetor C\n");
    }
    if(flagA == 0 && flagB == 0 && flagC == 0){
      printf("nao esta em nenhum vetor");
    }
  }
}


/*

Passar 3 vetores e um inteiro com parâmetro para uma função

Verificar se o valor está presente nos vetores passados como parâmetro

como saídaa funçào deve imprimir
se não estiver em nenhum imprimir 0
1. se o valor estiver no vetor 1
2. se estiver no vetor 2
3. se estiver no vetor 3


Leitura de nome peso e altura
inserir na lista em ordem alfabética

listar as pessoas em ordem alfabética
------------------------------------------------------
Nome      Peso    altura       IMC    Classificação
------------------------------------------------------
João       75       1.80     23.15    Normal
Gabriel    60       1.90     16.62    Abaixo do peso
------------------------------------------------------

*/

