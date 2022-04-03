#include <stdio.h>
#define SIZE 5

void repetitionChecker (int *array[]);

int main (){
    int array[SIZE];

    for (int index = 0; index < SIZE; index++){
        printf ("Enter the value [%d]:\n", index);
        scanf ("%d", &array[index]);
    }
    puts ("");
    repetitionChecker (array);

    return 0;
}

void repetitionChecker (int *array[]){
    int repetition = 0;
    int adder = 0;

    for (int index = 0; index < SIZE; index++){
        for (int count = 0; (count + adder) < SIZE; count++){
            //printf("[%d] x [%d] (%d < %d)\n", array[index], array[count + adder], (count + adder), SIZE);
            if (array[index] == array[count + adder]){
                repetition++;
            }
        }
        if (repetition > 1){
            printf("Number [%d]: %d\n", array[index], repetition);
        }
        repetition = 0;
        adder++;
    }
    puts("");
}