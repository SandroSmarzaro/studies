#include <stdio.h>

int main(void) {
  int a = 3; 
  int b = 6;
  int c = 2;
  int r;
  r = 3 + 6 / 3;
//  3   2   1   <- prioridade de execução

  printf(" %d \n", r);

	float peso = 79;
	float altura = 1.75;
	float imc;
/*	
	              peso
		imc = ----------------
          (altura x altura)

*/
  imc = peso / altura * altura;
	printf("imc (errado): %f \n", imc);

  imc = peso / (altura * altura);
	printf("imc: %f \n", imc);
// r = -> r vai receber ...
  r = a + b * c - a / b * c - 2;
//      4   1   5   2   3   6   <- prioridade de execução

  printf(" %d \n", r);

	a = 3;
	printf(" %d \n", a++);
	printf(" %d \n", ++a);


/*
									 |	a
	1. imprime a     |  3 *
	1. incrementa a  |  4
	2. incrementa a  |  5
	2. imprime a     |  5 *
*/  

	a = 2; 
	b = 3;
	r = ++a + b++;
	//3  1  2  4
  printf(" %d \n", r);

	while (++a < 10) printf(" %d ", a);
// nunca faça isso 

	puts("  ");

	int soma = 0;
	for (int i = 1; i < 10; i += 2){
		printf(" %d ", i);
    soma += i; // soma = soma + i;
	}
	printf("\nsoma: %d\n", soma);
 
  return 0;
}



/*
  Raphael
  r = a + b * c - a / b * c - 2
        4   1   5   2   3   6
*/


/*
  r = a + b * c - a / b * c -2

*/

/*
  G
  r = a + b * c - a / b * c -2
        4    1  5   2   3   6
*/