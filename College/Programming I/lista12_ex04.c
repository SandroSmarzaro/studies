#include <stdio.h>

int eh_primo(int num);

int main(){

    int number, result;

    printf("Enter the number:\n");
    scanf("%d", &number);
    system("cls");

    result=eh_primo(number);

    printf("The result is: %d\n", result);

    return 0;
}

int eh_primo(int num){

    int result, divisor=0;

    for(int count=1; count<=num; count++){

        if(num%count==0){

            divisor++;
        }
    }

    if(divisor==2){

        result=1;
    }
    
    else{

        result=0;
    }

    return result;
}