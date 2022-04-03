#include <stdio.h>

int main(){

    int axis_x=7, axis_y=4, matrix[axis_x][axis_y], smaller, position[2];

    for(int count=0; count<axis_x; count++){
        
        for(int count2=0; count2<axis_y; count2++){
            
            printf("Enter the number of %d line and %d column:\n", count, count2);
            scanf("%d", &matrix[count][count2]);
            system("cls");

            if(count==0 && count2==0){ 

                smaller=matrix[count][count2];

                position[0]=count;
                position[1]=count2;
            }    
            
            if(matrix[count][count2]<=smaller){

                smaller=matrix[count][count2];

                position[0]=count;
                position[1]=count2;
            } 
        }
    }

    printf("The smaller value is: %d in %d axis X and %d axis Y position\n",smaller, position[0],position[1]);


    return 0;
}