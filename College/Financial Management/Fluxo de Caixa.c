#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 50
#define DELAY 1

typedef struct operational_struct
{
    float sales_receipt;
    float salary;
    float providers;
    float taxation;

} operational_type;

typedef struct investment_struct
{
    float sales_permanentAssets;
    float dividend_receipt;
    float asset_acquisition;

} investment_type;

typedef struct financing_struct
{
    float loan_acquisition;
    float dividend_payment;
    float amortization_financing

} financing_type;

typedef struct week_struct
{
    operational_type operational;
    investment_type investment;
    financing_type financing;
    
} week_type;

week_type week[4];
float initialValue = 0;

void exit_menu();
void clear_screen();
void invalid_menu();
void draw_line(int quantity);
int initial_menu();
void inital_value();
int week_menu();
void cashFlow(int week_number);
int show_cashFlow();

int main()
{   
    int initial_option;
    int week_option;
    int cashFlow_option;

    setlocale(LC_ALL, "Portuguese");
    do
    {
        initial_option = initial_menu();
        switch (initial_option)
        {
            case 0:
                exit_menu();
                initial_option = 0;
                break;

            case 1:
                do
                {
                    cashFlow_option = show_cashFlow();
                    if ( cashFlow_option != 0 ) invalid_menu();
                } while ( cashFlow_option != 0 );
                break;
        
            case 2:
                do
                {
                    week_option = week_menu();
                    switch (week_option)
                    {
                        case 0:
                            break;
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            cashFlow(week_option);
                            break;

                        case 5:
                            inital_value();
                            break;

                        default:
                            invalid_menu();
                            break;
                    }
                } while ( week_option != 0 );
                break;
            
            default:
                invalid_menu();
                break;
        }
    } while (initial_option != 0);   

    return 0;
}
void exit_menu()
{
    clear_screen();
    puts("\n\n");
    draw_line(30);
    puts("\n\n   SAINDO DO SISTEMA...\n");
    draw_line(30);
    puts("\n");
    sleep(DELAY);

}

