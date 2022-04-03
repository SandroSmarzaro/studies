#include<stdio.h>

int main(){

    float salary, financing;
    
    printf("Enter you salary:\n");
    scanf("%f",&salary);
    system("cls");

    printf("Enter your financing:\n");
    scanf("%f",&financing);
    system("cls");

    if(financing<=salary*5){
        printf("Financing grated!\n");
    }
    else{
        printf("Financing denied!\n");
    }

    printf("Thanks for using our system!\n");

    return 0;
}