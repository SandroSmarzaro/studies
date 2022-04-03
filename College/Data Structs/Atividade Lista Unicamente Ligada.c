#include <stdio.h>
#include <stdlib.h>

struct listNode {            
    int data;                
    struct listNode *nextPtr;
}; 

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *sPtr, int value );
void printList( ListNodePtr currentPtr );
int questionFirst(ListNodePtr currentPtr, int n);
int questionSecond(ListNodePtr currentPtr, int value);
int questionThird(ListNodePtr currentPtr, int value);
int questionFourth(ListNodePtr currentPtr);

int main() {
  ListNodePtr startPtr = NULL;
  insert(&startPtr, 10);
  insert(&startPtr, 40);
  insert(&startPtr, 55);
  insert(&startPtr, 80);
  insert(&startPtr, 90);
  printList( startPtr );
  printf("Question 1: %d\n", questionFirst( startPtr, 3));
  printf("Question 2: %d\n", questionSecond(startPtr, 55));
  insert(&startPtr, 55);
  printList( startPtr );
  printf("Question 3: %d\n", questionThird(startPtr, 55));
  printf("Question 4: %d\n", questionFourth(startPtr));

  return 0;
}

void insert( ListNodePtr *sPtr, int value ) { 
  ListNodePtr newPtr = NULL;
  ListNodePtr previousPtr = NULL;
  ListNodePtr currentPtr = NULL;   
  newPtr = malloc( sizeof( ListNode ) );

  if ( newPtr != NULL ) {
    newPtr->data = value;
    newPtr->nextPtr = NULL;
    previousPtr = NULL;
    currentPtr = *sPtr;

    while ( currentPtr != NULL ) { 
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if ( previousPtr == NULL ) { 
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    }
    else {
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
  }
  else { 
    printf( "%d not inserted. No memory available.\n", value );
  }
}

void printList( ListNodePtr currentPtr ) {
  if ( currentPtr == NULL ) {
      printf( "List is empty.\n\n" );
  }
  else { 
      printf( "\nThe list is:\n" );
      while ( currentPtr != NULL ) { 
          printf( "%d --> ", currentPtr->data );
          currentPtr = currentPtr->nextPtr;   
      }
      printf( "NULL\n\n" );
  }
}

int questionFirst(ListNodePtr currentPtr, int n) {
  int value = 0;

  for (int count = 0; count <= n; count++) {
    value = currentPtr->data;
    currentPtr = currentPtr->nextPtr;
  }

  return value;
}

int questionSecond(ListNodePtr currentPtr, int value) {
  while (currentPtr != NULL) {
    if ( currentPtr->data == value ){
      return 1;
    }
    currentPtr = currentPtr->nextPtr;
  }
  return 0;
}

int questionThird(ListNodePtr currentPtr, int value) {
  int count = 0;

  while (currentPtr != NULL) {
    if (currentPtr->data == value) {
      count++;
    }
    currentPtr = currentPtr->nextPtr;
  }

  return count;
}

int questionFourth(ListNodePtr currentPtr) {
    int count = 0;
    ListNodePtr halfPtr = currentPtr;
    ListNodePtr endPtr = currentPtr;

    while ( endPtr != NULL ) {
        count++;
        endPtr = endPtr->nextPtr;
        if (count % 2 == 0) {
            halfPtr = halfPtr->nextPtr;
        }
    }
    if ( count % 2 == 1 ) {
        halfPtr = halfPtr->nextPtr;
    } 

    return halfPtr->data;
}
