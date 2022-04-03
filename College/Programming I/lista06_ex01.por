programa
{
	
	funcao inicio()
	{
		inteiro num

		escreva("Digite o número: \n")
		leia(num)

		limpa()

		se(num>0){
			se(num%2==0){
				escreva("Seu número é par \n")
			}
			senao{
				escreva("Seu número é ímpar \n")
			}
		}
		
		senao se(num==0){
			escreva("O número é zero \n")
			
		}
		senao{
			escreva("Este número não é positivo \n")		
		
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 355; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */