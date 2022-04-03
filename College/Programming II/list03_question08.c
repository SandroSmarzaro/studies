#include <stdio.h>

int main(){
    int size;
    
    scanf("%d", &size);
    puts("");
    for(int count = 0; count < size; count++){
        for(int count2 = 0; count2 < size; count2++){
            printf("*   ");
        }
        puts("");
    }
    return 0;
}