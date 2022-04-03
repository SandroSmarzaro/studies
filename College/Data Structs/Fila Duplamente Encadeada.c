/*
Operações em uma lista duplamente encadeada
- Insert
- Delete
- Print
*/

#include <stdio.h>
#include <stdlib.h>

struct listNode{
  struct listNode *prevPtr;
  char data;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insertOrder(ListNodePtr *sPtr, char value);
void Delete(ListNodePtr *sPtr, char data);
void print(ListNodePtr *sPtr);

int main(void){
  ListNodePtr sPtr = NULL;
  insertOrder(&sPtr, 'a');
  insertOrder(&sPtr, 'd');
  insertOrder(&sPtr, 'c');
  insertOrder(&sPtr, 'e');
  insertOrder(&sPtr, 'g');
  print(&sPtr);
  Delete(&sPtr, 'a');
  Delete(&sPtr, 'd');
  Delete(&sPtr, 'g');
	print(&sPtr);
  return 0;
}

void insertOrder(ListNodePtr *sPtr, char value){
  ListNodePtr newPtr = NULL;
  ListNodePtr currentPtr = NULL;
  newPtr = malloc(sizeof(ListNode));
  if(newPtr != NULL){
    newPtr->prevPtr = NULL;
    newPtr->data = value;
    newPtr->nextPtr = NULL;
    currentPtr = *sPtr;
    if(currentPtr == NULL){
      *sPtr = newPtr;
    }else{
      while(currentPtr->nextPtr != NULL && value > currentPtr->data ){
        currentPtr = currentPtr->nextPtr;
      }
      if(currentPtr->nextPtr == NULL && value > currentPtr->data){
        //insere no final
        currentPtr->nextPtr = newPtr;
        newPtr->prevPtr = currentPtr;
        
      } else if(currentPtr->prevPtr == NULL && value < currentPtr->data){
        //Insere no Inicio
        newPtr->nextPtr = currentPtr;
        currentPtr->prevPtr = newPtr;
        *sPtr = newPtr;
      } else {
				newPtr->nextPtr = currentPtr;
				newPtr->prevPtr = currentPtr->prevPtr;
				currentPtr->prevPtr->nextPtr = newPtr;
				currentPtr->prevPtr = newPtr;
			}
    }
  }else{
    printf("Overflow de Memoria!\n");
  }
}

void Delete(ListNodePtr *sPtr, char value){
  // buscar o dado
	// se encontrar apaga
  ListNodePtr currentPtr;
  currentPtr = *sPtr;
  if(currentPtr != NULL){
    if(currentPtr->data == value){
      //delete no início
      currentPtr->nextPtr->prevPtr = NULL;
      *sPtr = (*sPtr)->nextPtr;
      free(currentPtr);
    }else{
      while(currentPtr->nextPtr != NULL && currentPtr->data != value){
        currentPtr = currentPtr->nextPtr;
      }
      if(currentPtr->data == value){
        if(currentPtr->nextPtr == NULL){
          currentPtr->prevPtr->nextPtr = NULL;
        } else {
          currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
          currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
        }
        free(currentPtr);
      }else{
        printf("Item nao encontrado!\n");
      }
    }
  }else{
    printf("Lista Vazia\n");
  }
}

void print(ListNodePtr *sPtr){
  ListNodePtr currentPtr;
  currentPtr = *sPtr;
  if(currentPtr == NULL){
    printf("Lista Vazia!\n");
  }else{
    while(currentPtr != NULL){
      printf("%c <-> ", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }
    printf("\n");
  }
}
