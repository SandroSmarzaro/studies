#include <stdio.h>

double raizQuadrada(double n);
double raiz(double n, double inicio, double fim);
double absoluto(double valor);

int main(void) {
  double numero;
	double i;
  printf("Digite um valor para Raiz Quadrada: ");
  scanf("%lf", &numero);
  i = raizQuadrada(numero);
  printf("\nResultado: %.5f", raiz(numero, i - 1, i));
  return 0;
}

double raizQuadrada(double n){
	double i = 1;
	while(i * i < n){
    //verificar se é um quadrado perfeito
    i += 1;
  }
	return i;
}

double raiz(double n, double inicio, double fim){
	double meio = (inicio + fim) / 2;
	double mult = meio * meio;
	while(absoluto(mult - n) > 0.0000001){
		if(mult < n){
			inicio = meio;
		} else {
      fim = meio;
		}
		meio = (inicio + fim) / 2;
		mult = meio * meio;
  }
	return meio;
}

double absoluto(double valor){
  if(valor >= 0){
    return valor;
  }else{
    return valor * -1;
  }
}
	
/*
Encontrar a raiz de n com precisão 5
1. Começar a testar os quadrados a partir de i = 1
2. Se i * i = n --> raiz(n) = i
3. Senão buscar o menor i onde i * i > n
4. Raiz de n está entre (i - 1) e i
5. Calcular o meio do intervalo (i - 1) e i
		((i - 1) + i) / 2
6. comparar meio * meio com n com precisão 5
	a. meio * meio = n --> retorna meio
	b. meio * meio < n --> inicio recebe meio
	c. meio * meio > n --> fim recebe meio



Exemplo com raiz de 10
inicio           meio                   fim
3                3,5                     4
[                                        ]
inicio           fim
[                  ]



Exemplo com raiz de 15
inicio                                  fim
3                3,5                     4
[                                        ]
                 inicio                 fim
								 [                       ]
*/