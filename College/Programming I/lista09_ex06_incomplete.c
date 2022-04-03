#include <stdio.h>

int main(){

    int axis_x=10, axis_y=4, registry;
    char matrix[axis_x][axis_y];


    for(int count=0; count<axis_x; count++){
        
        for(int count2=0; count2<axis_y; count2++){
            
            printf("Enter the information of %d line and %d column:\n", count, count2);
            prinf("First your name after your city, phone and e-mail.\n");
            scanf("%s", matrix[count][count2]);
            system("cls");   
            
        } 
    }

    printf("Which registry do you want?\n");
    scanf("%d",&registry);
    system("cls");

    for(int max=registry; registry<=max; max++){

        for(int count=0; count<axis_y; count++){

            printf("%s\n", matrix[registry][count]);
        }
    }
    
    return 0;
}