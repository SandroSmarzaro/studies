#include <stdio.h> //adicionando a biblioteca padrão

float PA( float a1, int n, float reason); //declarando o módulo que ira calcular o último termo da PA

int main(){
    
    float a1, reason,result;    //declarando as váriaveis de escopo local da função main para depois passar ela para a outra função
    int n;

    printf("Enter the first term of PA:\n"); //pedindo o valor de a1 pra passar como parametro de valor
    scanf("%f", &a1); //recebendo esse valor
    system("cls"); //apagando a tela pra organizar

    printf("Enter the numbers of terms of PA\n"); //pedindo o número de termos para passar como valor   
    scanf("%d", &n); //recebendo o valor de n
    system("cls");

    printf("Enter the reason of PA\n"); //pedindo o valor da razão da PA para passar como valor
    scanf("%f", &reason);   //recebendo o valor 
    system("cls");

    result=PA(a1, n, reason); //chando a função para calcular oíltimo termo da PA, passando por valor para ela os três valores anteriores

    printf("The final term of PA is: %.2f\n", result); //mostrando o resultado depois de calculado

    return 0; //neste caso a função main não vai retornar algo pra ser usado
}

float PA( float a1, int n, float reason){

    float result;   //declarando o resultado desejado para ser retornado
    
    result= a1+(n-1)*reason; //aplicando a fórmula de PA subistituindo pelas variaveis recebidas
    
    return result;  //retornando o resultado para main já calculado
}