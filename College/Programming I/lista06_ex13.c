#include <stdio.h>

int main(){

    float weight, height, IMC;
    char name[20];

    printf("Enter your name:\n");
    scanf("%s",name);
    system("cls");

    for(int limit=1; name!="sair" || limit>50;limit++){
        
        printf("Enter your weight:\n");
        scanf("%f",&weight);
        system("cls");

        printf("Enter your height:\n");
        scanf("%f",&height);
        system("cls");

        IMC= weight/(height*height);
    
        if(IMC>0 && IMC<100){

            if(IMC<18.5){

                printf("You are underweight.\n")
            }

            if(IMC<24.9){

                printf("Congratulations! You are at your normal weight!\n")
            }

            if(IMC<=29.9){

                printf("You are overweight (overweight).\n");
            }

            else{

                printf("Obesity.\n");
            }
        
            printf("Enter your name:\n");
            scanf("%s",name);
            system("cls");
        }
    }
    
    return 0;
}