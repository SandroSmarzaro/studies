#include <stdio.h>
#include <stdlib.h>
int main(){

	char conceito;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int total;

	puts("informe o conceito: ");
	puts("Conceito A");
	puts("Conceito B");
	puts("Conceito C");
	puts("Conceito D");
	puts("Sair ");
	while((conceito = getchar()) != EOF){
			switch(conceito){
				case 'A':
				case 'a':
					a++;
					break;
				case 'B':
				case 'b':
					b++;
					break;
				case 'C':
				case 'c':
					c++;
					break;
				case 'D':
				case 'd':
					d++;
					break;
				case '\n':
				case '\t':
				case ' ':
					break;
				default:
					puts("Conceito invalido!");
					break;     
			}
	}

  total = a + b + c + d;

  printf("Conceito A: %3d Percentual: %3d\n",a , a * (100/total)); 
  printf("Conceito B: %3d Percentual: %3d\n",b , b * (100/total)); 
  printf("Conceito C: %3d Percentual: %3d\n",c , c * (100/total)); 
  printf("Conceito D: %3d Percentual: %3d\n",d , d * (100/total));  

	int i;
	for (i = 0; i < 16; ++i){
		if ( i == 5 ){
			break; // força a saida do loop, força a parada do loop
		}
		printf("%d ", i);
	}
	printf("\nSaida com i = %d \n", i);

	for (i = 0; i < 16; ++i){
		if ( i % 2 == 0 ){
			continue; // volta para o inicio do loop sem executar
								// o restante do bloco do loop, mantendo o valor
								// das variáveis
								// interrompe o fluxo do loop
		}
		printf("%d ", i);
	}
	printf("\nSaida com i = %d\n ", i);

  return 0;
}
/*
Programa que lê conceitos da unidade de entrada
- conceitos pode ser de A até D, considerando entrada de maiúsculos e minúsculos
- o programa deve contar cada conceito
- ao final do programa deve ser impresso cada conceito e sua quantidade
- Quando o usuário entrar com um conceito diferente o programa deve informar que o conceito está fora da faixa, e pedir um novo conceito


_ Critério de parada vai ser entrar com o conceito 0


	Conceito A: 10 
	Conceito B: 9
	Conceito C: 8
	Conceito D: 3

  a\n

   10 / 100

	 18 / 51

	 18 ---  51
	  x --- 100

		x * 51  = 18 * 100

		x * 51 (/51) = 18 * 100 (/51)
		
		x = 18 * 100 / 51 = 35%


*/