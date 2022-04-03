// Dependências Necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Macros de Pré Compilação
#define SIZE 50

// Definindo a estrutura do Nó
struct listNode {
  struct listNode *prevPtr;
  char name[SIZE];
  int priority;
  struct listNode *nextPtr;
};

// Definindo a estrutura de array de strings
struct string {
  char theme[SIZE];
};

// Definindo os Tipos
typedef struct string stringArray;
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// Prototipação de Funções
int menu();
void clear();
int randomNumber();
void printList(ListNodePtr *sPtr);
void loadThemes(ListNodePtr *sPtr, int numberNames);
void insertOrder(ListNodePtr *sPtr, char name[SIZE], int priority);
void groupDivider(ListNodePtr *sPtr, stringArray themes[SIZE], int numberNames,int numberThemes);
void generateDocument();

int main(void) {
  int option;
  // Criação da semente de aleatóriadade pela hora e data atual
  srand(time(NULL));
  do {
    // Pegando a opção do usuário
    option = menu();
    switch (option) {
      // Caso o usuário deseja sair do programa
      case 0:

        break;

      // Caso o usuário queira gerar o relatório
      case 1:
        generateDocument();

        break;

      // Caso o usuário insira uma opção inválida
      default:

        break;
    }

  // Enquanto o usuário não inserir a opção de saída, continuar o programa
  } while( option != 0 );

  return 0;
}
// Função que printa o menu e recebe a opção do usuário
int menu() {

  // Declaração de variavéis locais
  int option;

  // Print do menu
  clear();
  puts("\n\tSELECT ACTION");
  puts("-------------------------");
  puts("\n1 - Generate Document");
  puts("0 - Exit\n");
  puts("-------------------------\n");
  printf("ACTION: ");
  scanf("%d", &option);
  clear();

  // Retorna a opção selecionada
  return option;
}
// Função que limpa a tela
void clear(){
  // Caso o OS seja Unix's like o comando será clear
  #if defined(__linux__) || defined(__unix__) || defined (__APPLE__)
  system("clear");
  #endif

  // Caso o OS seja Windows o comando será cls
  #if defined(_WIN32) || defined(_WIN64)
  system("cls");
  #endif
}
// Função de geração de números pseudo-aleatórios inteiros de até SIZE
int randomNumber() {
  return rand() % SIZE;
}
// Função que gera o relatório .txt
void generateDocument() {
  // Declaração de variavéis locais
  int numberNames = 0;
  char filename[SIZE];
  char name[SIZE];
  FILE *namesFile;
  ListNodePtr sPtr = NULL;
  // Obtendo o nome do arquivo a ser aberto
  clear();
  puts("\nFile name of students");
  puts("Ex: nomes.txt");
  puts("-------------------------\n");
  printf("Name: ");
  scanf(" %s",filename);
  // Abrindo o arquivo .txt
  namesFile = fopen(filename, "r");
  // Caso o arquivo esteja vazio avisar
  if ( namesFile == NULL ){
    clear();
    puts("\nFile can't open.\n");

    // Saia dá função caso esteja vazio
    exit(1);
  }
  else {
    // Enquanto não encontrar o EOF continua o loop
    while ( !feof(namesFile) ){
      fscanf(namesFile, "%s", name);
      // Inserindo um novo nó com o nome e prioridade na lista
      insertOrder(&sPtr, name, randomNumber());
      numberNames++;
    }
    loadThemes(&sPtr, numberNames);
  }
  // Fechando o arquivo
  fclose(namesFile);
}
// Função que printa a lista duplamente encadeada
void printList(ListNodePtr *sPtr) {
    ListNodePtr currentPtr;
    currentPtr = *sPtr;
    // Se a lista estiver vazia notificar
    if ( currentPtr == NULL ) {
      clear();
      puts("\nEmpty List!\n");
    }
    else {
      // Enquant não encontrar o final da lista ir printando
      while ( currentPtr != NULL ) {
        printf("%s %d <-> ", currentPtr->name, currentPtr->priority);
        currentPtr = currentPtr->nextPtr;
      }
      puts("");
    }
}
// Função que organiza os grupos com seus temas
void loadThemes(ListNodePtr *sPtr, int numberNames) {
  int count = 0;
  FILE *themesFile;
  char filename[SIZE];
  stringArray themes[SIZE];
  ListNodePtr currentPtr = *sPtr;
  // Pegando o nome do arquivo de temas
  clear();
  puts("\nFile name of themes");
  puts("-------------------------\n");
  puts("Ex temas.txt");
  printf("Name: ");
  scanf(" %s", filename);
  // Abrindo o arquivo .txt
  themesFile = fopen(filename, "r");
  // Caso o arquivo esteja vazio avisar
  if ( themesFile == NULL ){
    clear();
    puts("\nFile can't open.\n");
    // Saia dá função caso esteja vazio
    exit(1);
  }
  else {
    // Enquanto não encontrar o EOF continua o loop
    while ( !feof(themesFile) ){
      fscanf(themesFile, "%s", themes[count].theme);
      count++;
    }
  }
  // Fechando o arquivo
  fclose(themesFile);
  groupDivider(&currentPtr, themes, numberNames,count);
}
void groupDivider(ListNodePtr *sPtr, stringArray themes[SIZE], int numberNames,int numberThemes) {
  // Declaração de variáveis locais
  int option;
  int restMembers;
  int newGroup = 0;
  int newMember = 0;
  int extraNames = 0;
  int numberMembers;
  int numberGroups;
  int question = 0;
  FILE *documentFile;
  ListNodePtr currentPtr;

  currentPtr = *sPtr;
  // Pegando o número de grupos a ser feito
  do {
    clear();
    puts("\nNumbers of Groups");
    puts("-------------------------\n");
    printf("Number: ");
    scanf("%d", &numberMembers);  // &numberGroups
  } while (numberMembers <= 0 || numberMembers > numberNames);
  // Pegando o número de quantos participantes em cada grupo
  numberGroups = numberNames / numberMembers;
  // Caso haja divisão não exata de grupos
  if ( numberNames % numberGroups != 0 ) {
    do {
      // Menu de pergunta no que o usuário deseja fazer
      clear();
      puts("\nDivision of groups not exact!\n");
      puts("\tSELECT ACTION\n");
      puts("-------------------------\n");
      puts("1 - Form a new group");
      puts("0 - Redistribute among groups");
      puts("\n-------------------------\n");
      printf("Number: ");
      scanf("%d", &option);
    // Enquanto ele não escolher alguma dessas opções não sairá do menu
    } while ( option < 0 || option > 1);

    if ( option == 1 ) {
      // Acrecentando um grupo a mais
      newGroup++;
      extraNames++;
    }
    else {
      // Calculando o número de nomes que sobraram
      restMembers = numberNames - (numberMembers * numberGroups);
      // Acrecentando um nome a ser redestribuido
      newMember++;
    }
  }
  // Abrindo o arquivo .txt
  documentFile = fopen("relatorio.txt", "w");
  // Caso o arquivo esteja vazio avisar
  if ( documentFile == NULL ) {
    clear();
    puts("\nFile can't open.\n");
    // Saia dá função caso esteja vazio
    exit(1);
  }
  else {
    int totalGroups = numberGroups + newGroup;
    int aux = 0;
    // Escrevendo a estrutura básica
    fprintf(documentFile, "----------------------------------------------\n");
    fprintf(documentFile, "BSI - ED 2021-1 Equipe Raphael & Sandro\n");
    fprintf(documentFile, "Relação de grupos aleatórios com 2 elementos\n");
    fprintf(documentFile, "----------------------------------------------\n\n");
    // Laço para escrita de até o número de grupos especificados
    for (int count = 0; count < totalGroups; count++) {
      // Caso seja o último grupo e necessite de mais membros que o planejado
      if(count == (totalGroups - 1) && extraNames == 1){
        numberMembers++;
      }
      // Caso chegue no final da array de temas, retorne no inicio
      if(aux > numberThemes - 1){
        aux = 0;
      }
      fprintf(documentFile, "Grupo %d:\n", count + 1);
      fprintf(documentFile, "Tema: %s\n", themes[aux].theme);
      fprintf(documentFile, "Alunos: %s\n", currentPtr->name);
      currentPtr = currentPtr->nextPtr;
      // Devido um nome já ter sido escrito, começa a escrita dos demais acrescentado
      for (int countNames = 1; countNames < (numberMembers + newMember); countNames++) {
        // Caso especial de ter menos nomes pra imprimir do que membros teoricos
        if ( currentPtr != NULL ) {
          fprintf(documentFile, "\t\t\t\t%s\n", currentPtr->name);
          currentPtr = currentPtr->nextPtr;
        }
      }
      // Caso especial de
      if ( (count + 1) == restMembers ) {
        newMember = 0;
      }
      fprintf(documentFile, "\n\n");
      aux++;
    }
    // Escrevendo a estrutura básica
    fprintf(documentFile, "----------------------------------------------\n");
    fprintf(documentFile, "Quantidade de alunos: %d\n", numberNames);
    fprintf(documentFile, "Quantidade de Grupos: %d\n", totalGroups);
    fprintf(documentFile, "----------------------------------------------\n");
  }
  // Fechando o arquivo
  fclose(documentFile);
}
// Função de inserção de um na lista duplamente encadeada
void insertOrder(ListNodePtr *sPtr, char name[SIZE], int priority){
  // Declaração de variavéis locais
  ListNodePtr newPtr = NULL;
  ListNodePtr currentPtr = NULL;
  // Alocando espaço de memória necessário para um nó da lista
  newPtr = malloc(sizeof(ListNode));
  // Caso teve memória para inserção
  if ( newPtr != NULL ) {
    // Inicializando o novo nó
    newPtr->prevPtr = NULL;
    strcpy (newPtr->name, name);
    newPtr->priority = priority;
    newPtr->nextPtr = NULL;
    currentPtr = *sPtr;
    // Caso a lista esteja vazia, o novo nó é o inicio
    if ( currentPtr == NULL ) {
      *sPtr = newPtr;
    }
    // Caso a lista não esteje vazia, inserir de acordo com o caso
    else {
      // Enquanto não chegar no final da lista e a prioridade ser maior, avançe
      while ( (currentPtr->nextPtr) != NULL && priority > (currentPtr->priority) ){
        currentPtr = currentPtr->nextPtr;
      }
      // Caso chegue no fim da lista e precise inserir depois
      if ( (currentPtr->nextPtr) == NULL && priority > currentPtr->priority ) {
        currentPtr->nextPtr = newPtr;
        newPtr->prevPtr = currentPtr;
      }
      // Caso chegue no fim e precise inserir antes
      else if ( (currentPtr->prevPtr) == NULL && priority < currentPtr->priority){
        newPtr->nextPtr = currentPtr;
        currentPtr->prevPtr = newPtr;
        *sPtr = newPtr;
      }
      // Caso de inserção normal no meio, inserindo antes
      else {
        newPtr->nextPtr = currentPtr;
        newPtr->prevPtr = currentPtr->prevPtr;
        currentPtr->prevPtr->nextPtr = newPtr;
        currentPtr->prevPtr = newPtr;
      }
    }
  }
// Caso não houve memória para o nó
  else {
    clear();
    puts("Memory Overflow!\n");
  }
}
