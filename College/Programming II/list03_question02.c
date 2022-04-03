#include <stdio.h>

#define max 5

int main(){
    unsigned count; 
    for (count = 1; count < max; count++){
    printf("%d ", count);
    }
    printf("\nStop the loop in count == %d\n", count);
    return 0;
}