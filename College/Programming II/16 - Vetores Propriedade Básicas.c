#include <stdio.h>

#define TAMANHO 10

int main(void) {
	int a[5]; // a[0], a[1], a[2], a[3], a[4]
	int b[] = {11, 12, 13, 14, 15}; 
	// b[0]=11, b[1]=12, b[2]=13, b[3]=14, b[4]=15
	int c[5] = {22, 99};
	static int d[5];
	int e[TAMANHO];
	
	for(int i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	puts("");

	for(int i = 0; i < 5; i++){
		printf("%d ", b[i]);		
	}
	puts("");

	for (int i = 0; i < 5; i++){
		printf("%d ", c[i]);
	}

	for (int i = 0; i < TAMANHO; i++){
		e[i] = 1;
	}
	puts("");

	for (int i = 0; i < TAMANHO; i++){
		printf("%d ", e[i]);
	}
	puts("");

	int a = 2;
	int b = 1;

	b[a + b] += 10; //  () []
  // b[3] += 10
	// b[3] = b[3] + 10
	// b[3] = 14 + 10
	// b[3] = 24


  return 0;
}



/*

Array estruturas homogeneas de dados
todos os dados do array são do mesmo tipo
mem  ind    conte 
023 - 0  -   11 
025 - 1  -   12
027 - 2  -   13
029 - 3  -   14
02B - 4  -   15

Exemplo compra:

R$ 10,00 em 3 parcelas
qual o valor das parcelas?
1. 3,33
2. 3,33
3. 3,34






*/
