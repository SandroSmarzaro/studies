#include <stdio.h>
int main(void) {
  FILE *clientePtr;
  if ((clientePtr = fopen("clientes.txt", "r")) == NULL){
    puts("Error ao abrir arquivo!");
  }else{
    unsigned int conta;  // 00000000 11111111111111111111111111111111
		char nome[20];
		double saldo;
		puts("Conta  Nome              Saldo");
    fscanf(clientePtr,"%d %19s %lf", &conta, nome, &saldo);
		while (!feof(clientePtr)){
      printf("%-6d %-15s %8.2lf\n", conta, nome, saldo);
      fscanf(clientePtr,"%d %19s %lf", &conta, nome, &saldo);
    }
    fclose(clientePtr);
  }
  return 0;
}