void clear_screen()
{
    #if defined(__linux__) || defined(__unix__) || defined (__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void invalid_menu()
{
    clear_screen();
    puts("\n\n");
    draw_line(30);
    puts("\n\n   OPCAO INVALIDA!\n");
    draw_line(30);
    puts("\n");
    sleep(DELAY);
}

void draw_line(int quantity)
{
    for (int count = 0; count < quantity; count++)
    {
        printf("-");
    }
}

int initial_menu()
{
    int option;
    
    clear_screen();
    puts("\n   SELECIONE A OPCAO\n");
    draw_line(25);
    puts("\n\n1 - Mostrar Relatorio");
    puts("\n2 - Inserir Item");
    puts("\n0 - Sair\n");
    draw_line(25);
    printf("\n\nACAO: ");
    scanf("%d", &option);

    return option;
}

void inital_value()
{
    clear_screen();
    puts("\n   DIGITE O VALOR INICIAL\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &initialValue);
    draw_line(35);
}

int week_menu()
{
    int option;
    
    clear_screen();
    puts("\n   SELECIONE A OPCAO\n");
    draw_line(25);
    puts("\n\n1 - Primeira Semana");
    puts("\n2 - Segunda  Semana");
    puts("\n3 - Terceira Semana");
    puts("\n4 - Quarta   Semana");
    puts("\n5 - Valor Inicial");
    puts("\n0 - Sair\n");
    draw_line(25);
    printf("\n\nACAO: ");
    scanf("%d", &option);

    return option;
}


void cashFlow(int week_number)
{   
    week_number--;
    clear_screen();
    puts("\n   FLUXO DE CAIXA OPERACIONAL\n");
    draw_line(35);
    puts("\n\n( + ) Recebimento de Vendas\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].operational.sales_receipt);
    clear_screen();
    puts("\n   FLUXO DE CAIXA OPERACIONAL\n");
    draw_line(35);
    puts("\n\n( - ) Salarios\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].operational.salary);
    clear_screen();
    puts("\n   FLUXO DE CAIXA OPERACIONAL\n");
    draw_line(35);
    puts("\n\n( - ) Fornecedores\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].operational.providers);
    clear_screen();
    puts("\n   FLUXO DE CAIXA OPERACIONAL\n");
    draw_line(35);
    puts("\n\n( - ) Impostos\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].operational.taxation);

    clear_screen();
    puts("\n  FLUXO DE CAIXA DE INVESTIMENTO\n");
    draw_line(35);
    puts("\n\n( + ) Vendas de Ativos Permanetes\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].investment.sales_permanentAssets);
    clear_screen();
    puts("\n  FLUXO DE CAIXA DE INVESTIMENTO\n");
    draw_line(35);
    puts("\n\n( + ) Recebimento de Dividendos\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].investment.dividend_receipt);
    clear_screen();
    puts("\n  FLUXO DE CAIXA DE INVESTIMENTO\n");
    draw_line(35);
    puts("\n\n( - ) Aquisicao de Imobilizados\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].investment.asset_acquisition);

    clear_screen();
    puts("\n  FLUXO DE CAIXA DE FINANCIMAENTO\n");
    draw_line(35);
    puts("\n\n( + ) Aquisicao de Emprestimos\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].financing.loan_acquisition);
    clear_screen();
    puts("\n  FLUXO DE CAIXA DE FINANCIMAENTO\n");
    draw_line(35);
    puts("\n\n( - ) Pagamento de Dividendos\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].financing.dividend_payment);
    clear_screen();
    puts("\n  FLUXO DE CAIXA DE FINANCIMAENTO\n");
    draw_line(35);
    puts("\n\n( - ) Amortizacao de Financiamento\n");
    draw_line(35);
    printf("\n\nVALOR: ");
    scanf("%f", &week[week_number].financing.amortization_financing);
}

int show_cashFlow()
{   
    int option;
    char word[30];
    float final_balence = 0;
    float previous_balance[4];
    float operating_balance[4];
    float investment_balance[4];
    float financing_balance[4];
    float period_balance[4];
    float final_period[4];
    float sum_order[14];

    for (int index = 0; index < 14; index++)
    {
        if (index < 4)
        {
            previous_balance[index] = 0;
            operating_balance[index] = 0;
            investment_balance[index] = 0;
            financing_balance[index] = 0;
            period_balance[index] = 0;
            final_period[index] = 0;
        }
        sum_order[index] = 0;
    }
    previous_balance[0] = initialValue;
    for (int index = 0; index < 4; index++)
    {
        operating_balance[index] = week[index].operational.providers + week[index].operational.salary + week[index].operational.sales_receipt + week[index].operational.taxation;
        investment_balance[index] = week[index].investment.asset_acquisition + week[index].investment.dividend_receipt + week[index].investment.sales_permanentAssets;
        financing_balance[index] = week[index].financing.amortization_financing + week[index].financing.dividend_payment + week[index].financing.loan_acquisition;
        period_balance[index] = operating_balance[index] + investment_balance[index] + financing_balance[index];
        final_period[index] = previous_balance[index] + period_balance[index];
        if ( index < 3 ) previous_balance[(index + 1)] = final_period[index];
    }
    for (int index = 0; index < 4; index++)
    {
        sum_order[0] += week[index].operational.providers;
        sum_order[1] += week[index].operational.salary;
        sum_order[2] += week[index].operational.sales_receipt;
        sum_order[3] += week[index].operational.taxation;
        sum_order[4] += week[index].investment.asset_acquisition;
        sum_order[5] += week[index].investment.dividend_receipt;
        sum_order[6] += week[index].investment.sales_permanentAssets;
        sum_order[7] += week[index].financing.amortization_financing;
        sum_order[8] += week[index].financing.dividend_payment;
        sum_order[9] += week[index].financing.loan_acquisition;
        sum_order[10] += operating_balance[index];
        sum_order[11] += investment_balance[index];
        sum_order[12] += financing_balance[index];
        sum_order[13] += period_balance[index];
    }
    final_balence = previous_balance[0] + sum_order[13];
    clear_screen();
    puts("\t\t\t\t\t\tDEMONSTRACAO DE FLUXO DE CAIXA\n");
    draw_line(155);
    printf("\n\n                    SEMANAS                          1a                      2a                      3a                      4a                     TOTAL\n\n");
    draw_line(155);
    strcpy(word, "SALDO ANTERIOR");
    
    printf("\n( = )%30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, previous_balance[0], previous_balance[1], previous_balance[2], previous_balance[3], previous_balance[0]);
    puts("");
    draw_line(155);
    puts("\n\t\t\t\t\t\tFLUXO DE CAIXA OPERACIONAL");
    draw_line(155);
    strcpy(word, "Recebimento de Vendas");
    printf("\n( + ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].operational.sales_receipt, week[1].operational.sales_receipt, week[2].operational.sales_receipt, week[3].operational.sales_receipt, sum_order[2]);
    strcpy(word, "Salarios");
    printf("( - ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].operational.salary, week[1].operational.salary, week[2].operational.salary, week[3].operational.salary, sum_order[1]);
    strcpy(word, "Fornecedores");
    printf("( - ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].operational.providers, week[1].operational.providers, week[2].operational.providers, week[3].operational.providers, sum_order[0]);
    strcpy(word, "Impostos");
    printf("( - ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].operational.taxation, week[1].operational.taxation, week[2].operational.taxation, week[3].operational.taxation, sum_order[3]);
    strcpy(word, "SALDO FLUXO OPERACIONAL");
    printf("\n( = ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, operating_balance[0], operating_balance[1], operating_balance[2], operating_balance[3], sum_order[10]);
    puts("\n");
    draw_line(155);
    puts("\n\t\t\t\t\t\tFLUXO DE CAIXA DE INVESTIMENTO");
    draw_line(155);
    strcpy(word, "Venda de Ativos Permanentes");
    printf("\n( + ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].investment.sales_permanentAssets, week[1].investment.sales_permanentAssets, week[2].investment.sales_permanentAssets, week[3].investment.sales_permanentAssets, sum_order[6]);
    strcpy(word, "Recebimento de Dividendos");
    printf("( + ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].investment.dividend_receipt, week[1].investment.dividend_receipt, week[2].investment.dividend_receipt, week[3].investment.dividend_receipt, sum_order[5]);
    strcpy(word, "Aquisicao de Imobilizados");
    printf("( - ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].investment.asset_acquisition, week[1].investment.asset_acquisition, week[2].investment.asset_acquisition, week[3].investment.asset_acquisition, sum_order[4]);
    strcpy(word, "SALDO FLUXO DE INVESTIMENTO");
    printf("\n( = ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, investment_balance[0], investment_balance[1], investment_balance[2], investment_balance[3], sum_order[11]);

    puts("\n");
    draw_line(155);
    puts("\n\t\t\t\t\t\tFLUXO DE CAIXA DE FINANCIAMENTO");
    draw_line(155);
    strcpy(word, "Aquisicao de Emprestimos");
    printf("\n( + ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].financing.loan_acquisition, week[1].financing.loan_acquisition, week[2].financing.loan_acquisition, week[3].financing.loan_acquisition, sum_order[9]);
    strcpy(word, "Pagamento de Dividendos");
    printf("( - ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].financing.dividend_payment, week[1].financing.dividend_payment, week[2].financing.dividend_payment, week[3].financing.dividend_payment, sum_order[8]);
    strcpy(word, "Amortizacao de Financiamento");
    printf("( - ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, week[0].financing.amortization_financing, week[1].financing.amortization_financing, week[2].financing.amortization_financing, week[3].financing.amortization_financing, sum_order[7]);
    strcpy(word, "SALDO FLUXO DE FINANCIAMENTO");
    printf("\n( = ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, financing_balance[0], financing_balance[1], financing_balance[2], financing_balance[3], sum_order[12]);
    
    strcpy(word,"Saldo Inicial do Periodo");
    puts("");
    draw_line(155);
    printf("\n( = ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, previous_balance[0], previous_balance[1], previous_balance[2], previous_balance[3], previous_balance[0]);
    strcpy(word,"Saldo do Periodo");
    printf("( = ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, period_balance[0], period_balance[1], period_balance[2], period_balance[3], sum_order[13]);
    strcpy(word,"Resultado Final do Periodo");
    printf("( = ) %30s\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\t\t%9.2f\n", word, final_period[0], final_period[1], final_period[2], final_period[3], final_balence);
    draw_line(155);
    puts("\n\n0 - Sair");
    printf("\n\nACAO: ");
    scanf("%d", &option);

    return option;
}