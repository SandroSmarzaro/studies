#include <stdio.h>

int maiorNumero(int n1, int n2);

int main(){

    int number1, number2, result;

    printf("Enter the first number:\n");
    scanf("%d", &number1);
    system("cls");

    printf("Enter the second number:\n");
    scanf("%d", &number2);
    system("cls");

    result=maiorNumero(number1, number2);

    printf("The biggest number is: %d", result);

    return 0;
}

int maiorNumero(int n1, int n2){

    int result;

    if(n1>n2){

        result=n1;
    }
    else{

        result=n2;
    }

    return result;
}