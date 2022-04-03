#include <stdio.h>

int main(){

    int i=1, value_m=0, num_divisior=0, factorial=1, sum_integer=0;

    while(i!=0){
        
        while(value_m<=0){    
        
            printf("Enter the value of m:\n");
            scanf("%i",&value_m);
            system("cls");
        }
        
        if(value_m%2==0){

            for(int divisor=1; value_m>=divisor; divisor++){
                
                if(value_m%divisor==0){
                    
                    num_divisior++;
                }
            }
            printf("The number of divisors is: %i\n",num_divisior);
        }
        else if(value_m%2!=0 && value_m<12){
            
            for(;value_m>=1;value_m--){

                factorial=factorial*value_m;
            }

            printf("The factorial of m is: %i\n", factorial);    
        }
        else{

            for(int integer=1; value_m>=integer; integer++){

                sum_integer=sum_integer+integer;
            }

            printf("The sum of integers of m is: %i\n",sum_integer);
        }

        printf("\nDo you want continue?\n");
        printf("<1> YES     <0> NO\n");
        scanf("%i",&i);
        system("cls");

        value_m=0;
    }
    return 0;
}