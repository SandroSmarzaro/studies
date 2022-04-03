#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int amount_a=0, amount_e=0, amount_i=0, amount_o=0, amount_u=0, size;
    char word[21], letter;

    printf("Enter your word:\n");
    scanf("%[^\n]s", word);
    system("cls");

    size=strlen(word);

    for(int count=0; count<size; count++){

        
        letter=tolower(word[count]);
        
        switch (letter){
            
            case 'a':
                amount_a++;
                break;
            case 'e':
                amount_e++;
                break;
            case 'i':
                amount_i++;
                break;
            case 'o':
                amount_o++;
                break;
            case 'u':
                amount_u++;
                break;
        }
    }

    printf("The amount of vowel is:\n");
    printf("A: %d   |   E: %d   |   I: %d   |   O: %d   |   U: %d   |\n", amount_a, amount_e, amount_i, amount_o, amount_u);

    return 0;
}