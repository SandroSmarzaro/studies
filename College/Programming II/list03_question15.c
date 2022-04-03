#include <stdio.h>

int main(){
    int size;
    int smaller;
    int first = 0;

    scanf("%d", &size);
    int array[size];
    for(int count =0; count < size; count++){
        scanf("%d", &array[count]);
        if(array[count] % 2 == 0){
            first++;
            if(first == 1){
                smaller = array[count];
            }
            if(smaller > array[count]){
                smaller = array[count];
            }
        }
    }
    printf("\nThe smaleer even: %d\n", smaller);
    
    
    return 0;
}