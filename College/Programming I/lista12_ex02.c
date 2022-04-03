#include <stdio.h>
#include <math.h>

float calcular(int n);

int main(){

    int num;
    float result;

    printf("Enter the number:\n");
    scanf("%d", &num);
    system("cls");

    result=calcular(num);

    printf("%.2f", result);

    return 0;
}

float calcular(int n){

    int quad;
    float root, quad2, result;
    
    quad=pow(n, 2);

    root=sqrt(quad);

    quad2=pow(root, 4);

    result=quad2*n;

    return result;
}