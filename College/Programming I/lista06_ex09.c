#include <stdio.h>
#include <math.h>

int main(){

    int perfect_num, divisor=1, sum_divisor=0;

    for(int n=1;n<=7;n++){

        perfect_num = (pow(2,n-1))* ((pow(2,n))-1);

        while(perfect_num>divisor){

            if(perfect_num%divisor==0){
                
                sum_divisor=sum_divisor+divisor;
                
            }
        divisor++;
        }
    
        if(perfect_num==sum_divisor){
                    
            printf("%i ", perfect_num);
        }

    divisor=1;
    sum_divisor=0;
    }
    
    return 0;
}