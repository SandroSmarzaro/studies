#include <stdio.h>

int main(){

    int num=1, predecessor=0, sucessor=0;

    printf("Enter the number:\n");
    scanf("%i",&num);
   
   
    while(num!=0){

        predecessor=num-1;
        sucessor=num+1;
        
        printf("Predecessor = %i\n", predecessor);
        printf("Number = %i\n",num);
        printf("Sucessor = %i\n",sucessor);
        printf("\n");

        printf("Enter the number:\n");
        scanf("%i",&num);
        
    }
    
    return 0;
}