#include <stdio.h>

#define PASSAGEM 10
#define MAX_VAGAO 40
#define CUSTO_VAGAO 200

int main() {
    int numeroPassageiros;
    int numeroVagoes = 1;
    float lucro;
    
    printf("Informe a quantidade de passageiros\n");
    scanf("%d", &numeroPassageiros);
    
    if (numeroPassageiros % MAX_VAGAO == 0)
        numeroVagoes = numeroPassageiros / MAX_VAGAO;
    else 
        numeroVagoes = (numeroPassageiros / MAX_VAGAO) + 1;
    lucro = numeroPassageiros * PASSAGEM - numeroVagoes * CUSTO_VAGAO;
    printf("%d vagões\n", numeroVagoes);
    printf("R$ %.2f\n", lucro);
    return 0;
}