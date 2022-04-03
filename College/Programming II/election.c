#include <stdio.h>

int main(void) {
  int op;
  int tam;
  int voto;

  printf("Digite a quantidade de candidatos: ");
  scanf("%d",&tam);
  int candidato[tam];

  for(int i = 0; i < tam; i++){
      candidato[i] = 0;
  }

  do{
		puts("1 - Votar");
    puts("2 - Relatorio");
    puts("3 - Grafico de votos");
    puts("0 - Sair");
		scanf("%d", &op);
    switch(op){
      case 0:
        printf("Vote sempre!");
        break;
      case 1:
        printf("Escolha o candidato de 1 a %d\n", tam);
        printf("0 para branco\n");
        printf("outro numero para sair\n");
        do{
          printf("Escolha seu candidato: ");
          scanf("%d", &voto);
          if(voto >= 0 && voto < tam+1){  
            candidato[voto]++;
          }
        }while(voto >= 0 && voto <= tam);
        break;
      case 2:
				printf("\n\n--------------------------\n");
				printf("Canditato  Voto Percentual ");
				printf("\n\n--------------------------\n");
        for(int i = 1;i < tam; i++){
          printf("Candidato %d: Votos: %d\n", i, candidato[i]);
        }
        printf("Votos em branco: %d\n",candidato[0]);
				printf("\n\n--------------------------\n");
        break;
      case 3:
        printf("|------------------------|\n");      
        printf("Candidato / Voto\n");
        printf("|------------------------|\n");
        for(int i = 0; i < tam; i++){    
          if(i == 0){
            printf("Branco.: ");
          } else {
						printf("%7d. ", i);
					}
					for(int x = 0; x < candidato[i]; x++){
            printf("*");
          }
					
          printf("\n");
        }
				printf("\n\n--------------------------\n\n");
        break;
      default:
        printf("Opcao invalida!");
    }
  }while(op!=0);
  return 0;
}

/* Eleiçao

4 Candidatos (1, 2, 3, 4)(Branco)
- candidato[1] 
- Leitura dos votos
- 0 Branco


Imprimir o Resultado:

Candidato  Votos Perc.
    1        10    xx%
		2        15    xx%
		3        12    xx%
		4         5    xx%
		Brancos  11    xx%

Candidato/ Votos

1. **********
2. ***************
3. ************
4. *****
B. ***********

*/
