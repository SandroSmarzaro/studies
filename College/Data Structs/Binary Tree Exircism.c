#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
struct treeNode { /// Estrutura do nó                                           
  	struct treeNode *leftPtr;
  	int data;                   
	struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode; /// Alias para a struct
typedef TreeNode *TreeNodePtr; /// Alias para ponteiro da struct

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);

int menu();
void insertTXTDuplicate(TreeNodePtr *treePtr, char fileName[SIZE]);
TreeNodePtr removeLeafs(TreeNodePtr treePtr); // Questão 5
void compareTrees(TreeNodePtr treePtr); // Questão 7 
int countElementsTree(TreeNodePtr treePtr);
void secondBiggerValueOfTree(TreeNodePtr treePtr); // Questão 1
TreeNodePtr foundSecondBiggerValueOfTree(TreeNodePtr treePtr);

int main(void){
	int option;

	TreeNodePtr rootPtr = NULL;
	TreeNodePtr resultPtr = NULL;
	insertTXTDuplicate(&rootPtr, "datas1.txt");
	puts("");
	do {
		option = menu();
		switch (option) {
			case 0:
				puts("Exit System...\n");
				break;

			case 1:
				removeLeafs(rootPtr);
				break;

			case 2:
				secondBiggerValueOfTree(rootPtr);
				break;

			case 3:
				compareTrees(rootPtr);
				break;

			case 4:
				inOrder(rootPtr);
				puts("\n");
				break;

			default:
				puts("Option Invalid!\n\n");
				break;
		}
	} while (option != 0);

}

void insertNode(TreeNodePtr *treePtr, int value){
	int option;
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		if (*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} 
		else {
      		printf("Memory Overflow\n");
    	}
	} 
	else {
		if (value == (*treePtr)->data || value < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else {
			insertNode(&((*treePtr)->rightPtr), value);
		}
	}
}

void inOrder(TreeNodePtr treePtr){
	if (treePtr != NULL){
		inOrder(treePtr->leftPtr);    
		printf("%4d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

int menu() {
	int option;

	puts("1 - Remove Leafs of Tree");
	puts("2 - Search Second Bigger");
	puts("3 - Compare Number Elements between in Trees");
	puts("4 - Print");
	puts("0 - Exit");
	printf("Option - ");
	scanf("%d", &option);
	puts("\n");

	return option;
}

void insertTXTDuplicate(TreeNodePtr *treePtr, char fileName[SIZE]) {
	int value;
	int option;

	FILE *file;
	file = fopen(fileName, "r");
	if (file == NULL) {
		puts("\nFile can't open.\n");
		exit(1);
	}
	else {
		while (!feof(file)) {
			fscanf(file, "%d", &value);
			insertNode(treePtr, value);
		}
		fclose(file);
	}
}

TreeNodePtr removeLeafs(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL) {
			free(treePtr);
			return NULL;
		}
		else {
			treePtr->leftPtr = removeLeafs(treePtr->leftPtr);
			treePtr->rightPtr = removeLeafs(treePtr->rightPtr);
		}
	}
	else {
		return NULL;
	}
	return treePtr;
}

int countElementsTree(TreeNodePtr treePtr) {
	int elementsNumber = 0;
	if (treePtr != NULL){
		elementsNumber++;
		elementsNumber += countElementsTree(treePtr->leftPtr);
		elementsNumber += countElementsTree(treePtr->rightPtr);
	}
	return elementsNumber;
}

TreeNodePtr foundSecondBiggerValueOfTree(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		TreeNodePtr resultPtr = NULL;
		while (treePtr != NULL && treePtr->rightPtr != NULL) {
			resultPtr = treePtr;
			treePtr = treePtr->rightPtr;
		}
		if (treePtr->leftPtr == NULL) {
			return resultPtr;
		}
		else{
			treePtr = treePtr->leftPtr;
			while(treePtr->rightPtr != NULL){
				treePtr = treePtr->rightPtr;
			}
			return treePtr;
		}
	}
	else {
		return NULL;
	}
}

void secondBiggerValueOfTree(TreeNodePtr treePtr) {
	TreeNodePtr bigger2ndPtr = foundSecondBiggerValueOfTree(treePtr);
	printf("\t\tThe second bigger is %d\n\n", bigger2ndPtr->data);
}

void compareTrees(TreeNodePtr treePtr) {
	int numberOfFirstTree = countElementsTree(treePtr);
	TreeNodePtr secondRootPrt = NULL;
	insertTXTDuplicate(&secondRootPrt, "datas2.txt");
	int numbersOfSecondTree = countElementsTree(secondRootPrt);

	if (numberOfFirstTree == numbersOfSecondTree) {
		puts("\t\tThe Trees are equals.\n\n");
	}
	else {
		puts("\t\tThe Trees are differents!\n\n");
	}
}
