#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 7500

int main(){
    int raffle;
    int  static repetition[6];
    float percentage[6];

    srand(time(NULL));
    for(int round = 0; round < 10; round++){    
        printf("-------------------------------------------ROUND %d ----------------------------------", round+1);
        for(int count = 0; count < max; count++){
            raffle = (rand() % 6) + 1;
            if(count % 75 == 0){
                puts(" ");
            }
            printf("%d  ", raffle);
            repetition[raffle - 1]++; 
        }
        puts(" ");
        for(int count = 0; count < 6; count++){
            percentage[count] =  (repetition[count] / (float) max) * 100;
            printf("\nthe percentage of %d is: %.2f %% with %d times\n", count+1, percentage[count], repetition[count]);
        }
        printf("\n\n");
    }
    return 0;
}