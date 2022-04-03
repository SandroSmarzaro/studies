#include <stdio.h>

void exibirMenu();

float somar(float sum1, float sum2);

float subtarir(float subtract1, float subtract2);

float multiplicar(float multiply1, float multiply2);

float dividir(float divide1, float divide2);

int main(){

    int option;
    float num1, num2, result;
    char final='s';
    
    while(final=='s'){
        
        exibirMenu();

        scanf("%d", &option);

        system("cls");

        printf("Enter the first number:\n");
        scanf("%f", &num1);
        system("cls");

        printf("Enter the second number:\n");
        scanf("%f", &num2);
        system("cls");
        
        switch (option){

            case 1:

                result=somar(num1, num2);

                break;

            case 2:

                result=subtarir(num1, num2);

                break;

            case 3:

                result=multiplicar(num1, num2);

                break;

            case 4:

                result=subtarir(num1, num2);

                break;

            default:

                printf("Number of option invalid!\n");

                break;
        }
        
        if(option>=1 && option<=4){
            
            printf("Your result is: %f\n", result);
        }

        printf("\nDo you like continue?\n");
        printf("<s> YES          <n> NO\n");

        scanf("%s", &final);

        system ("cls");
    }
    
    return 0;
}

void exibirMenu(){

    printf("############ CALCULADORA #############\n");
    printf("######## DIGITE 1 PARA SOMAR #########\n");
    printf("###### DIGITE 2 PARA SUBTRAIR ########\n");
    printf("##### DIGITE 3 PARA MULTIPLICAR ######\n");
    printf("####### DIGITE 4 PARA DIVIDIR ########\n");
    printf("######################################\n");
}

float somar(float sum1, float sum2){

    float result;

    result=sum1+sum2;

    return result;
}

float subtarir(float subtract1, float subtract2){

    float result;

    result=subtract1-subtract2;

    return result;
}

float multiplicar(float multiply1, float multiply2){

    float result;

    result=multiply1*multiply2;

    return result;
}

float dividir(float divide1, float divide2){

    float result;

    result=divide1*divide2;

    return result;
}