#include <stdio.h>

void ordena(int vetor[], int tamanho);
void ordena2(int vetor[], int tamanho);
void imprime(int vetor[], int tamanho);
int buscaBinaria(int vetor[], int chave, int tamanho);

int main(void) {
	int a[] = {1, 2, -1, 3, 1, 21, 10, 1, 14, 17, 9};
	int b[] = {1, 2, 1, 3, -1, 21, 10, 1, 14, 17, 9};
	int tamanho = 11;
	int numero;
	int posicao;
	
	ordena(a, tamanho);
  imprime(a, tamanho);

	ordena2(b, tamanho);
  imprime(b, tamanho);

  printf("Digite um numero: ");
  scanf("%d", &numero);
	posicao = buscaBinaria(b, numero, tamanho);
  printf("Posicao: %d", posicao);

  return 0;
}

void ordena(int vetor[], int tamanho){
  for(int i = 0; i < tamanho; i++){
    for(int j = i; j < tamanho; j++){
      if(vetor[j] < vetor[i]){
        int aux = vetor[j];
        vetor[j] = vetor[i];
        vetor[i] = aux;
      }
    }
  }
}

void ordena2(int vetor[], int tamanho){
  for(int i = 0; i < tamanho; i++){
    for(int j = 0; j < tamanho - 1; j++){
			if(vetor[j+1] < vetor[j]){
				int aux = vetor[j + 1];
				vetor[j + 1] = vetor[j];
				vetor[j] = aux;
			}
    }
  }
}

int buscaBinaria(int vetor[], int chave, int tamanho){
	int inicio = 0;
	int fim = tamanho - 1;
	while (inicio <= fim){
	int meio = (inicio + fim) / 2;
		if(vetor[meio] == chave){
			return meio;
		}else if(chave > vetor[meio]){
			inicio = meio + 1;
		}else{
			fim = meio - 1;
		}
  }
  return -1;
}
         
void imprime(int vetor[], int tamanho){
	for(int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
  }
  puts("");
}

/*
int a[] = {1, 2, 1, 3, 1, 21, 10, 1, 14, 17, 9};

a[] = {1, 2, 1, 3, 1, 21, 10, 1, 14, 17, 9};
(Ordena 1);

1. fixar os itens ordenados a partir da posição [0]
       1                                    *
a[] = {1, 2, 1, 3, 1, 21, 10, 1, 14, 17, 9};
          1                                 *  
a[] = {1, 1, 2, 3, 1, 21, 10, 1, 14, 17, 9};
             1                              *  
a[] = {1, 1, 1, 3, 2, 21, 10, 1, 14, 17, 9};
                1                           *  
a[] = {1, 1, 1, 1, 3, 21, 10, 2, 14, 17, 9};

                      *  *       *
a[] = {1, 1, 1, 1, 2, 3, 9, 10, 14, 17, 21} 

*/


