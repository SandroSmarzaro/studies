#include <stdio.h>

#define VALOR_QUESTAO 80
#define DESCONTO 0.05

int main() {
    int numeroQuestoes;
    int numeroHoras;
    float notaObtida;
    float valorEntrada;
    float valorQuestoes;
    float valorDesconto;
    float valorSegundaParcela;
    float valorTaxa;
    float valorTotal;
    
    printf("Informe o número de questões da prova\n");
    scanf("%d", &numeroQuestoes);
    printf("Informe o número de horas para realização da prova\n");
    scanf("%d", &numeroHoras);
    printf("Informe a nota obtida pelo aluno\n");
    scanf("%f", &notaObtida);

    valorQuestoes = numeroQuestoes * VALOR_QUESTAO;
    valorDesconto = (numeroHoras * DESCONTO) * valorQuestoes;
    valorEntrada = valorQuestoes - valorDesconto;

    if (notaObtida > 8)
        valorTaxa = 1;
    else if (notaObtida > 6)
        valorTaxa = 0.95;
    else if (notaObtida > 4)
        valorTaxa = 0.90;
    else if (notaObtida > 2)
        valorTaxa = 0.85;
    else
        valorTaxa = 0.80;
    
    valorSegundaParcela = valorEntrada * valorTaxa;
    valorTotal = valorEntrada + valorSegundaParcela;
    printf("Valor Total: %.2f\n", valorTotal);

    return 0;
}