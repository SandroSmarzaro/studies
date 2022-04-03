#include <stdio.h>

int main(){

    int I;
    float A, B, C;
    float smaller, medium, bigger;

    printf("Enter the value of A:\n");
    scanf("%f",&A);
    system("cls");

    printf("Enter the value of B:\n");
    scanf("%f",&B);
    system("cls");

    printf("Enter the value of C:\n");
    scanf("%f",&C);
    system("cls");

    printf("Enter the value of I:\n");
    scanf("%i",&I);
    system("cls");

    if(A>B && B>C){
           
        bigger=A;
        medium=B;
        smaller=C;
    }    
    
    else if(A>C && C>B){
    
        bigger=A;
        smaller=B;
        medium=C;
    }

    else if(B>A && A>C){
        
        medium=A;
        bigger=B;
        smaller=C;
    }

    else if(B>C && C>A){
        
        smaller=A;
        bigger=B;
        medium=C;
    }

    else if(C>B && B>A){
        
        smaller=A;
        medium=B;
        bigger=C;
    }

    else if(C>A && A>B){
            
        medium=A;
        smaller=B;
        bigger=C;
    }
    
    switch(I){

        case 1:

            printf("%f, %f, %f\n", smaller, medium, bigger);

            break;

        case 2:

            printf("%f, %f, %f\n", bigger, medium, smaller);

            break;

        case 3:

            printf("%f, %f, %f\n", smaller, bigger, medium);

            break;
        
        default:
            
            printf("Value incorrect of I.\n");

            break;

    }
}