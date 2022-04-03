#include <stdio.h>

int power(int base, int exponent);

int main(void){
    int baseMain;
    int exponentMain;
    int result;
    
    printf("Base and Exponent:");
    scanf("%d %d", &baseMain, &exponentMain);
    result = power(baseMain, exponentMain);
    printf("Result: %d\n", result);

    return 0;
}

int power(int base, int exponent){
    int product = 1; 

    for(int count = 0; count < exponent; count++){
        product *= base;
    }

    return product;
}