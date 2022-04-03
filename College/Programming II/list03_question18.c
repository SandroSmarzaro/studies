#include <stdio.h>

#define SIZE 3

int main(){
    int array[SIZE];
    int bigger;
    int smaller[2];
    
    for(int count = 0; count < SIZE; count++){
        do{
            scanf("%d", &array[count]);
        }while(array[count] <= 0);
    }
    for(int count = 0; count < SIZE; count++){
        if(count == 0){
            bigger = array[count];
        }
        else if(array[count] >= bigger){
            smaller[count - 1] = bigger;
            bigger = array[count];
        }
        else if(array[count] < bigger){
            smaller[count - 1] = array[count];
        }
    }
    if(smaller[0] + smaller[1] >= bigger){
        printf("\nTriangle\n");
    }
    else{
        printf("\nNot triangle\n");
    }

    return 0;
}