#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int amount_a=0, amount_e=0, amount_i=0, amount_o=0, amount_u=0, size;
    char word[21], letter, asterisk='*';

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
    
    printf("A: ");
    for(int count=0; count<amount_a; count++){
        printf("%c", asterisk);
    }
    printf("(%d)\n", amount_a);

    printf("E: ");
    for(int count=0; count<amount_e; count++){
        printf("%c", asterisk);
    }
    printf("(%d)\n", amount_e);

    printf("I: ");
    for(int count=0; count<amount_i; count++){
        printf("%c", asterisk);
    }
    printf("(%d)\n", amount_i);

    printf("O: ");
    for(int count=0; count<amount_o; count++){
        printf("%c", asterisk);
    }
    printf("(%d)\n", amount_o);

    printf("U: ");
    for(int count=0; count<amount_u; count++){
        printf("%c", asterisk);
    }
    printf("(%d)\n", amount_u);

    return 0;
}