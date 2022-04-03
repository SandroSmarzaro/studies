#include <stdio.h>

#define MAX 2
double hypotenuse(double side[MAX]);

int main(){
    double number[MAX];
    double result;
    
    for(int count = 0; count < MAX; count++){
        printf("Side %d: \n", count + 1);
        scanf("%lf", &number[count]);
    }
    result = hypotenuse(number);
    printf("\nRoot: %.3f\n", result);

    return 0;
}

double hypotenuse(double side[MAX]){
    double root;

    root = ((side[0] * side[0]) + (side[1] * side[1]));

    return root;
}