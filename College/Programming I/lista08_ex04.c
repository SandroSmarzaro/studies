#include <stdio.h>

int main(){

    int value, banknote_100=0, banknote_50=0, banknote_20=0, banknote_10=0, banknote_05=0, banknote_02=0;

    printf("Enter the value of withdraw:\n");
    scanf("%i",&value); 
    system("cls"); 
     
    if (value<=2000){
        
        if(value%2==0 || value%5==0){

            while (value-100>=0 && value>0){

                value=value-100;
                banknote_100++;
            }        

            while (value-50>=0 && value>0){

                value=value-50;
                banknote_50++;
            }

            while (value-20>=0 && value>0){
                
                value=value-20;
                banknote_20++;
            }
            
            while (value-10>=0 && value>0){
                
                value=value-10;
                banknote_10++;
            }

            while (value-5>=0 && value>0){
                
                value=value-5;
                banknote_05++;
            }

            while (value-112>=0 && value>0){
                
                value=value-2;
                banknote_02++;
            }

            printf("The numbers of banknotes of your withdraw is:\n");
            printf("|100 $ = %i |50 $ = %i |20 $ = %i |10 $ = %i |5 $ = %i |2 $ = %i | \n",banknote_100,banknote_50,banknote_20,banknote_10,banknote_05,banknote_02);
        }

        else{

            printf("The value must be a multiple of 2 and 5.\n");
        }
    }
    
    else{

        printf("The withdraw limit is 2000 $.\n");
    }

    return 0;
}