#include <stdio.h>
#include <stdlib.h> //lib para o malloc
#include <string.h>
#define SIZE 50

//criando a estrutura do nó
struct stackNode {   
    char operator;              //operador na pilha
    struct stackNode *nextPtr;  //ponteiro do tipo estrutura nó para o próximo nó
};

typedef struct stackNode StackNode;   //criando o tipo nó de pilha
typedef StackNode *StackNodePtr;      //criando o tipo ponteiro de nó de pilha

void push (StackNodePtr *topPtr, char operator);  //função de empilhar
void pop (StackNodePtr *topPtr);              //função de desempilhar
void printStack (StackNodePtr currentPtr);   //função de print de pilha
int menu ();

int main(){
  //inicializando a pilha, setando o ponteiro de nó como vazio
	StackNodePtr stackPtr = NULL;
  int option;

  do{
    option = menu();
    if (option) {
      char operation[SIZE];
      puts ("Insert the operation:");
      scanf ("%s", operation);
      puts("");
      for (int index = 0; index < strlen(operation); index++) {
        //ao ver se encontrar qualquer abertura deve-se empilhar  
        if (operation[index] == '(' || operation[index] == '{' || operation[index] =='[' || operation[index] == '<') {
          push (&stackPtr, operation[index]);
        }
        //se a pilha não estiver vazia, compara-se o operador atual da string com o operador atual no topo
        else if (stackPtr->nextPtr != NULL || stackPtr->nextPtr != 0) {
          if (operation[index] == ')' && stackPtr->operator == '(') {
            pop (&stackPtr);
          }
          else if (operation[index] == '}' && stackPtr->operator == '{') {
            pop (&stackPtr);
          }
          else if (operation[index] == ']' && stackPtr->operator == '[') {
            pop (&stackPtr);
          }
          else if (operation[index] == '>' && stackPtr->operator == '<') {
            pop (&stackPtr);
          }
          //caso ocorra de todas comparações serem falsas, empilha-se o operador de fechamento
          else if (operation[index] == ')' || operation[index] == '}' || operation[index] == ']' || operation[index] == '>') {
            push (&stackPtr, operation[index]);
          }
        }
        else if (operation[index] == ')' || operation[index] == '}' || operation[index] == ']' || operation[index] == '>') {
          push (&stackPtr, operation[index]);
        }
      }
      //quando a pilha após todas operações permanece vazia, sinal que todos operadores abertos foram fechados
      if (stackPtr->nextPtr == NULL || stackPtr->nextPtr == 0) {
        puts ("Valid Operation.");
      }
      else {
        puts("Invalid Operation");
      }
      puts("");
      //desempilhando toda a pilha para estar vazia para próxima análise
      while (stackPtr->nextPtr != NULL || stackPtr->nextPtr != 0) {
        pop (&stackPtr);
      }
    }
  } while (option != 0);
	
  return 0;
}

void push (StackNodePtr *topPtr, char operator) {
	StackNodePtr newPtr;                //declarando newPtr

	/*alocando e referenciando endereço de memória para newPtr,
  endereço do nó se tiver espaço, se não NULL*/
  newPtr = malloc(sizeof(StackNode));
  if (newPtr != NULL) {              //caso tenha espaço pra alocar, fazer as operações
    newPtr->operator = operator;     //novo nó recebendo o valor a ser empilhado
    newPtr->nextPtr= *topPtr;        //fazendo o novo nó apontar pra seu seguinte, sendo ele o topo atual
    *topPtr = newPtr;                //o topo se torna o novo nó, com o antigo topo sendo o seguinte nó empilhado
  }
  else {
    printf ("Overflow, there is no space in memory! Could not insert operator %c\n", operator);
  }
}

void pop (StackNodePtr *topPtr) {
	StackNodePtr tempPtr;           //declaração do ponteiro de nó temporario         
	tempPtr = *topPtr;              //passando o endereço do topo para a temporária
	*topPtr = (*topPtr)->nextPtr;   //aribuindo ao novo endereço do topo, o endereço do nó seguinte do antigo topo agora
	free(tempPtr);                  //liberando | desalocando, espaço do antigo topo, o nó desempilhado
}

void printStack (StackNodePtr currentPtr) {
  if (currentPtr == NULL) {                 //se exatamente o primeiro nó no topo estiver vazio
    puts ("Empty Stack!");                  //sinal que não foi inserido nenhum elemento
  } 
  else {
    while (currentPtr != NULL) {            //enquanto não ncontrar o fim da pilha continua
      printf ("%c\n", currentPtr->operator);
      currentPtr = currentPtr->nextPtr;     //atribuindo o ponteiro o endereço do próximo nó da pilha
    }
  }
}

int menu () {
  int option;

  puts("SELECT ACTION");
  puts("");
  puts("1 - Validate Operation");
  puts("0 - Exit");
  printf("\nACTION: ");
  do {
    scanf ("%d", &option);
  } while (option != 1 && option != 0);
  puts("");

  return option;
}