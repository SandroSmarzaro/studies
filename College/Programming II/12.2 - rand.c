#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int dado;
	int x;            // quantidade de elementos
	int static frequencia[6]; // [0] [1] [2] [3] [4] [5]
	for(int i = 1; i <= 30000; i++){
  	dado = 1 + rand() % 6;   //   1   2   *3   4   5   6
		frequencia[dado - 1]++;  // frequencia[2]++
    printf("%3d ", dado);
		if(i % 10 == 0){
			puts("");
		}
  }
  for(int y = 0 ; y < 6 ; y ++){
    printf("\nFrequencia numero %d: %d ", y + 1, frequencia[y]);
  }
  return 0;
}

int quadrado(int x){
	static int y;
	y++;
	x = x * x;
	return x;
}

// printf(y);
// printf(x);
// 0 1 2 3 4 5 6
//       x x x
// valor = 3 + rand() % 3


