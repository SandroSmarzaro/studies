#include <stdio.h>

int evenSum(int num);
int number = 30;

int main(){
    int result = evenSum(number);
    printf("\n%d\n", result);

    return 0;
}

int evenSum(int num){
    if(num == 0){
        return 0;
    }
    else{
        return num + evenSum(num -2);
    }
    
    
}