#include <stdio.h>
#include <ctype.h>
#include <math.h>

void imprimeEspaco(char *frasePtr);
void imprimeEspacoPtr(char *frasePtr);
void converteMaiusculo(char *frasePtr);
void printArray(int *vetor);
long valorMaximo(int bytes);
void copiarString(const char *string,char *string2);
void copiarStringFor(const char *string1, char *string2);
void copiarStringPonteiro(const char *string1, char *string2);
int main(void) {
	char texto1[20] = "Programacao II";
	char texto2[20];
	char texto3[20] = "Programacao";
	char texto4[20];
  char olaMundo[] = "Ola Mundo!";
	int vetor[] = {10, 10, 12, 13, 17, 22, 30, -1}; /* flag fim de lista */
	int tamanho = 4;
	int i;
	long j;
	char c;
  imprimeEspaco(olaMundo);
  imprimeEspacoPtr(olaMundo);
	converteMaiusculo(olaMundo);
  imprimeEspacoPtr(olaMundo);
  printArray(vetor);
  //copiarString(texto1, texto2);
  //copiarStringFor(texto3, texto4);
  copiarStringPonteiro(texto1, texto2);
  copiarStringPonteiro(texto3, texto4);
	puts("");
  imprimeEspaco(texto2);
  imprimeEspaco(texto4);

	printf("\n%c\n", toupper('a'));

	printf("\ntamanho de i: %lu, %lu\n", sizeof i, sizeof(int) );
	printf("\ntamanho de j: %lu, %lu\n", sizeof j, sizeof(long) );
	printf("\ntamanho de c: %lu, %lu\n", sizeof c, sizeof(char) );
	printf("\ntamanho de c: %lu, %lu   ", sizeof(vetor), sizeof(int) );
	printf(" Número de Itens: %lu \n", sizeof(vetor) / sizeof(int) );
	printf("\n\nFaixa de valores em %lu", valorMaximo(4));

  return 0;
}

void imprimeEspaco(char *frasePtr){
  int i = 0;
  puts("");
  while(frasePtr[i] != '\0'){
    printf("%c ", frasePtr[i]); 
    i++;
  }
	puts("");
}

void imprimeEspacoPtr(char *frasePtr){
	while (*frasePtr != '\0'){
		printf("%c ",*frasePtr);
    frasePtr++; 
	}
	puts("");
}
                                           
void printArray(int *vetor){
  while(*vetor > 0){
    printf("%d ",*vetor);
    vetor++;
  }
}

void converteMaiusculo(char *frasePtr){
  while(*frasePtr != '\0'){
    if(islower(*frasePtr) ){
      *frasePtr = toupper(*frasePtr);
    }
    frasePtr++;
  }
}

long valorMaximo(int bytes){
  return pow(2,bytes*8);
}

void copiarString(const char *string1, char *string2){
  int i = 0;
  while(string1[i] != '\0'){
    string2[i] = string1[i];
    i++;
  }
}

void copiarStringFor(const char *string1, char *string2){  //string1 P r o g r a m a c a o \0
	for(int i = 0; (string2[i] =  string1[i]); i++); 
	// for não tem nada no corpo do loop
}

void copiarStringPonteiro(const char *string1, char *string2){
	for(; (*string2 = *string1); string1++, string2++); 
	// for não tem nada no corpo do loop
}

//  inicio(1)
//  # [1 (10)] x $ $ [233 (NULL) ]# f T $  [23(5) ]
  
// 	int vetor[] = {10, 10, 12, 13, 17, 20, 12, -1}; /* flag fim de lista 
// 
// pos * tamanho(tipo) na memória
//
// * -> referencia indireta a uma posição de memória
// int a = 10; a 0x12312   -> 00000000 00000000 00000000 00001010
//
// int *aPtr; aPtr 0x13a20 -> lixo

// aPtr = &a; aPtr 0x13a20 -> 0x12312

// *aPtr -> (0x12312) -> 10



//(a > 0 ? V: F); operador ternário
// V = 'Verdadeiro'
// F = 'Falso'
//string[0]
/*        |
string1 P r o g r a m a c a o \0
          |
string2 P



banana\0
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   int bin[8]; // <---------------
   int aux;

   printf("Digite o número (base decimal) para ser convertido: ");
   scanf("%d", &num);

   for (aux = 7; aux >= 0; aux--)
   {
      if (num % 2 == 0)
         bin[aux] = 0;
      else
         bin[aux] = 1;
      num = num / 2;
   }

   for (aux = 0; aux < 8; aux++)
       printf("%d", bin[aux]);

   printf("\n");

   return 0;
}

copiar o string1 para o string2 usando vetor com referência direta

copiar o string3 para o string4 usando ponteiros

0000 = 0

1111 = f = 15

1111 0000 f0
1111 0100 f4
1111 1000 f8
(a > 0 ? V: F);
1
10

00000000
01111100 * 2  == * 10
01000100 * 2  == * 10
00100010
00100010
00 10001 /2 == /10
00011111 /2 == /10
00000000

int v[4] = {10, 12, 2, 3}
int *vPtr = v
 0x1000     0x1004     0x1008 
  &v[0]      &v[1]      &[2]

vPtr++

https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
islower() 

toupper()


Valor
vetor -> (copia de todos os elementos)

Referência (* ref indireta)(padrao)
vetor -> (trabalha no endereço do vetor)


// 'O','l','a',' ','M','u','n','d','o','\0'

   [O],[l],[a],[ ],[M],[u],[n],[d[,[o],[\0]
    | 
   frasePtr++

	 sizeof()
*/
