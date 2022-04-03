#include <stdio.h>
#include <string.h> 

int main(){

    int vowels_count=0, size;
    char word[20];

    printf("Enter the word:\n");
    scanf("%s",word);
    system("cls");

    size=strlen(word);
    
    for(int count=0; count<size ;count++){

        if(word[count]=='a' || word[count]=='A'){
            
            vowels_count++;
        }
        
        else if(word[count]=='e' || word[count]=='E'){

            vowels_count++;
        }

        else if(word[count]=='i' || word[count]=='I'){

            vowels_count++;
        }

        else if(word[count]=='o' || word[count]=='O'){

            vowels_count++;
        }

        else if(word[count]=='u' || word[count]=='U'){

            vowels_count++;
        }
    }

    printf("The number of vowels is: %i\n", vowels_count);


    return 0;
}