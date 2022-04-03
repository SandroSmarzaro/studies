#include <stdio.h>

int main(){
    int size;
    int decrease = 0;

    scanf("%d", &size);
    int array[size];
    for(int count =0; count < size; count++){
        scanf("%d", &array[count]);
    }
    for(int count = 0; count < size; count++){
        if(array[count] > array[count + 1]){
            decrease++;
        }
    }
    if(decrease == size - 1){
        printf("\nIs decreasing\n");
    }
    else{
        printf("\nIs not decreasing\n");
    }
    
    return 0;
}