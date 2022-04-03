#include <stdio.h>

int main(){

    int discount=0;
    float salary, salary_increase=0;
    char name;

    printf("Enter your name:\n");
    scanf("%c",&name);
    system("cls");
        
    printf("Enter your current salary:\n");
    scanf("%f",&salary);
    system("cls");
    
    if(salary>0){

        if(salary<998){

            discount=10;
        }

        else if(salary<1200){

            discount=6;
        }

        else if(salary<1500){

            discount=4;
        }

        else if(salary<1800){

            discount=2;
        }
    }
    
    else{

        printf("Value of salary invalid!\n");
    }

    salary_increase= (salary*(discount/100))+salary;

    printf("The functionary %c had increase of %i por cent\n", name, discount);
    printf("with current salary of %.2f $ that change to %.2f $.\n",salary, salary_increase);

    return 0;
}