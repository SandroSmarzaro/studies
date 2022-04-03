#include <stdio.h> //adicionando a biblioteca padrão
#include <ctype.h> //biblioteca para o tolower
#include <string.h>

void read_matrix(char matrix[3][3]); //declarando o procedimento que vai ler a matriz passsada por parametro

void inverted_matrix(char matrix[3][3]); //declarando o procedimento que vai inverter a matriz passada por parametro 

void print_matrix(char matrix[3][3]);    //declarando o procedimento que vai mostrar a matriz invertida que foi passa por paramentro

int main(){

    char main_matrix[3][3]; //declarando a matriz de letras

    read_matrix(main_matrix); //chamando o procedimento que vai ler a matriz

    inverted_matrix(main_matrix); //chamando o procedimento que vai inverter a matriz lida
    
    print_matrix(main_matrix); //chamando o procedimento que vai mostrar a matriz invertida

    return 0;
}

void read_matrix(char matrix[3][3]){
    
    char letter; //declarando uma varialvel que vai receber a letra da vez daquela posição
    
    for(int count=0; count<3; count++){ //fazendo o primeiro laço que vai passar pelas linhas

        for(int count2=0; count2<3; count2++){ //fazendo segundo laço que vai passar pelas colunas
    
            printf("Enter the letter of line %d and column %d\n", count, count2);
            scanf("%s", &matrix[count][count2]);   //recebendo os valores daquela exata posição da matriz
            system("cls");  //apagando atela pra organizar

            letter=matrix[count][count2];  //recebendo a letra da vez daquela exta posição ad matriz

            switch (tolower(letter)){   //verificado atraves do escolha se ela é uma vogal seja maiuscula ou minuscula com o tolower

                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':

                    matrix[count][count2]='#'; //se for uma vogal é subistituida naquela mesma posição por #

                    break;
            
                default: //se não for vogal quero que faça nada
                
                    break;
            }
        }
    }   
}

void inverted_matrix(char matrix[3][3]){

    char saved;

    for(int count=0; count<3; count++){

        for(int count2=0; count2<3; count2++){

            saved= matrix[2-count][2-count2]; 
            matrix[(2-count)][(2-count2)]=matrix[count][count2]; //a própria matriz na posição inversa esta recebendo os valores da posição original a medida que o laço avança
            matrix[count][count2]=saved;

            if(count==1 && count2==1){

                count=3;
                count2=3;
            }
        } 
    }
}

void print_matrix(char matrix[3][3]){

    for(int count=0; count<3; count++){

        for(int count2=0; count2<3; count2++){

            printf("    %c  ", matrix[count][count2]); // mostrando a matriz seguindo o laço
            
            if(count2==2){

                printf("\n");
            }
        } 
    }
}