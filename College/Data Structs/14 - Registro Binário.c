/*
	Programa que grava um registro em um arquivo Binário existente
	em uma determinada posição, buscada com o comando
	Exemplo do Deitel.


*/
#include <stdio.h>
#define MAX 15
struct contaCliente{
  unsigned int NConta;
  char nome[MAX];
  char sobrenome[MAX];
	double saldo;
};
int main(){
	FILE *contasPtr;
	if((contasPtr = fopen("contas.dat", "rb+")) == NULL){
    printf("Nao foi possivel criar o arquivo\n");
  } else {
    struct contaCliente  cliente = {0, "", "", 0};
    printf("Entre com  a conta(1 a 100 para cadastrar.\n"
		       "Digite 0 caso queira sair:\n");
    scanf("%u",&cliente.NConta); // 00000000 00000000 00000000 00010000 -> 16
		while(cliente.NConta != 0){
      printf("Entre com o nome sobrenome saldo: \n");
			fscanf(stdin, "%s %s %lf", cliente.nome, cliente.sobrenome, &cliente.saldo);
			//
			fseek(contasPtr,(cliente.NConta - 1) * sizeof(struct contaCliente) ,SEEK_SET);
			fwrite(&cliente, sizeof(struct contaCliente), 1, contasPtr);
			//
			printf("Entre com  a conta(1 a 100 para cadastrar.\n"
						"Digite 0 caso queira sair:\n");
			scanf("%u",&cliente.NConta);			
    }
    fclose(contasPtr);
  }
return 0;
}
/*
for (int i = 10; i < 20; i++){
	printf("%d", i);
}
O(9) -> O(1)

O(9n) -> O(n)

O(1)
0 1 
1 2 Fulano Silva 50000
2 3 
3 4 Maria Vargas 4355
4 5 maria vargas 4500
5 6 
6 7


nome
 0    3    6    9                  
[123][456][789][ABC]
 ---  ---  ---  ---
  0    1    2    3

nome[2] = 789 --> posicao * tamanho --> 2 * 3 --> 6
*/




