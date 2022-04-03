#include <stdio.h>

int main(){

    char city1[20], city2[20];
    float people1, people2, reason1, reason2, years;
    
    printf("Enter the name of first city:\n");
    scanf("%s",city1);
    system("cls");
    
    printf("Enter the name of second city:\n");
    scanf("%s",city2);
    system("cls");

    printf("Enter the numbers people of first city:\n");
    scanf("%f",&people1);
    system("cls");

    printf("Enter the numbers people of second city:\n");
    scanf("%f",&people2);
    system("cls");

    printf("Enter the reason percentage of first city:\n");
    scanf("%f",&reason1);
    system("cls");

    printf("Enter the reason percentage of second city:\n");
    scanf("%f",&reason2);
    system("cls");
    
    years=((people2-people1)/((reason1/100)-(reason2/100)))+1;

    printf("The number of years is: %.1f",years);

    return 0;
}