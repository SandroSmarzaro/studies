#include <stdio.h>

#define SIZE 3
float bigger(float number[SIZE]);

int main(){
    float array[SIZE];
    float result;

    for(int count = 0; count < SIZE; count++){
        scanf(" %f", &array[count]);
    }
    result = bigger(array);
    printf("\nBigger: %.3f\n", result);

    return 0;
}

float bigger(float number[SIZE]){
    float big = number[0];

    if(number[1] > big){
        big = number[1];
    }
    if(number[2] > big){
        big = number[2];
    }

    return big;
}