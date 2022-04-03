#include <stdio.h>

float calcMedia(float f_grade);

char verConceito(float f_calMedia);

int count2=0;

float sum=0;

int main(){

    float grade, average;
    char concept;
    
    for(int count=0; count<3; count++){

        printf("Enter the %d grade:\n", count);
        scanf("%f", &grade);
        system("cls");

        calcMedia(grade);
    }

    average=calcMedia(grade);
    
    verConceito(average);
    
    concept=verConceito(average);

    printf("The average is: %.2f with concept %c\n", average, concept);

    return 0;
}

float calcMedia(float f_grade){

    float average;
    
    sum=sum+f_grade;

    if(count2==2){
        
        average=sum/3.0;
    }  
    
    count2++;

    return average;
}

char verConceito(float f_calMedia){

    char concept;

    if(f_calMedia>0){

        if(f_calMedia<4){

            concept='E';
        }

        else if(f_calMedia<6){

            concept='D';
        }

        else if(f_calMedia<8){

            concept='C';
        }

        else if(f_calMedia<9){

            concept='B';
        }
        else if(f_calMedia<10){

            concept='A';
        }
    
        else{

        printf("Numbers of grades invalid!\n");
        }
    }

    return concept;
}