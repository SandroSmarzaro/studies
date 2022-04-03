/* Fig. 12.8: fig12_08.c
   dynamic stack program */
#include <stdio.h>
#include <stdlib.h>

struct stackNode {   
    int data; 
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;     // NoPilhaPtr

void push( StackNodePtr *topPtr, int info );
int pop( StackNodePtr *topPtr );
void printStack( StackNodePtr currentPtr );

int main(){
	StackNodePtr stackPtr = NULL;
	int teste;
	push(&stackPtr, 3);
	push(&stackPtr, 7);
	push(&stackPtr, 20);
	printStack (stackPtr);
  printf("Saiu -> %d\n",pop(&stackPtr));
  printStack (stackPtr);

}

void push( StackNodePtr *topPtr, int info ){
	StackNodePtr newPtr;
	newPtr = malloc(sizeof(StackNode));
  if(newPtr != NULL){
    newPtr->data = info;
    newPtr->nextPtr= *topPtr;
    *topPtr = newPtr;
  }else {
    printf("Overflow, não consegui inserir valor %d :(\n", info);
  }
}

int pop( StackNodePtr *topPtr){
	StackNodePtr tempPtr;
	int value;
	tempPtr = *topPtr;
	value = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return value;
}

void printStack(StackNodePtr currentPtr){
  if(currentPtr == NULL){
    printf("Pilha vazia");
  } else {
    while(currentPtr != NULL){
      printf("%d\n",currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }
  }
}

/*
>>> s1 = '-'
>>> s2 = '+'

(a) '-+'
(b) '-+-'
(c) '+––'
(d) '+––+––'
(e) '+––+––+––+––+––+––+––+––+––+––+'
(f) '+–+++––+–+++––+–+++––+–+++––+–+++––'

*/


