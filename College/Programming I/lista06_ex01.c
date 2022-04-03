#include<stdio.h>

int main(){

    int num;

    printf("Digite um numero:\n");
    scanf("%i",&num);

    if(num<0){
        printf("O numero e negativo.\n");
    }
    else if(num==0){
        printf("O Numero e igual a zero.\n");
    }
    
    else{
        if(num%2==0){
            printf("O numero e par.\n");
        }
        else{
            printf("O numero e impar.\n");
        }
    }

    return 0;
}