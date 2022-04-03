#include <stdio.h>
int main(void) {
  int vetor[16] = {1, 3, 5, 6, 7, 8, 12, 34, 55, 66, 77, 88, 99, 100, 102, 103};
	int numero; // número que vai ser buscado no vetor
	int inicio = 0;
  int fim = 15;
	int meio;
	
	printf("Digite um numero para ser buscado: ");
  scanf("%d", &numero);
  meio = (fim + inicio) / 2;
  while(numero != vetor[meio] && inicio < fim ){
		if(numero > vetor[meio]){
      inicio = meio  + 1;
    } else{
      fim = meio - 1;
    }
    meio = (fim + inicio) / 2;
		printf(" %d %d %d \n ", inicio, meio, fim);
  }
  if(numero == vetor[meio]){
    printf("Encontrado na posição: %d\n", meio);
	} else {
  	printf("\n** Não Encontrado **\n");
	}
	
  return 0;
}




/*  (100)
busca em um vetor ordenado:                   meio = [14]
                                             inicio  fim
[0]                        [7]            [11]     [13]  [4]    [15]
                                                         
{1, 3, 5, 6, 7, 8, 12, 34, 55, 66, 77, 88, 99, 100, 102, 103}

numero inicio fim  meio  vetor[meio] 
-------------------------------------





indice -> 0
55 

500 750 875  *907* ***915 ****919 920  *****921 **923  940

*/


