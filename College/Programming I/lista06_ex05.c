#include <stdio.h>

int main(){

    int num, num_even=0, num_odd=0, sum_num=0, sum_even=0, sum_odd=0;
    float  average_num, average_even, average_odd;

    for(int i=1;i<=5;i++){

        printf("Enter a number:\n");
        scanf("%i",&num);
        system("cls");

        sum_num= sum_num + num;

        if(num%2==0){
            num_even++;
            sum_even= sum_even+num;
        }
        else{
            num_odd++;
            sum_odd= sum_odd+num;
        }
    }

    average_num= sum_num/5.0;
    average_even= sum_even/5.0;
    average_odd= sum_odd/5.0;

    printf("The numbers of even numbers are: %i\n", num_even);
    printf("The numbers of odd numbers are: %i\n", num_odd);
    printf("The average of numbers is: %.2f\n", average_num);
    printf("The average of even numbers is: %.2f\n", average_even);
    printf("The average of odd numbers is: %.2f\n", average_odd);

    return 0;
}