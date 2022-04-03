#include <stdio.h>

int main(){

    int count2, axis_x=2, axis_y=6, matrix[axis_x][axis_y], bigger, position_bigger, spectator=0, kids[axis_x], max=0,non_paying=0;

    for(int count=0; count<axis_x; count++){
        
        for(count2=0; count2<axis_y; count2++){
            
            printf("Enter the number of %d line and %d column:\n", count, count2);
            scanf("%d", &matrix[count][count2]);
            system("cls");              
        }

        for(int count3=0; count3<3; count3++){

            spectator=spectator+matrix[count][count3];
        }

        if(count==0 && count2==6){

            bigger=spectator;
            position_bigger=count;
        }

        if(spectator>bigger){

            bigger=spectator;
            position_bigger=count;
        }

        spectator=0;
        
        if(matrix[count][2]==0){

            kids[max]=count;
            max++;
        }

        for(int count4=3; count4<axis_y; count4++){

            non_paying=non_paying+matrix[count][count4];
        }
    }

    printf("The game most most spectator is: %d with %d viewers\n",position_bigger, bigger);
    printf("The games with zero kids is:\n");

    for(int count=0; count<max; count++){

        printf("%d /",kids[count]);
    }

    printf("\nThe total of non paying public is: %d\n",non_paying);



    return 0;
}