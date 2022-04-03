#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char name[20], marital_status[2];
    int age, size_name;
    float income;

    printf("Enter the name:\n");
    scanf("%s",name);
    system("cls");

    printf("Enter the age:\n");
    scanf("%i",&age);
    system("cls");

    printf("Enter the income:\n");
    scanf("%f",&income);
    system("cls");

    printf("Enter the marital status:\n");
    scanf("%s",marital_status);
    system("cls");

    size_name=strlen(name);

    if(size_name<3){

        printf("Name %s is INVALID! (The name requires at least 3).\n",name);
    }
    else{

        printf("Name %s is VALID!\n",name);
    }

    if(age>=16 && age<=130){

        printf("Age %i old is VALID!\n", age);
    }
    else{

        printf("Age %i old is INVALID! (Age must be between 16 to 130 years).\n", age);
    }

    if(income>= 1045){

        printf("Income %.2f $ is VALID!\n", income);
    }
    else{

        printf("Income %.2f $ is INVALID! (Income must be greater than 1045 $).\n", income);
    }

    switch (tolower(marital_status[0])){

        case 's':
        case 'c':
        case 'd':
        case 'v':

            printf("Marital Status %s is VALID!\n", marital_status);

            break;
        
        default:

            printf("Marital Status %s is INVALID! (Marital status must be equal to S, C, D or V.)\n",marital_status);
    }

    return 0;
}