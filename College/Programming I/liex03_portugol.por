programa
{
	
	funcao inicio()
	{

		inteiro max=4, number, count2=4,vector_1[5], vector_2[5], result[5];


    		para(inteiro count=0; count<=max; count++){

        
       		escreva("Enter the ",count," number of first vector:\n");
        		leia(number);
        		limpa()

        		vector_1[count]=number;
    		}


    		para(inteiro count=0; count<=max; count++){

        
        
        		escreva("Enter the ",count," number of second vector:\n");
        		leia(number);
        		limpa()

        		vector_2[count]=number;
    		}

    		para(inteiro count=0; count<=max;count++){
        
        		result[count]= vector_1[count] * vector_2[count2]
        
        		count2--;
        
    		}

    		escreva(vector_2[0]," \n");

   		
   		para(inteiro count=0; count<=max; count++){

        		escreva(vector_1[count]," ");
    		}    
    
    		escreva("\n");

    		
    		para(inteiro count=0; count<=max; count++){

        		escreva(vector_2[count]," ");
    		}

     	escreva("\n");

    		
    		para(inteiro count=0; count<=max; count++){    
        
        		escreva(result[count]," ");
    		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 708; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */