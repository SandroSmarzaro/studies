#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(){
    
    int size;
    char word[11];
    
    do{
        printf("Enter the word:\n");
        scanf("%[^\n]s", word);
        size=strlen(word);

        if(size!=10){
            system("cls");
            printf("The word must be equal to 10 characters. Repeat again!\n");
        }

    }while(size!=10);
    
    system("cls");
    
    for(int count=0; count<10; count++){
        
        if(word[count]!=' '){
            printf("%c\n", word[count]);
        }
    }
    return 0;
}