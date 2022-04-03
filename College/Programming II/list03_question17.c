#include <stdio.h>

#define SIZE 10

int main(){
    int array[SIZE];
    int repetition = 0;

    for(int count = 0; count < SIZE; count++){
        scanf("%d", &array[count]);
    }
    for(int count = 0; count < SIZE; count++){
        if(array[count] == array[9]){
            repetition++;
        }
    }
    printf("\n%d\n", repetition);

    return 0;
}