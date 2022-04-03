#include <stdio.h>
#include <stdlib.h>
#define MAX 16

struct pilha{
  int bits[MAX];
  int topo;
};

typedef struct pilha pl;

void criarPilha(pl *p);
void empilhar(pl *p, int bit);
void desempilhar(pl *p);
int pilhaVazia(pl *p);
int pilhaCheia(pl *p);
void imprimePilha(pl *p);

int main(void) {
    pl *p = (pl *)malloc(sizeof(pl));
    int numero;
    int resto;
    int opcao;

    do{
      puts("Digite o numero decimal a ser convertido:");
      do{
        scanf("%d", &numero);
      }while (numero < 0 || numero > 65535);
      criarPilha(p);
      do{
        resto = numero % 2;
        empilhar(p, resto);
        numero /= 2;
      }while (numero > 0);
      imprimePilha(p);
      do{
        puts("");
        puts("Deseja continuar?");
        puts("0 - Sair");
        puts("1 - Continuar");
        scanf("%d", &opcao);
        puts("");
      }while (opcao != 1 && opcao != 0);
      //resetando a pilha
      while (p->topo > -1){
        desempilhar(p);
      }
    }while(opcao != 0);

    return 0;
}

void criarPilha(pl *p){
	p->topo = -1;
}

int pilhaVazia(pl *p){
  if(p->topo == -1){
     return 1;
  }else{
    return 0;
  }
}

int pilhaCheia(pl *p){
  if(p->topo == MAX -1){
    return 1;
  }else{
    return 0;
  }
}

void empilhar(pl *p, int bit){
  if(pilhaCheia(p)){
    puts("Pilha cheia");
  }else{
    p->topo++;
    p->bits[p->topo] = bit;
  }
}

void desempilhar(pl *p){
  if(pilhaVazia(p)){
    puts("Pilha vazia");
  }else{
    p->topo--;
  }
}

void imprimePilha(pl *p){
  puts("");
  puts("Numero convertido: ");
  for(int index = p->topo; index >= 0; index--){
    printf("%d", p->bits[index]);
  }
  puts("");
}