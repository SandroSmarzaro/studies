#include <stdio.h>

void printArray (const int *array[], const int size);
int increasingComparison (const int *array[], const int size);

int main (){
    const int size;
    int result;

    puts ("Size of array: ");
    scanf ("%d", &size);
    puts ("");
    int array[size];
    for (int index = 0; index < size; index++){
        printf ("Enter the value [%d]:\n", index);
        scanf ("%d", &array[index]);
    }
    result = increasingComparison (array, size);
    printArray (array, size);
    if (result == 1){
        puts("In order.");
    }
    else{
        puts("Out of order!");
    }
    puts("");

    return 0;
}

void printArray (const int *array[], const int size){
    puts ("");
    for (int index = 0; index < size; index++){
        printf ("%d ", array[index]);
    }
    puts ("");
}

int increasingComparison (const int *array[], const int size){
    int comparisonFlag = 1;
    for (int index = 0; comparisonFlag == 1 && index < (size - 1); index++){
        if (array[index] > array[index + 1]){
            comparisonFlag = 0;
        }
    }
    return comparisonFlag;
}