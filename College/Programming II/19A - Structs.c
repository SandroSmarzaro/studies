#include <stdio.h>

typedef struct vendaItens {
	int numeroVenda;
	int produto;
	int quantidade;
} tipoVenda;

int fim = 0;

void cadastraVenda(tipoVenda venda[]);
void imprimeVenda(tipoVenda venda[]);
void linha(int tamanho);

int main(void) {
	tipoVenda vendas[100];

	cadastraVenda(vendas);
	cadastraVenda(vendas);
	cadastraVenda(vendas);
	cadastraVenda(vendas);
	imprimeVenda(vendas);

	vendas[1] = vendas[2];
  return 0;
}

void cadastraVenda(tipoVenda venda[] ){ 
	venda[fim].numeroVenda = fim;
	printf("\nProduto: ");
	scanf("%d", &venda[fim].produto);
	fim++;
  system("clear");
}

void imprimeVenda(tipoVenda venda[]){
  puts("Vendas Produto");
	for(int i = 0; i < fim; i++){
    printf("%5d %8d\n",venda[i].numeroVenda, venda[i].produto);
  }
	linha(15);
}

void linha(int tamanho){
	for( int i = 0; i < tamanho; i++){
		printf("-");
	}
	puts("");
}
