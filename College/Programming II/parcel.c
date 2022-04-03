#include <stdio.h>
#include <math.h>

int main(){
    double value;
    int quantity;
    double sum = 0;
    double sumCorrected = 0;

    puts("Value of product and Quanity of pacels:");
    scanf("%lf %d", &value, &quantity);
    puts("");
    double parcel[quantity];

    for(int count = 0; count < quantity; count++){
        parcel[count] = value / quantity;
        printf("Parcel Incorrect |%d| : %lf\n", count, parcel[count]);
        parcel[count] = floor(parcel[count] * 100) / 100; 
        printf("Parcel Correct   |%d| : %lf\n", count, parcel[count]);
        puts("");
        printf("Sum  before parcel |%d| : %lf\n", count, sum);
        sum += parcel[count];
        printf("Sum  after parcel  |%d| : %lf\n", count, sum);
        puts("");
    }
    if(sum < value){
        parcel[quantity - 1] += value - sum;
    }
    for(int count = 0; count < quantity; count++){
        sumCorrected += parcel[count];
    }
    for(int count = 0; count < quantity; count++){
        printf("Parcel %d is: %.2lf\n", count + 1, parcel[count]);
    }
    puts("");
    printf("Uncorrected sum: %.2lf\n", sum);
    printf("Corrected   sum: %.2lf\n", sumCorrected);

    return 0;
}