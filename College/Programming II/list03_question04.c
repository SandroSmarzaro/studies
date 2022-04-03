#include <stdio.h>

int better(int num);
int bigger = 0;

int main(){
    int max;
    int number;

    scanf("%d", &max);
    for(int count = 0; count < max; count++){
        scanf("%d", &number);
        if(count == 0){
            bigger = number;
        }
        better(number);
    }
    printf("\n%d\n", bigger);

    return 0;
}
int better(int num){ 
    
    if(num > bigger){
        bigger = num;
    }

    return bigger;
}