#include <stdio.h>

float calcularPotencia(float n, float p);

int main(){

    float number, power, result;

    printf("Enter the number:\n");
    scanf("%f", &number);
    system("cls");

    printf("Enter the power:\n");
    scanf("%f", &power);
    system("cls");

    result=calcularPotencia(number, power);

    printf("The result is: %.2f\n", result);

    return 0;
}

float calcularPotencia(float n, float p){

    float result=1;

    for(int count=1; count<=p; count++){

        result=result*n;

    }

    return result;
}