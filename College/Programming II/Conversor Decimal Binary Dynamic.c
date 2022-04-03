#include <stdio.h>
#include <stdlib.h> //lib para o malloc
#include <string.h>
#define SIZE 50

//criando a estrutura do nó
struct stackNode {   
    int bit;              //bit na pilha
    struct stackNode *nextPtr;  //ponteiro do tipo estrutura nó para o próximo nó
};

typedef struct stackNode StackNode;   //criando o tipo nó de pilha
typedef StackNode *StackNodePtr;      //criando o tipo ponteiro de nó de pilha

void push (StackNodePtr *topPtr, int bit);    //função de empilhar
void pop (StackNodePtr *topPtr);              //função de desempilhar
void printStack (StackNodePtr currentPtr);   //função de print de pilha
int menu ();

int main(){
    //inicializando a pilha, setando o ponteiro de nó como vazio
    StackNodePtr stackPtr = NULL;
    int option;
    int rest;
    int number;

    do{
        option = menu();
        if (option) {
            do{
                puts("Enter the decimal number to be converted:");
                scanf("%d", &number);
            }while (number < 0 || number > 65535);
            do{
                rest = number % 2;
                push (&stackPtr, rest);
                number /= 2;
            }while (number > 0);
            puts("");
            printStack(stackPtr);
            puts("");
            //desempilhando toda a pilha para estar vazia para próxima análise
            while (stackPtr->nextPtr != NULL || stackPtr->nextPtr != 0) {
                pop (&stackPtr);
            }
            pop (&stackPtr);
        }
    } while (option != 0);

    return 0;
}

void push (StackNodePtr *topPtr, int bit) {
	StackNodePtr newPtr;                //declarando newPtr

    /*alocando e referenciando endereço de memória para newPtr,
    endereço do nó se tiver espaço, se não NULL*/
    newPtr = malloc(sizeof(StackNode));
    if (newPtr != NULL) {              //caso tenha espaço pra alocar, fazer as operações
        newPtr->bit = bit;               //novo nó recebendo o valor a ser empilhado
        newPtr->nextPtr= *topPtr;        //fazendo o novo nó apontar pra seu seguinte, sendo ele o topo atual
        *topPtr = newPtr;                //o topo se torna o novo nó, com o antigo topo sendo o seguinte nó empilhado
    }
    else {
        printf ("Overflow, there is no space in memory! Could not insert operator %d\n", bit);
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
            printf ("%d", currentPtr->bit);
            currentPtr = currentPtr->nextPtr;     //atribuindo o ponteiro o endereço do próximo nó da pilha
        }
        puts("");
    }
}

int menu () {
    int option;

    puts("SELECT ACTION");
    puts("");
    puts("1 - Conversion");
    puts("0 - Exit");
    printf("\nACTION: ");
    do {
        scanf ("%d", &option);
    } while (option != 1 && option != 0);
    puts("");

  return option;
}