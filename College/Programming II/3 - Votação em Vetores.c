#include <stdio.h>

int main(void) {
  int op;
  int tam;
  int voto;
  int votoTotal = 0;
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
          if(voto >= 0 && voto < tam + 1){  
            candidato[voto]++;
            votoTotal++;
          }
        }while(voto >= 0 && voto <= tam);
        break;
      case 2:
				printf("\n\n--------------------------\n");
				printf("Canditato  Voto Percentual ");
				printf("\n\n--------------------------\n");
        for(int i = 1; i <= tam; i++){
          printf(" %6d | %6d| %6.1f\n", i, candidato[i], (float)(candidato[i] * 100) /votoTotal);
        }
        printf("Brancos | %6d| %6.1f\n",candidato[0], (float)(candidato[0] * 100)/ votoTotal);
				printf("Total de Votos: %d", votoTotal);
				printf("\n\n--------------------------\n");
        break;
      case 3:
        printf("|------------------------|\n");      
        printf("Candidato / Voto\n");
        printf("|------------------------|\n");
        for(int i = 0; i <= tam; i++){    
          if(i == 0){
            printf("Branco.: ");
          } else {
						printf("%6d.: ", i);
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
  }while (op != 0);
  return 0;
}

/* Eleiçao

4 Candidatos (1, 2, 3, 4)(Branco)
- candidato[1] 
- Leitura dos votos
- 0 Branco


Imprimir o Resultado:

Candidato  Votos  Perc.
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

parte       total
12    ---    43
       x
 x    ---   100    

12 *  100 = 43 * x

x = (12 * 100) / 43

x = (10 / 35) * 100

      0 * 100


			0 4 baixo
      5 9 cima0

			34.3804958484
			
*/
