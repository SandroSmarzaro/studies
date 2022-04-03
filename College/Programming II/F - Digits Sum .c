#include <stdio.h>

int main(){
    int number;
    int sum = 0;

    scanf("%d", &number);
    while(number > 0){
        int last_digit = number % 10;
        sum += last_digit;
        number /= 10; 
    }
    if(sum < 10){
        sum *= 10;
    }
    printf("%d", sum);

    return 0;
}