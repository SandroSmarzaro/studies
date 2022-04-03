#include <stdio.h>
#include <math.h>

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
                printf("Saindo do sistema...\n\n");
                break;
            case 1:
                cadastrar();
                break;
            case 2:
                if(topo > -1){
                    simular();
                }
                else{
                    printf("Nao ha nenhuma quantia para fazer a simulacao!\n\n");
                }
                break;
            default:
                printf("Opcao invalida! Repita.\n\n");
                break;
        }
    } while (option != 0);
    

    return 0;
}

int menu () {
    int option;

    puts("SELECIONE A ACAO");
    puts("");
    puts("--------------------");
    puts("# 1 - Cadastrar");
    puts("# 2 - Simulacao");
    puts("# 0 - Sair");
    puts("--------------------");
    printf("\n\nACAO: ");
    scanf ("%d", &option);
    puts("");
    system("cls");

  return option;
}
void cadastrar(){
    int quantidadeVendida;

    puts("Quantidade vendida neste ano:");
    printf("---> ");
    do{
        scanf("%d", &quantidadeVendida);
    }while(quantidadeVendida < 0);
    puts("");
    system("cls");
    topo++;
    registro[topo] = quantidadeVendida;   
}

void simular(){
    int opcao;
    int limite = topo + 1;
    int ultimoIndex = topo;
    float somaQuantia = 0;
    float somaPesos = 0;
    float peso = 0.5;
    float sugestao;

    if (limite >= 4){
        limite = 4;
    }
    for (int index = 0; index < limite; index++){
        somaQuantia += (float)registro[ultimoIndex] * peso;
        somaPesos += peso;
        peso -= 0.15;
        ultimoIndex--;
    }
    sugestao = somaQuantia / somaPesos;
    puts("Arrendodar para cima ou baixo?");
    printf("\n[1]\tCIMA\t\t[0]\tBAIXO\n\n");
    printf("---> ");
    do{
        scanf("%d", &opcao);
    }while (opcao != 0 && opcao != 1);
    if (opcao){
        sugestao = ceil(sugestao);
    }
    else{
        sugestao = floor(sugestao);
    }
	printf("\n-------------------------------------\n");
    printf("Quantidade sugerida: %.0f\n", sugestao);
    printf("-------------------------------------\n\n\n");
}