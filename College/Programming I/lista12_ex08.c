#include <stdio.h>

int calcularMMC(int numb1, int numb2);

int calcularMDC(int num1, int num2);

int main(){

    int n1, n2, result, option;
    char restart='s';

    while(restart=='s'){
        
        printf("Enter the number one:\n");
        scanf("%d",&n1);
        system("cls");

        printf("Enter the number two:\n");
        scanf("%d",&n2);
        system("cls");

        printf("Which operation you want do?\n");
        printf("<1> MMC          <0> MDC\n");
        scanf("%d", &option);
        system("cls");

        if(option==1){

            result=calcularMMC(n1, n2);

            printf("Your result is: %d", result);

        }
        else if(option==0){

            result=calcularMDC(n1,n2);

            printf("Your result is: %d\n", result);

        }
        else{
            
            printf("Option invalid!\n");
        }

        printf("\nDo you like continue?\n");
        printf("<s> YES          <n> NO\n");
        scanf("%s", &restart);
        system("cls");
    
    }

    return 0;
}

int calcularMMC(int numb1, int numb2){

    int MMC, inicial_numb1, inicial_numb2, residue;

    inicial_numb1=numb1;
    inicial_numb2=numb2;

    while(numb2!=0){

        residue=numb1%numb2;
        numb1=numb2;
        numb2=residue;
    }

    MMC=inicial_numb1*(inicial_numb2/numb1);

    return MMC;
}

int calcularMDC(int num1, int num2){

    int MDC, inicial_num1, inicial_num2, residue;

    inicial_num1=num1;
    inicial_num2=num2;

    while(num2!=0){

        residue=num1%num2;
        num1=num2;
        num2=residue;
    }

    MDC=num1;

    return MDC;
}