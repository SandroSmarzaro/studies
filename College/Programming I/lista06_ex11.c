#include <stdio.h>
#include <math.h>

int main(){

    int squad, cube, factorial=1, num_divisor=0;

    printf("Number  Squad   Cube    Factorial   Divisors    Prime\n");
    
    for(int num=1; num<=100; num++){

        if(num%10==0){

            printf("Number  Squad   Cube    Factorial   Divisors    Prime\n");
        }
        
        printf("%i         ",num);

        squad= pow(num,2);

        printf("%i      ",squad);

        cube= pow(num, 3);

        printf("%i          ",cube);

        for(int i=num;i>=1;i--){

            factorial=factorial*i;
        }

        printf("%i          ",factorial);

        factorial=1;

        for(int i=1; num>=i;i++){

            if(num%i==0){

                num_divisor++;
            }
        }

        printf("%i          ",num_divisor);

        num_divisor=0;

        for(int i=1;num>=i;i++){

            if(num%i==0){

                num_divisor++;
            }
        }

        if(num_divisor==1 || num_divisor==2){

            printf("True\n");

        }
        else{

            printf("False\n");

        }

        num_divisor=0;    
    }

    return 0;
}