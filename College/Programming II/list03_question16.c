#include <stdio.h>

void inverse(int vector[], int max);

int main(){
    int size;

    scanf("%d", &size);
    int array[size];
    for(int count =0; count < size; count++){
        scanf("%d", &array[count]);
    }
    puts("");
    for(int count = 0; count < size; count++){
        printf("%3d ", array[count]);
    }
    puts("");
    inverse(array, size);
    
    return 0;
}

void inverse(int vector[], int max){
    int auxiliary;

    for(int count = 0; count < max; count++){
        auxiliary = vector[(max - count) -1];
        vector[(max - count) - 1] = vector[count];
        vector[count] = auxiliary;
    }
    for(int count = 0; count < max; count++){
        printf("%3d ", vector[count]);
    }
    puts("");
}