/*	
	implementação de Pilha usando vetor
	pilha 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct pilha{
  int item[MAX];
  int topo;
};

typedef struct pilha pl;

void criarPilha(pl *p);
void empilhar(pl *p, int valor);
void desempilhar(pl *p);
int pilhaVazia(pl *p);
int pilhaCheia(pl *p);
void imprimePilha(pl *p);
int lerTopo(pl *p);

int main(void) {      //a   b
	pl *p = (pl *)malloc(sizeof(pl));
  criarPilha(p);
  empilhar(p, 10);
  empilhar(p, 55);
  empilhar(p, 46);
  empilhar(p, 110);
  empilhar(p, 55);
  imprimePilha(p);
  empilhar(p, 4116);	
  empilhar(p, 778);
  empilhar(p, 849);
	puts("Empilhado");
  desempilhar(p);
  imprimePilha(p);
	puts("Imprime topo");
	printf("Topo: %d\n", lerTopo(p));
  desempilhar(p);
	desempilhar(p);
	desempilhar(p);
	desempilhar(p);
	desempilhar(p);
	desempilhar(p);
	desempilhar(p);
  return 0;
}

void criarPilha(pl *p){
	p->topo = -1;
  puts("Pilha criada");
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

void empilhar(pl *p, int valor){
  if(pilhaCheia(p)){
    puts("Pilha cheia");
  }else{
    p->topo++; // p->item[++topo] = valor;
    p->item[p->topo] = valor;
  }
}

void desempilhar(pl *p){
  if(pilhaVazia(p)){
    puts("Pilha vazia");
  }else{
    p->topo--;
  }
}

int lerTopo(pl *p){
  return p->topo;
}

void imprimePilha(pl *p){
  for(int i = 0; i <= p->topo; i++){
    printf("Pilha[%d]: %d\n", i,p->item[i]);
  }
}
/*


2 3 1 6 1


*/

  