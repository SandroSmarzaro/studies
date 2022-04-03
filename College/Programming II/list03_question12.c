#include <stdio.h>

int inverse(int number);

int main(){
    int num;
    int result;
    
    scanf("%d", &num);
    result = inverse(num);
    printf("\n%d\n", result);

    return 0;
}

int inverse(int number){
    int unit;
    int ten;
    int hundred;

    unit = (number % 1000) / 100;
    ten = (number % 100) / 10;
    hundred = number % 10;

    return hundred * 100 + ten * 10 + unit;
}