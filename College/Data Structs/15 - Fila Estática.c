#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct fila{
  int inicio;
  int ultimo;
  int item[MAX];
};

typedef struct fila fl;

void criaFilaVazia(fl* f);
int filaCheia(fl* f);
int filaVazia(fl* f);
void enfileirar (fl* f, int valor);
void desenfileira(fl* f);
int lerAtual(fl* f);
void printFila(fl* f);

int main(void) {
	fl *fila = malloc(sizeof(fl));
	
  criaFilaVazia(fila);
  enfileirar(fila, 10);
  enfileirar(fila, 8);
	
  enfileirar(fila, 15);
  enfileirar(fila, 35);
  printFila(fila);
  printf("\nAtual: %d\n", lerAtual(fila));
	desenfileira(fila);
  desenfileira(fila);
  enfileirar(fila, 2);
  enfileirar(fila, 9);
  printFila(fila);
  printf("\nAtual: %d\n", lerAtual(fila));
  enfileirar(fila, 75);
  enfileirar(fila, 45);
  enfileirar(fila, 64);

  return 0;
}

void criaFilaVazia(fl* f){
	f->inicio =  0;
	f->ultimo = -1;
}

int filaCheia(fl* f){
	return (f->ultimo  == MAX);
}

int filaVazia(fl* f){
  return f->ultimo < 0 || f->inicio > f->ultimo;
}

void enfileirar (fl* f, int valor){
  if(!filaCheia(f)){
    f->ultimo++;
    f->item[f->ultimo] = valor;
  }else{
    printf("Erro ao Enfileirar!\n");
  }
}

void desenfileira(fl* f){
  if(!filaVazia(f)){
    f->inicio++;
  }else{
    printf("Erro ao Desenfileirar!\n");
  }
}

int lerAtual(fl* f){
  return f->item[f->inicio];
}

void printFila(fl* f){
	puts("");
  for(int i = f->inicio; i <= f->ultimo; i++){
    printf("[%d] <-", f->item[i]);
  }
	puts("");
}

/*
        inicio      fim
         |           |
[ #][ 1][ 2][ 2][2 ][ 5][ 8]


begin procedure isEmpty 
  if último é menor que MIN OR frente é maior que fim
    return true 
  else 
    return false 
  endif 
end procedure

begin procedure isfull
  if rear equals to MAXSIZE 
    return true 
  else 
    return false 
  endif 
end procedure

Insere um elemento no fim da fila
Passo 1 − Verifica se a fila está cheia
Passo 2 − Se a fila estiver cheia, retorna erro e sai.
Passo 3 − Se a fila não estiver cheia incremente o fim .
Passo 4 − Adicione o novo elemento no fim.
Passo 5 − retorne sucesso.

Retirar item da fila: deQueue()
Passo 1 − Checar se a fila está vazia.
Passo 2 − Se a fila estiver vazia, 
		         produz erro de  underflow e sai.
Passo 3 − Se a fila não estiver vazia,
						 Incremente o controlador frente 
Passo 5 − Retorne sucesso.

Criar a Fila: CreateEmptyQueue()
Verificar se a fila está vazia: isEmpty()
Verificar se a fila está Cheia: isFull()
Inserir item na fila: enQueue()
Retirar item da fila: deQueue()
Ler elemento da frente: peek()
Imprimir Fila: printQueue()

*/