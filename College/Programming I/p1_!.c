#include <stdio.h> //bliblioteca basica de input e output
#include <string.h> //biblioteca para as strings

int main(){

        //declarando as variaveis
        char matrix[12][12];

       
        //fazendo o primeiro laço para percorer os valores de coluna da matriz
        for(int count=0; count<12; count++){

            //enquanto estiver naquela linha, este laço percorrera de linha da matriz
            for(int count2=0; count2<12; count2++){

                //fazendo os espaços em branco do T
                 matrix[count][count2]=' ';
                
                if(count==0){

                    //enquanto a cordenanda estiver em seu topo, fazer o taço de cima do T
                    matrix[0][count2]='#';
                }

                else if(count2==5){
                    
                    //para fazer a coluna vertical do T, quando a matriz estiver no meio, colocar um #
                    matrix[count][5]='#';
                }
            }
        }
        
        //fazendo novamente os dois laços para escrever o T
        for(int count=0; count<12; count++){

            for(int count2=0; count2<12; count2++){

                printf("%c", matrix[count][count2]);
                
                //quando a linha chegar ao final que é 11, devido começar com 0, quebrar a linha para não escrever tudo junto
                if(count2==11){
                    printf("\n");
                }
            }
        }

    //a função retorna nada
    return 0;
}