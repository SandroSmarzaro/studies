#include <stdio.h>

#define MAX_CARROS 15
#define VALOR_DIA_ALUGUEL 250
#define PRECO_GASOLINA 6.8

int main () {
    int kmPercorridos[MAX_CARROS];
    int litrosConsumidos[MAX_CARROS];
    float consumoMedio[MAX_CARROS];
    int quantidadeDias;
    int distanciaRequerida;

    for (int index = 0; index < MAX_CARROS; index++) {
        printf("Digite a quantidade de km percorridos pelo carro %d: ", index + 1);
        scanf(" %d", &kmPercorridos[index]);
        printf("Digite a quantidade de litros de combustivel consumidos pelo carro %d: ", index + 1);
        scanf(" %d", &litrosConsumidos[index]);
        consumoMedio[index] = (kmPercorridos[index] / 1.0) / litrosConsumidos[index];
    }
    printf("Digite a quantidade de dias que o carro ficara alugado: ");
    scanf(" %d", &quantidadeDias);
    printf("Digite a distancia que o carro deverá percorrer: ");
    scanf(" %d", &distanciaRequerida);

    int posicaoMaisEconomica;
    for (int index = 0; index < MAX_CARROS; index++) {
        if (index == 0)
            posicaoMaisEconomica = 0;
        else if (consumoMedio[index] > consumoMedio[posicaoMaisEconomica])
            posicaoMaisEconomica = index;
    }
    int valorTotalAluguel = quantidadeDias * VALOR_DIA_ALUGUEL;
    float valorTotalCombustivel = consumoMedio[posicaoMaisEconomica] * PRECO_GASOLINA;
    float gastoTotal = valorTotalCombustivel + valorTotalAluguel;

    printf(
        "Seu gasto toal será de R$ %.2f.\nSendo %.2f da gasolina\nE %.2f do aluguel\n", 
        gastoTotal, valorTotalCombustivel, valorTotalAluguel
    );
    
    return 0;
}