#include <stdio.h>

int main(){

    int max=4, number, count2=4,vector_1[5], vector_2[5], result[5];

    //srand(time(NULL));

    for(int count=0; count<=max; count++){

        //vector_1[count]= rand()%10;
        
        printf("Enter the %dº number of first vector:\n",count);
        scanf("%d",&number);
        system("cls");

        vector_1[count]=number;
    }

    for(int count=0; count<=max; count++){

        //vector_1[count]= rand()%10;
        
        printf("Enter the %dº number of second vector:\n",count);
        scanf("%d",&number);
        system("cls");

        vector_2[count]=number;
    }

    for(int count=0; count<=max;count++){
        
        result[count]= vector_1[count]* vector_2[count2];
        
        count2--;
        
    }

    for(int count=0; count<=max; count++){

        printf("%d ",vector_1[count]);
    }    
    
    printf("\n");

    for(int count=0; count<=max; count++){

        printf("%d ",vector_2[count]);
    }

     printf("\n");

    for(int count=0; count<=max; count++){    
        
        printf("%d ",result[count]);
    }

    return 0;
}