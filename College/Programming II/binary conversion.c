#include <stdio.h>

int main(){
    int number;
    int rest;
    int size = 16;
    int binary[size];
    int end = 0;

    puts("Enter your number:");
    scanf("%d", &number);
    do{
        rest = number % 2;
        binary[end] = rest;
        number = number / 2;
        end++;
    }while(number>0);

    for(int count = end - 1; count >= 0; count--){
        printf("%d", binary[count]);
    }

    return 0;
}