#include <stdio.h>
#include <stdlib.h>
#define MAX 50

//criação da estrutura de daos pilha
struct pilha{
  char operadores[MAX];
  int topo;
};

//criando o tipo pl
typedef struct pilha pl;

void criarPilha(pl *p);
void empilhar(pl *p, char operador);
void desempilhar(pl *p);
int pilhaVazia(pl *p);
int pilhaCheia(pl *p);
void imprimePilha(pl *p);
int lerTopo(pl *p);
int menu();
char *inserirOperacao();

int main(void) {
    //alocando o espaço necessário
    pl *p = (pl *)malloc(sizeof(pl));
    int opcao;
    char *operacao;
       
    do{
        opcao = menu();
        if (opcao == 1){
            operacao = inserirOperacao();
            printf("operacao %s\n", operacao);
        }
    }while(opcao != 0);

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

void empilhar(pl *p, char operador){
  if(pilhaCheia(p)){
    puts("Pilha cheia");
  }else{
    p->topo++;
    p->operadores[p->topo] = operador;
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
    printf("Pilha[%d]: %d\n", i,p->operadores[i]);
  }
}

int menu(){
    int opcao;

    puts("SELECIONE A ACAO");
    puts("");
    puts("1 - Inserir Operacao");
    puts("2 - Validar Operacao");
    puts("0 - Sair");
    printf("\nACAO: ");
    scanf("%d", &opcao);
    puts("");
    return opcao;
}

char *inserirOperacao(){
    char operacao[MAX];

    puts("Insira a operacao:");
    scanf("%s", operacao);

    return operacao;
}
