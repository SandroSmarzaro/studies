#include <stdio.h>
#define size 8 

int main(){

    int number;
    int binary[size];
    int rest;
    int end = 0;

    puts("Number:");
    scanf("%d", &number);
    
    //number > 255 para tratamento do overflow sendo 1111 1111 = 255 o maior número;
    if(number > 255) {
        puts("Overflow!");
    }
    else{
        do{
            rest = number % 2;
            binary[end] = rest;
            number /= 2;
            end++;
        }while(number > 0);

        //se o binário não ocupar todos os espaços completar com 0;
        if(end < size){
            for(int count = end; count <= size; ++count){
                binary[count] = 0;
            }
        }
    
        for(int count = (size - 1); count >= 0; count--){
            printf("%d", binary[count]);
        }
    }

    return 0;
}