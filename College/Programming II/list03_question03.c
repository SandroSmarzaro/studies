#include <stdio.h>

#define sentinel 9999

int main(){
    int number;
    int sum = 0;
    int total = 0;
    float avarage;

    while(number != sentinel){
        scanf("%d", &number);
        sum += number;
        total++;
    }
    sum -= sentinel;
    total--;
    avarage = (float) sum / total;
    printf("\n\n%.2f\n", avarage);

    return 0;
}