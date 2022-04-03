#include <stdio.h>

int main(){

    int max=10;
    char name[20];
    float salary, percent, increase, new_salary, costs=0.0;
    
    for(int counter=1; counter<=max; counter++){

        printf("Enter the name:\n");
        scanf("%s",name);

        system("cls");

        printf("Enter the salary:\n");
        scanf("%f",&salary);

        system("cls");

        if(salary<=1500.00){

            percent=0.06;
        }else{
            percent=0.04;
        }
        
        increase= salary*percent;
        new_salary= salary+increase;
        costs= costs+increase;
    }

    printf("The costs is: %.3f $\n", costs);

    return 0;
}