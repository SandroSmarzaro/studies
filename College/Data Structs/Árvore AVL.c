 // Árvores
// Deitel como programar
// percorrer a árvore em preorder, inorder e postorder

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Estrutura de um nó auto-referenciado em uma árvore
struct treeNode {
  int data;
	int height; // 16 = 2ˆ4 ->  log(16,2) = 4
  struct treeNode *leftPtr;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode; // sinonimo para  - struct treeNode -
typedef TreeNode *TreeNodePtr; // sinonimo para - TreeNode* -
int height(struct treeNode *nPtr);
int balanceFactor(struct treeNode *nPtr);
struct treeNode *rightRotate(struct treeNode *y);
struct treeNode *leftRotate(struct treeNode *x);
void insertNode(TreeNodePtr *treePtr, int value);// <modificado
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
int max(int a, int b);

int main(void){
	TreeNodePtr arvore = NULL;
	// 40 30 20 10
	insertNode(&arvore, 40); 
	insertNode(&arvore, 30);	
	insertNode(&arvore, 20);	
	insertNode(&arvore, 10);	
	insertNode(&arvore, 60);	
	insertNode(&arvore, 70);	

	puts("");
	preOrder(arvore);	
}

int height(struct treeNode *nPtr){
	if (nPtr == NULL){
		return 0;
	} else {
		return nPtr->height;
	}
}

int balanceFactor(struct treeNode *nPtr){
	if (nPtr == NULL){
		return 0;
	} else {
		return height(nPtr->leftPtr) - height(nPtr->rightPtr);
	}
}

void insertNode(TreeNodePtr *treePtr, int value){
	if (*treePtr == NULL){
		*treePtr = malloc(sizeof(TreeNode));
		if (*treePtr != NULL){
			(*treePtr)->data = value;
			(*treePtr)->height = 1;
      (*treePtr)->leftPtr = NULL;
      (*treePtr)->rightPtr = NULL;
		} else{
      printf("Overflow de Memoria\n");
    }
	} else {
		if(value < (*treePtr)->data){
			insertNode(&((*treePtr)->leftPtr), value);   
		}else if(value > (*treePtr)->data){
      insertNode(&((*treePtr)->rightPtr), value);
    }else{
      printf("dup");
    }
	}
	
	(*treePtr)->height = max(height((*treePtr)->leftPtr), 
													 height((*treePtr)->rightPtr))+1;
	int bf = balanceFactor(*treePtr);
	// Caso esquerda esquerda bf > 1 e paramet
	if(bf > 1 && value < (*treePtr)->leftPtr->data){
    //        40                 30 
		//       /                  /  \
		//     30        --->>     20   40
		//     /        
		//   20           
    (*treePtr) = rightRotate((*treePtr));

	// caso esquerda direita
  }else if(bf > 1 && value > (*treePtr)->leftPtr->data){
     // 40 - 30 - 35
	  //        40             40                   35 
		//       /              /                    /  \
		//     30     -->>     35        --->>       30  40
		//       \            /    
		//        35        30     
		
    (*treePtr)->leftPtr = leftRotate((*treePtr)->leftPtr);
		(*treePtr) = rightRotate(*treePtr);
  }else if(bf < -1 && value > (*treePtr)->rightPtr->data){
    (*treePtr) = leftRotate(*treePtr);
  }else if(bf < -1 && value < (*treePtr)->rightPtr->data){
    (*treePtr)->rightPtr = rightRotate((*treePtr)->rightPtr);
    (*treePtr) = leftRotate(*treePtr);
  }
}

struct treeNode *rightRotate(struct treeNode *y){
/* 
         y
			 /   \
      x     T3
    /   \
   T1   T2
*/
	struct treeNode *x = y->leftPtr;
	struct treeNode *T2 = x->rightPtr;
	x->rightPtr = y;
	y->leftPtr = T2;
	x->height = max(height(x->leftPtr), height(x->rightPtr)) + 1;
	y->height = max(height(y->leftPtr), height(y->rightPtr)) + 1; 
	return x;
}

struct treeNode *leftRotate(struct treeNode *x){
/* 
         x
			 /   \
      T1    y    
			    /   \
			   T2   T3
*/

	struct treeNode *y = x->rightPtr;
	struct treeNode *T2 = y->leftPtr; 
  y->leftPtr = x;
  x->rightPtr = T2;
	x->height = max(height(x->leftPtr), height(x->rightPtr)) + 1;
	y->height = max(height(y->leftPtr), height(y->rightPtr)) + 1; 
  return y;
}

void preOrder(TreeNodePtr treePtr){
  if (treePtr != NULL){
    printf("%4d", treePtr->data);
    preOrder(treePtr->leftPtr);
    preOrder(treePtr->rightPtr);
  }
}

int max(int a, int b){
	if (a > b){
		return a;
	} else {
		return b;
	}
}
