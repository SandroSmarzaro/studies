#include <stdio.h>

int main(){

    int max=5, vector[max], number, interval_1=0, interval_2=0, interval_3=0, interval_4=0;

    for(int count=0; count<max; count++){

        printf("Enter the %dº number:\n",count);
        scanf("%d",&number);
        system("cls");
        
        if(number<0 || number>100){

            count--;
        }
        
        else{
            
            vector[count]= number;

            if(vector[count]>=0 && vector[count]<=25){

                interval_1++;
            }
            else if(vector[count]>25 && vector[count]<=50){

                interval_2++;
            }
            else if(vector[count]>50 && vector[count]<=75){

                interval_3++;
            }
            else if(vector[count]>75 && vector[count]<=100){

                interval_4++;
            }
        }
    }

    printf("The number in interval 1 is: %d, interval 2: %d, interval 3:%d and interval 4: %d\n",interval_1,interval_2,interval_3,interval_4);

    return 0;
}