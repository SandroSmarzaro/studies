#include <stdio.h>

int main(){

    int i=1;
    float salary, salary_increase=0, discount=0;
    char name;

    while(i!=0){
        printf("Enter your name:\n");
        scanf("%c",&name);
        system("cls");
        
        printf("Enter your current salary:\n");
        scanf("%f",&salary);
        system("cls");

        if(salary>0){
            
            if(salary<998){
                discount=0.1;
                salary_increase= (salary*discount)+salary;
                printf("The functionary %c had increase of 10 por cent\n", name);
                printf("with current salary of %.2f $ that change to %.2f $.\n",salary, salary_increase);
            }
            else if(salary<1200){
                discount=0.6;
                salary_increase= (salary*discount)+salary;
                printf("The functionary %c had increase of 6 por cent\n", name);
                printf("with current salary of %.2f $ that change to %.2f $.\n",salary, salary_increase);
            }
            else if(salary<1500){
                discount=0.4;
                salary_increase= (salary*discount)+salary;
                printf("The functionary %c had increase of 4 por cent\n", name);
                printf("with current salary of %.2f $ that change to %.2f $.\n",salary, salary_increase);
            }
            else if(salary<1800){
                discount=0.2;
                salary_increase= (salary*discount)+salary;
                printf("The functionary %c had increase of 2 por cent\n", name);
                printf("with current salary of %.2f $ that change to %.2f $.\n",salary, salary_increase);
            }
            else{
                discount=0;
                salary_increase=salary;
                printf("The functionary %c had increase of 0 por cent\n", name);
                printf("with current salary of %.2f $ that change to %.2f $.\n",salary, salary_increase);
            }
        }
        else{
            printf("Value of salary invalid!\n");
        }
        printf("\n");
        printf("Do you want to continue?\n");
        printf("<1> YES         <0> NO\n");
        scanf("%i",i);
    }

    return 0;
}