#include <stdio.h>

int main() {
    int numeroPartidas;
    int setsVencidos;
    int setsPerdidos;
    int setsVencidosTotal = 0;
    int pontos = 0;

    printf("Informe o número de partidas do Sada Cruzeiro\n");
    scanf(" %d", &numeroPartidas);

    for(int partida = 1; partida <= numeroPartidas; partida++) {
        setsVencidos = 0;
        setsPerdidos = 0;
        printf("Informe o número de sets vencidos pelo Sada Cruzeiro na partida %d\n", partida);
        scanf(" %d", &setsVencidos);
        printf("Informe o número de sets vencidos pelo adversário na partida %d\n", partida);
        scanf(" %d", &setsPerdidos);

        setsVencidosTotal += setsVencidos;
        if (setsVencidos == 3) {
            if (setsPerdidos == 0 || setsPerdidos == 1) {
                pontos += 3;
            }
            else if (setsPerdidos == 2) {
                pontos += 2;
            }
        }
        else if (setsVencidos == 2 && setsPerdidos == 3) {
            pontos += 1;
        }
    }
    
    printf("Pontos: %d\n", pontos);
    printf("Sets vencidos: %d\n", setsVencidosTotal);

    return 0;
}