#include <stdio.h>

#define TAMANHO1 8
#define TAMANHO2 8

void diagonalDoisFor(int matriz[][TAMANHO1], int limite);
void imprimirMatriz(int matriz[][TAMANHO1], int limite);
void diagonalEstatica(int matriz[][TAMANHO1], int limite);

int main(void) {
  static int matriz[4][4];
  int m[8][8];
	int tamanho;
	int a[2][3] = {{1, 2, 1}, {3, 2, 1}};

  diagonalDoisFor(matriz, 4);
  imprimirMatriz(matriz, 4);
	puts("");
  diagonalDoisFor(m, 8);
  imprimirMatriz(m, 8);
	puts("");
	diagonalEstatica(m, 8);
	imprimirMatriz(m, 8);
	puts("");
	puts("printf(\"|%4.2f|\", 23.12345)");
	printf("|%4.2f|\n", 23.12345);

  //Exibir matriz
  
  return 0;
}


/*
1 0 0 0 
0 1 0 0 
0 0 1 0
0 0 0 1
*/
void diagonalEstatica(int matriz[][TAMANHO1], int limite){
  for(int x = 0; x < limite; x++){
    matriz[x][x] = 1;
  }
}

void diagonalDoisFor(int matriz[][TAMANHO1], int limite){
  for(int x = 0; x < limite; x++){
    for (int y = 0; y < limite; y++){
      if(x == y){
        matriz[x][y] = 1;
      }else{
        matriz[x][y] = 0;
      }
    }
  }
}

void imprimirMatriz(int matriz[][TAMANHO1], int limite){
  for(int x = 0; x < limite; x++){
      for(int y = 0; y < limite; y++){
        printf("%d ", matriz[x][y]);
      }
      puts("");
    }
}

/*
0f 1f 2f 3f 4f 5f 6f 7f
00 01 02 03 10 11 12 13 
 4  3  0  2  1  2  1  9

 4 3 0 2 
 1 2 1 9

v[0]

v
&v[0]

int v[4];
0f 0[  2 ]
1f 1[  1 ]
2f 2[  4 ]
3f 3[  8 ]
int a = v[3];

struct l {int e; struct l *p};
struct l *lista
4f [2, 6f] 0101010101
5f [ 8, NULL ]
6f [1, 9f]
7f [ 8 ] (a) 
8f [ ocupado ]
9f [4, 5f ]
Af []
Bf [4f] (lista)

RAM
[x x x x x x   ]
disco
[   
swap [ x x x          ]



]

*/