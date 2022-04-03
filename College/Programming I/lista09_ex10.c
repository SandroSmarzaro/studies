#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{

    int size, axis_x, axis_y, count, count2, count3=0;
    char alphabet[28]="ABCDEFGHIJKLMNOPQRSTUVXWYZ0", letter, matrix[3][10]={{""}};
    
    srand(time(NULL));

    for(count=0; count<=2; count++){

        for( count2=0; count2<=8; count2++){

            letter=alphabet[count];
            matrix[count][count2]=letter;
        }
    }
    
    printf("Enter the size of word:\n");
    scanf("%d",&size);
    system("cls");

    char word[size+1];

    do
    {

        axis_x=rand()%3;

        if(axis_x!=2)
        {

            axis_y=rand()%9;
        }
        else
        {
            axis_y=rand()%8;
        }
        word[count3]=matrix[axis_x][axis_y];
    
    
        count3++;
    }
    while (count3<size);

    word[size]='\0';

    printf("The word create is: %s\n", word);

    return 0;
}