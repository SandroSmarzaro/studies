#include <stdio.h>

void separator (int number);
int inverse (void);
int digit (void);

int ones;
int tens;
int hundreds;

int main (void){
    int account;
    int sum;
    int result;

    scanf ("%d", &account);
    separator (account);
    sum = account + inverse ();
    separator (sum);
    result = digit ();
    printf("%d", result);
    
    return 0;
}

void separator (int number){
    ones = (number % 1000) / 100;
    tens = (number % 100) / 10;
    hundreds = number % 10;
}

int inverse (){
    int inverted;

    inverted = hundreds * 100 + tens * 10 + ones;
    
    return inverted;
}

int digit (){
    int result;

    ones *= 1;
    tens *= 2;
    hundreds *= 3;
    result = (hundreds + tens + ones) % 10;

    return result;
}