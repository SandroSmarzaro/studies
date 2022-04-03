#include <stdio.h>

int main(){

    int I;
    float A, B, C;

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

    switch(I){

        case 1:
            if(A<B && B<C)
            printf("%f, %f, %f",A,B,C);
            else if(A<C && C<B)
            printf("%f, %f, %f",A,C,B);
            else if(B<A && A<C)
            printf("%f, %f, %f",B,A,C);
            else if(B<C && C<A)
            printf("%f, %f, %f",B,C,A);
            else if(C<B && B<A)
            printf("%f, %f, %f",C,B,A);
            else if(C<A && A<B)
            printf("%f, %f, %f",C,A,B);

            break;
        
        case 2:
            if(A>B && B>C)
            printf("%f, %f, %f",A,B,C);
            else if(A>C && C>B)
            printf("%f, %f, %f",A,C,B);
            else if(B>A && A>C)
            printf("%f, %f, %f",B,A,C);
            else if(B>C && C>A)
            printf("%f, %f, %f",B,C,A);
            else if(C>B && B>A)
            printf("%f, %f, %f",C,B,A);
            else if(C>A && A>B)
            printf("%f, %f, %f",C,A,B);

            break;

        case 3:
            if(A>B && B>C)
            printf("%f, %f, %f",B,A,C);
            else if(A>C && C>B)
            printf("%f, %f, %f",C,A,B);
            else if(B>A && A>C)
            printf("%f, %f, %f",A,B,C);
            else if(B>C && C>A)
            printf("%f, %f, %f",C,B,A);
            else if(C>B && B>A)
            printf("%f, %f, %f",B,C,A);
            else if(C>A && A>B)
            printf("%f, %f, %f",A,C,B);

            break;
        
        default:
            
            printf("Value incorrect of I.\n");

            break;
    }

    return 0;
}