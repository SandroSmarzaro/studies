#include <stdio.h>

#define NOTA 5  // Quantidade de notas posíveis

int main(void) {
	static int notas[NOTA];
  int flag = 1;
  int estrelas;
  int total = 0;
  int somaPeso = 0;
  float media = 0;
  int moda;

  while(flag == 1){
    do{
			printf("informe a sua nota sobre o produto comprado(1 - %d):", NOTA);
			scanf("%d", &estrelas);
    }while(estrelas < 1 || estrelas > NOTA); // -1 0 1 2 3 4 5 6 7 
    notas[estrelas - 1] += 1;
    printf("Deseja continuar? SIM(1) - NAO(0): ");
    scanf("%d", &flag);
  }

  for(int i = 0; i < NOTA; i++){
    printf("Total de Nota %d: %d\n", i + 1, notas[i]);
    somaPeso += (i+1) * notas[i];
    total += notas[i];
  }

  media = (float) somaPeso / total;
  printf("Media de Notas: %.2f\n", media);
  
  moda = 0;
  for(int i = 1; i < NOTA; i++){
    if(notas[i] > notas[moda]){
      moda = i;
    }
  }
  printf("Moda das Notas: %d\n", moda + 1);

  return 0;
}

/*
Fazer um programa que receba uma avaliação do cliente, de 1 a 5;

em seguida impria o total de cada avaliação, a média, e a moda

av  total
1    10
2    10
3    10
4    10
5    10
--------

Total: 50
Média: 10
Moda: 10

av  total
1    0
2    0
3    0
4    5
5    10
--------
1 * 0 + 2 * 0  + 3 * 0 + 4 * 5 + 5 * 10
-----------------------------------------
        5 + 10

20 + 50
-------
  15

4,66


Total: 15
Média: 4,66
Moda: 5



5,01
5,06
5,10
4,98
4,93


4,0
6,0
3,5
6,5
4,0
5,5
6
4


*/