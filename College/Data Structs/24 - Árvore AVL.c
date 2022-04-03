// C programa para inserir um nó em uma árvore AVL
#include<stdio.h>
#include<stdlib.h>
 
struct Node {
    int data;
    struct Node *leftPtr;
    struct Node *rightPtr;
    int height;
};
// Prototipação
int max(int a, int b);
int height(struct Node * N);
struct Node *newNode(int key);
struct Node *rightRotation(struct Node *y);
struct Node *leftRotation(struct Node *x);
int balanceFactor(struct Node *N);
struct Node *insert(struct Node *node, int key);
void preOrder(struct Node *root);
int main()
{
  struct Node *root = NULL;
 
  // Construção da árvore
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
  return 0;
}

 
// Função que retorna a altura da árvore
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// retorna o maior de dois inteiros
int max(int a, int b){
	if (a > b) {
		return a;
	} else {
		return b;
	}
  //  return (a > b)? a : b;
}
 
/*  Função que:
	- alloca um novo nó uma chave específica
	- Inicializa leftPtr e rightPtr com NULL
	- Inicializa a altura do nó (height)
 */

struct Node* newNode(int key)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data   = key;
    node->leftPtr   = NULL;
    node->rightPtr  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
// Função que que faz a rotação a direita 
//
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->leftPtr;
    struct Node *T2 = x->rightPtr;
    // Faz a rotação
    x->rightPtr = y;
    y->leftPtr = T2;
 
    // Atualizando a altura
		if (height(y->leftPtr) > height(y->rightPtr)){
			y->height = height(y->leftPtr + 1);
		} else {
			y->height = height(y->rightPtr ) + 1;
		}

		if (height(x->leftPtr) > height(x->rightPtr)){
			x->height = height(x->leftPtr + 1);
		} else {
			x->height = height(x->leftPtr) + 1;
		}
    //y->height = max(height(y->leftPtr), height(y->rightPtr))+1;
    //x->height = max(height(x->leftPtr), height(x->rightPtr))+1;
 
    // Retorna a nova Raiz
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->rightPtr;
    struct Node *T2 = y->leftPtr;
 
    // Perform rotation
    y->leftPtr = x;
    x->rightPtr = T2;
 
    //  Update heights

    x->height = max(height(x->leftPtr), height(x->rightPtr))+1;
    y->height = max(height(y->leftPtr), height(y->rightPtr))+1;
 
    // Return new root
    return y;
}
 
// Retorna o fator de balanceamento de um nó
int balanceFactor(struct Node *N) {
    if (N == NULL){
        return 0;
		} else {
    	return height(N->leftPtr) - height(N->rightPtr);
		}
}
 
// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.

// Função recursiva para inserir um novo nó 
// na arvore como chave primária (sem valore repetidos)
// e retornar a nova raiz da árvore 
struct Node* insert(struct Node* node, int key) {
    // 1.  Inserção
    if (node == NULL){
        return(newNode(key));
		}
    if (key < node->data){
        node->leftPtr  = insert(node->leftPtr, key);
		} else if (key > node->data){
        node->rightPtr = insert(node->rightPtr, key);
		} else {
        return node; 
		}
    // 2. Atualiza a altura do antecessor 
		
    node->height = 1 + max(height(node->leftPtr),
                           height(node->rightPtr));
    // 3. Obtem o fator de balanceamento para verificar
		//    se vai precisar de rotacionar a árvore
    int balance = balanceFactor(node);
    // Caso o nó esteja desbalanceado
    // é feita a verificação dos 4 casos
 
    // 3.1 esquerda esquerda
    if (balance > 1 && key < node->leftPtr->data)
        return rightRotate(node);

   	// 3.2 esquerda direita
    if (balance > 1 && key > node->leftPtr->data)
    {
        node->leftPtr =  leftRotate(node->leftPtr);
        return rightRotate(node);
    }

    // 3.3 Direita Direita
    if (balance < -1 && key > node->rightPtr->data)
        return leftRotate(node);
 
    // 3.4 Direita esquerda
    if (balance < -1 && key < node->rightPtr->data)
    {
        node->rightPtr = rightRotate(node->rightPtr);
        return leftRotate(node);
    }
    /* retorno do nó sem modificação na árvore */
    return node;
}
 
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root){
	if(root != NULL) {
		printf("%d ", root->data);
		preOrder(root->leftPtr);
		preOrder(root->rightPtr);
	}
}
 
