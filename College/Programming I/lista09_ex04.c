#include <stdio.h>

int main(){

    int axis_x=5, axis_y=6, matrix[axis_x][axis_y], sum=0;
    float average, even_count=0;

    for(int count=0; count<axis_x; count++){
        
        for(int count2=0; count2<=axis_y; count2++){
            
            printf("Enter the number of %d line and %d column:\n", count, count2);
            scanf("%d", &matrix[count][count2]);
            system("cls");

            if(matrix[count][count2]%2==0){

                sum=sum+matrix[count][count2];
                even_count++;
            }
        }
    }

    average=sum/even_count;

    printf("The average of even numbers in matrix is: %.2f\n",average);

    return 0;
}