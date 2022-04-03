#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  int c;
  int escolha;
	int tentativas = 0;
	int acertos = 0;
  int resposta = 1;
  float porcentagem;
	srand(time(NULL));
	do{
		do {
			puts("cara (0) ou coroa (1):");
			scanf("%d", &escolha);
		} while(escolha < 0 || escolha > 1);
    tentativas++;
 		c = rand() % 2;
		if(c != escolha){
			puts("perdedor");
		} else {
      puts("voce acertou");
			++acertos;
		}
		printf("escolha: %d\n", escolha);
	  printf("resultado: %d\n", c);
		puts("Continua? Sim= 1 Nao= 0");
    scanf("%d", &resposta);
	} while(resposta == 1);
  porcentagem =  100 * (float)acertos / tentativas;
  printf("\nvoce acertou %d vezes", acertos);
  printf("\nvoce tentou %d vezes", tentativas);
  printf("\nporcentagem de acerto: %.1f \n", porcentagem);
  return 0;
}


/*

O usuário escolhe cara (0) ou coroa (1), o programa, usando rand() diz se ele acertou ou não.
para quando o usuário entrar com um valor diferente de 0 ou 1.


1234123414
456456464645
*/