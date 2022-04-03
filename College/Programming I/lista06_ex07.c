#include <stdio.h>

int main(){

    float grade, grade_sum=0, grade_average, grade_sum_general=0, grade_average_general;
    int approved_num=0, reproved_num=0;

    for(int i=1;i<=5;i++){

        for(int p=1;p<=5;p++){
            
            printf("Enter the grade of test:\n");
            scanf("%f,",&grade);
            system("cls");

            grade_sum=grade_sum+grade;
        }
    
        grade_average=grade_sum/5;
        printf("Your average of  5 grades is: %.2f\n",grade_average);

        if(grade_average<60){
            printf("You are reproved!\n");
            reproved_num++;
        }else{
            printf("You are approved!\n");
            approved_num++;
        }
        
        grade_sum_general=grade_sum_general+grade_average;
        grade_sum=0;
        grade_average=0;

    }
    grade_average_general=grade_sum_general/5;
    printf("The general average of class is: %.2f\n",grade_average_general);
    printf("The quantity of approved students is: %i\n", approved_num);
    printf("The quantity of reproved students is: %i\n", reproved_num);

    return 0;
}