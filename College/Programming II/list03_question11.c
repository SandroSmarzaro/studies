#include <stdio.h>

int consonant(char letter);

int main(){
    char character;
    int result;

    scanf("%c", &character);
    result = consonant(character);
    printf("\n%d\n", result);

    return 0;
}

int consonant(char letter){
    switch(letter){
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}