#include <stdio.h>

int main(){

    float grade;

    printf("Enter the grade of student:\n");
    scanf("%f",&grade);
    system("cls");

    if(grade>=0 && grade<=10){

        if(grade<3){
            printf("Concept E\n");
        }
        else if(grade<6){
            printf("Concept D\n");
        
            else if(grade<8){
                printf("Concept C\n");
        
                else if(grade<9){
                    printf("Concept B\n");
        
                    else if(grade<=10){
                        printf("Concept A\n");
        
                        else{
                            printf("Value of grade invalid!\n");
                         }
                    }
                }
            }
        }
    }
    return 0;
}