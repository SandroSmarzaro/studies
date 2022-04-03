#include <stdio.h>

int main(){

    int max=500;
    float result, divisor=5;

    for(int num=1; num<=500; num++){

        result=num/divisor;

        printf("Number: %d and Result: %.3f\n",num, result);
    }

    return 0;
}