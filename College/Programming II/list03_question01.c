#include <stdio.h>

int main(){
    int half = 5;

    for(int count = 1; count <= half; count++){
        for(int count2 = 0; count2 < (half - count); count2++){
            printf(" ");
        }
        for(int count3 = 0; count3 < ((2 * count) - 1); count3++){
            printf("*");
        }
        printf("\n");
    }
    for(int count = 1; count <= half; count++){
        for(int count2 = 0; count2 < count; count2++){
            printf(" ");
        }
        for(int count3 = 0; count3 < (2 * (half - count) - 1); count3++){
            printf("*");
        }
        printf("\n");
    }


    return 0;
}