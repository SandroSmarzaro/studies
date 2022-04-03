#include <stdio.h>
#include <string.h>
#include <windows.h>

void input();
void penalty_calculate();
void coordinate(int colune,int line);
void draw_table();

#define float velocity_max=75;

float velocity[10], penalty[10];
char license_plate[10][1], velocity_string[10][1], table[10][3];

int main(){

    input();
    penalty_calculate();
    draw_table();
    
    return 0;
}

void input(){
    for(int count=0; count<10; count++){

        printf("Enter the license plate:\n");
        scanf("%[^\n]s", license_plate[count][0]);
        system("cls");
        printf("Enter the velocity of car:\n");
        scanf("%s",velocity_string[count][0]);
        
        velocity[count]=atof(velocity_string[count]);
        
        for(int count2=0; count2<10; count2++){

            table[count2][0]=license_plate[count2][0];
            table[count2][1]=velocity_string[count2][0];
        }
    }
}

void penalty_calculate(){
    
    char word[20];

    for(int count; count<10; count++){
        
        if(velocity[count]>velocity_max){
            
            penalty[count]=(velocity[count]-velocity_max)*9;
            if(penalty[count]>180){
                penalty[count]=180;
            }
        }else{
            penalty[count]=0;
        }
        word[0]=table[count][2];
        sprintf(word, "%.2f", penalty[count]);
    }
}

void coordinate(int colune, int line){
    
    COORD coord;
    coord.X= colune;
    coord.Y= line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void draw_table(){
    
    int x=3, y=3, z=3;

    system("cls");
    coordinate(0,0);
    printf("LICENSE PLATE");
    coordinate(13,0);
    printf("VELOCITY");
    coordinate(22,0);
    printf("PENALTY");

    for(int count=0; count<3; count++){

        for(int count2=0; count2<10; count2++){

            if(count==0){    
                
                coordinate(0,x);
                printf("%s", table[count2][count]);
                x+=2;
            }
            else if(count==1){    
                
                coordinate(13,y);
                printf("%s", table[count2][count]);
                y+=2;
            }
            else if(count==2){    
                
                coordinate(13,z);
                printf("%s", table[count2][count]);
                z+=2;
            }
        }
    }
}
