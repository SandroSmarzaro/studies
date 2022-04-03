#include <stdio.h> //bliblioteca basica de input e output
#include <string.h> //bliblioteca para as strings e strlen
#include <ctype.h>  //bliblioteca para o tolower

int main(){

    //declarando as variaáveis
    char word[20], letter;
    int size, consonant=0, previous=0;

    //criando um laço para pegar as cinco palavras
    for(int count=1; count<=5; count++){

        printf("Enter the word:\n");

        //pegando cada palavra
        scanf("%s", word);
    
        system("cls");

        //pegando o tamanho da palavra inserida
        size=strlen(word);

        //apos pegar o tamanho da palavra, verificar se não do mesmo tamanho da anterior para que possa continuar fazendo as operações
        if(size!=previous){

            //registrando a nova palavra anterior para as próximas verificações
            previous=size;    

            //criando laço para ler cada letra da palavra
            for(int count2=0; count2<size; count2++){

                //pegando a letra específica daquela posição do vetor indicado por count2
                letter=word[count2];

                //usando a estrutura switch para verificar a existência das consoantes
                //tolower para diferenciar maiuscula de minuscula
                switch (tolower(letter)){
                
                    case 'n':
                    case 'p':
                    case 'r':
                    case 's':
                    case 't':

                        //se a consoante exisitir, o contador (que já foi zerado na declaração para não aumentar memória vazia) delas é aumentando em 1 contando cada uma
                        consonant++;
                
                        break;
                
                    //caso não a letra especifica não seja a consoante requerida, quero que faça nada
                    default:

                        break;
                }
            }

            //após a verificação das consoantes, posso usar a variavel contadora de consoantes a consonant para mostrar o número de consoantes pedidas naquela palavra especifica
            printf("The amount of N, P, R, S and T consonants this word is: %d\n", consonant);

            //zerando a viavel contadora de consoantes para não afetar a contagem das próximas palavras
            consonant=0;
    
        }else{
            
            //caso a palavra anterior seja igual a nova inserida, o programa deve parar
            break;
        }
    }

    //a função retorna nada
    return 0;
}