#include <stdio.h>

int main(){

    int max=50, vector[max];

    srand(time(NULL));
    
    for(int count=0; count<max; count++){

        vector[count]= rand()%16;

        if(vector[count]==10){

            printf("The position %d in vector is equal than 10.\n", count);
        }
    }

    return 0;
}