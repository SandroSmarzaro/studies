// programa que retorna o máximo de 3 valores
#include <stdio.h>

int maximo(int x, int y, int z);

int main(void) {
	int numero1;
	int numero2;
	int numero3;
  scanf("%d%d%d", &numero1, &numero2, &numero3);
  printf("o valor maximo eh: %d", maximo(numero1, numero2, numero3));
  return 0;
}

int maximo(int x, int y, int z){
  int max = x;
  if(y > max){
    max = y;
  }
  if(z > max){
    max = z;
  }
  return max;
}