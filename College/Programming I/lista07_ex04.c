#include <stdio.h>
#include <string.h>

int main(){

    int max_words=20, size, vowels_count_total=0, vowels_count_single=0;
    char word[20];

    for(int count_words=1; count_words<=max_words; count_words++){

        printf("Enter the %io word:\n", count_words);
        scanf("%s",word);
        system("cls");

        size=strlen(word);

        for(int count=0; count<size ;count++){
            
            if(word[count]=='a' || word[count]=='A'){
            
                vowels_count_single++;
                vowels_count_total++;
            }
            
            else if(word[count]=='e' || word[count]=='E'){

                vowels_count_single++;
                vowels_count_total++;
            }

            else if(word[count]=='i' || word[count]=='I'){

                vowels_count_single++;
                vowels_count_total++;
            }

            else if(word[count]=='o' || word[count]=='O'){

                vowels_count_single++;
                vowels_count_total++;
            }

            else if(word[count]=='u' || word[count]=='U'){

                vowels_count_single++;
                vowels_count_total++;
            }       
        }

        printf("The number of vowels this %io word is: %i\n",count_words,vowels_count_single);

        vowels_count_single=0;

    }

    printf("The number of vowels in total is: %i", vowels_count_total);

    return 0;
}