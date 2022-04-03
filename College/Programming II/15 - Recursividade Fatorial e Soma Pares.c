#include <stdio.h>

int fatorial(int n);
int soma(int par);

int main(void) {
	int par;
  printf("\n fatorial %d\n",fatorial(5));
  do{
    printf("informe um valor par: ");
    scanf("%d", &par);
  } while(par % 2 != 0);
  printf("somatorio dos pares: %d", soma(par));
  return 0;
}

int fatorial(int n){
	if (n <= 1){
		return 1;
	} else {
		return n * fatorial(n-1);
	}
}

int soma (int par){
  if(par == 0){
    return 0;
  }else{
    return par + soma(par - 2);
  }
}


/*

Fatorial (!)

5! = 5 * 4!       5! = 5 * 24 = 120
4! = 4 * 3!       4! = 4 *  6 =  24
3! = 3 * 2!       3! = 3 *  2 =   6
2! = 2 * 1!       2! = 2 *  1 =   2
1! = 1

Soma dos pares até numero (parametro);

Exemplo: 
Soma(6) = 6 + Soma(4)
Soma(4) = 4 + Soma(2)
Soma(2) = 2 + Soma(0)
Soma(0) = 0

*/


