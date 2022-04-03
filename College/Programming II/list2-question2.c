#include <stdio.h>

int main(){

    float salary;
    float tax;
    float aliquot;
    float deduction;

    puts("Salary:");
    scanf("%f", &salary);

    if(salary < 1903.98){
        aliquot = 0;
        deduction = 0;
    }
    else if(salary < 2826.65){
        aliquot = 0.075;
        deduction = 142.80;
    }
    else if(salary < 3751.05){
        aliquot = 0.15;
        deduction = 354.80;
    }
    else if(salary < 4664.68){
        aliquot = 0.225;
        deduction = 636.13;
    }
    else{
        aliquot = 0.275;
        deduction = 869.36;
    }
    tax = (salary * aliquot) - deduction;

    printf("\nAliquot: %9.2f %%\n", aliquot * 100);
    printf("Deduction: %7.2f\n", deduction);
    printf("Tax: %13.2f\n", tax);

    return 0;
}