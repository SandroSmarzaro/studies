#include <stdio.h>

int main(){
    int numbers[2];
    int rest;

    scanf("%d %d", &numbers[0], &numbers[1]);
    rest = numbers[0];
    do{
        rest -= numbers[1];
    }while(rest > 1);
    printf("\n%d\n", rest);

    return 0;
}