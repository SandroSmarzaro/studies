#include <stdio.h>

int main(){
    int size;
    char character;

    scanf("%d", &size);
    scanf(" %c", &character);
    puts("");
    for(int count = 0; count < size; count++){
        for(int count2 = 0; count2 < size; count2++){
            printf("%c   ", character);
        }
        puts("");
    }
    return 0;
}