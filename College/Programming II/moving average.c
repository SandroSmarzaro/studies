#include <stdio.h>

#define TAMANHO 100

int registro[TAMANHO];
int topo = -1;

int menu ();
void cadastrar();
void simular();

int main(){
    int option;
    do{
        option = menu();
        switch (option){
          case 0:
            puts("Saindo do sistema...");
            break;
          case 1:
            cadastrar();
            break;
          case 2:
            simular();
            break;
          default:
            puts("Opcao invalida! Repita.");
            break;
        }
    } while (option != 0);
    

    return 0;
}

int menu () {
    int option;

    printf("\nSELECIONE A ACAO\n\n");
    puts("--------------------");
    puts("# 1 - Cadastrar");
    puts("# 2 - Simulacao");
    puts("# 0 - Sair");
    puts("--------------------");
    printf("\nACAO: ");
    scanf ("%d", &option);
    puts("");

  return option;
}
void cadastrar(){
  int quantidadeVendida;

  puts("Quantidade vendida neste ano:");
  printf("---> ");
  do{
    scanf("%d", &quantidadeVendida);
  }while(quantidadeVendida < 0);
    topo++;
    registro[topo] = quantidadeVendida;   
}

void simular(){
  int soma = 0;
  int limite = topo;
  int ultimoIndex = topo;
  float peso = 0.5;

  if (limite >= 4){
    limite = 4;
  }
  for (int index = 0; index < limite; index++){
    soma += registro[ultimoIndex] * peso;
    peso -= 0.15;
    ultimoIndex--;
  }
	
  printf("\nQuantidade sugerida: %d\n", soma);
}