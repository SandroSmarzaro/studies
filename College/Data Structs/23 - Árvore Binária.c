// Árvores
// Deitel como programar
// percorrer a árvore em preorder, inorder e postorder

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Estrutura de um nó auto-referenciado em uma árvore        

struct treeNode {
  int data;
	int height;
  struct treeNode *leftPtr;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode; // sinonimo para  - struct treeNode -
typedef TreeNode *TreeNodePtr; // sinonimo para - TreeNode* -

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
struct treeNode* deleteNode(struct treeNode *root, int key);
struct treeNode* minimo(struct treeNode * root);
struct treeNode* maximo(struct treeNode * root);

int main(void){
	TreeNodePtr rootPtr = NULL;
	TreeNodePtr tempPtr = NULL;
	struct treeNode* deletadoPtr = NULL;

	puts("\n\nValores");

	insertNode(&rootPtr, 10);
	insertNode(&rootPtr, 5);
	insertNode(&rootPtr, 8);
	insertNode(&rootPtr, 7);
	insertNode(&rootPtr, 9);
	insertNode(&rootPtr, 1);
	insertNode(&rootPtr, 2);
	insertNode(&rootPtr, 8);
	insertNode(&rootPtr, 12);

	puts("\n\nImpressão em inOrder");
	inOrder(rootPtr);

  deletadoPtr = deleteNode(rootPtr, 8);
  
	printf("\n deletado: %d: \n", deletadoPtr->data);
  
	puts("\n\nImpressão em inOrder");
	inOrder(rootPtr);	

	tempPtr = minimo(rootPtr);
	printf("\nMinimo: %d: ", tempPtr->data);
	tempPtr = maximo(rootPtr);
	printf("\nMaximo: %d: ", tempPtr->data);
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
}

void inOrder(TreeNodePtr treePtr){
	if (treePtr != NULL){
		inOrder(treePtr->leftPtr);    //chamada
		printf("%4d", treePtr->data); //impressao
		inOrder(treePtr->rightPtr);   //chamada
	}
}

struct treeNode *minimo(struct treeNode * root){
	struct treeNode *current = root;
	while( current->leftPtr && current != NULL ){
		current = current->leftPtr;
	}
	return current;
}

struct treeNode *maximo(struct treeNode * root){
	struct treeNode *current = root;
	while(current->rightPtr && current != NULL ){
		current = current->rightPtr;
	}
	return current;
}

struct treeNode* deleteNode(struct treeNode *root, int key){
	if (root == NULL)	return NULL;
	if (key < root->data){
		root->leftPtr = deleteNode(root->leftPtr, key);
	} else if (key > root->data){
		root->rightPtr = deleteNode(root->rightPtr, key);
	} else {
		if (root->leftPtr == NULL){
			struct treeNode *temp = root->rightPtr;
			free(root);
			return temp;
		} else if (root->rightPtr == NULL){
			struct treeNode * temp = root->leftPtr;
			free(root);
			return temp;
		}
		struct treeNode *temp = minimo(root->rightPtr);
		root->data = temp->data;
		root->rightPtr = deleteNode(root->rightPtr, temp->data);
	}
  return root;
}



