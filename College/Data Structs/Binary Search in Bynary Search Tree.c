#include <stdio.h>
#include <stdlib.h>

//  gcc -O2 -S -fno-stack-protector test.c test.s

struct treeNode {                                           
  	struct treeNode *leftPtr;
  	int data;                   
	struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int menu();
void insertTXTDuplicate(TreeNodePtr *treePtr);
int valueSearch();
TreeNodePtr binarySearchValue(TreeNodePtr treePtr, const int value);

int main(void){
	int option;

	TreeNodePtr rootPtr = NULL;
	TreeNodePtr resultPtr = NULL;
	puts("");
	do {
		option = menu();
		switch (option) {
			case 0:
				puts("Exit System...\n");
				break;

			case 1:
				insertTXTDuplicate(&rootPtr);
				break;

			case 2:
				resultPtr = binarySearchValue(rootPtr, valueSearch());
				if (resultPtr == NULL) {
					puts("\n\nValue not found\n\n");
				} 
				else {
					puts("\n\nValue found\n\n");
				}
				break;

			case 3:
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
		if (value == (*treePtr)->data) {
			do {
				printf("The value %d is duplicate!\n", value); 
				printf("1 - Right or 0 - Left?: ");
				scanf("%d", &option);
				puts("\n");
			} while(option != 0 && option != 1);

			if (option) {
				insertNode(&((*treePtr)->rightPtr), value);
			}
			else {
				insertNode(&((*treePtr)->leftPtr), value);
			}
		}
		else if(value < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);   
		}
		else if(value > (*treePtr)->data) {
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

void preOrder(TreeNodePtr treePtr){
  if (treePtr != NULL){
    printf("%4d", treePtr->data);
    preOrder(treePtr->leftPtr);
    preOrder(treePtr->rightPtr);
  }
}

void postOrder(TreeNodePtr treePtr){
  if (treePtr != NULL){
    postOrder(treePtr->leftPtr);
    postOrder(treePtr->rightPtr);
    printf("%4d", treePtr->data);
  }
}

int menu() {
	int option;

	puts("1 - Insert TXT");
	puts("2 - Search Value");
	puts("3 - Print");
	puts("0 - Exit");
	printf("Option - ");
	scanf("%d", &option);
	puts("\n");

	return option;
}

void insertTXTDuplicate(TreeNodePtr *treePtr) {
	int value;
	int option;

	FILE *file;
	file = fopen("datas.txt", "r");
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

int valueSearch() {
	int value;

	printf("Insert value to search: ");
	scanf("%d", &value);

	return value;
}

TreeNodePtr binarySearchValue(TreeNodePtr treePtr, const int value) {
	TreeNodePtr resultPtr = NULL;
	if (treePtr != NULL) {
		if (value == treePtr->data) {
			resultPtr = treePtr;
		}
		else if (value > treePtr->data) {
			resultPtr = binarySearchValue(treePtr->rightPtr, value);
		}
		else {
			resultPtr = binarySearchValue(treePtr->leftPtr, value);
		}
	}
	return resultPtr;
}
