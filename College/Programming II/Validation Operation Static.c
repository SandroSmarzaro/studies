#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int menu();
void imprimePilha(pl *p);

int main() {
  //alocando o espaço necessário
  pl *p = (pl *)malloc(sizeof(pl));
  int opcao;
  
  do{
    opcao = menu();
    if (opcao == 1){
      char operacao[MAX];
      puts("Insira a operacao:");
      scanf("%s", operacao);
      puts("");
      criarPilha(p);
      for (int index = 0; index < strlen(operacao); index++){
        //ao ver se encontrar qualquer abertura deve-se empilhar  
        if (operacao[index] == '(' || operacao[index] == '{' || operacao[index] =='[' || operacao[index] == '<'){
          empilhar(p, operacao[index]);
        } 
        //se a pilha tiver algum elemento, comparar o operador do topo da pilha com o operador inverso na posição da string
        else if (!pilhaVazia(p) || index < strlen(operacao)){
          if (operacao[index] == ')' && p->operadores[p->topo] == '('){
            desempilhar(p);
          }
          else if (operacao[index] == '}' && p->operadores[p->topo] == '{'){
            desempilhar(p);
          }
          else if (operacao[index] == ']' && p->operadores[p->topo] == '['){
            desempilhar(p);
          }
          else if (operacao[index] == '>' && p->operadores[p->topo] == '<'){
            desempilhar(p);
          }
          //se a comparação for falsa em todos os casos, empilhar o operador de fechamento
          else if (operacao[index] == ')' || operacao[index] == '}' || operacao[index] == ']' || operacao[index] == '>'){
            empilhar(p, operacao[index]);
          }
        }
      }
      //quando a pilha está vazia é sinal que todos os operadores foram fechados
      if (pilhaVazia(p)){
        puts("Operacao Valida.");
      }
      else{
        puts("Operacao Invalida!");
      }
      puts("");
      //resetando o vetor para próxima análise 
      while (p->topo > -1){
        desempilhar(p);
      }
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

void empilhar(pl *p, char operador){
  if(pilhaCheia(p)){
  }
  else{
    p->topo++;
    p->operadores[p->topo] = operador;
  }
}

void desempilhar(pl *p){
  if(pilhaVazia(p)){
  }
  else{
    p->topo--;
  }
}

int menu(){
    int opcao;

    puts("SELECIONE A ACAO");
    puts("");
    puts("1 - Validar Operacao");
    puts("0 - Sair");
    printf("\nACAO: ");
    do{
        scanf("%d", &opcao);
    }while (opcao != 1 && opcao != 0);
    puts("");

    return opcao;
}