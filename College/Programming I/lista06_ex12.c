#include <stdio.h>

int main(){

    int a, b, MDC, a_mmc, b_mmc, MMC, residue;

    printf("Enter the value of a:\n");
    scanf("%i",&a);
    system("cls");

    printf("Enter the value of b:\n");
    scanf("%i",&b);
    system("cls");

    while(a!=0 || b!=0){
        
        a_mmc=a;
        b_mmc=b;

        while(b!=0){

            residue=a%b;
            a=b;
            b=residue;
        }
        MDC=a;

        MMC=a_mmc*(b_mmc/MDC);

        printf("The values a= %i and b= %i\n",a_mmc, b_mmc);
        printf("has the value of MDC= %i and MMC= %i\n",MDC, MMC);
        printf("\n");

        printf("Enter the value of a:\n");
        scanf("%i",&a);
        system("cls");

        printf("Enter the value of b:\n");
        scanf("%i",&b);
        system("cls");

    }

    return 0;
}