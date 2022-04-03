programa
{
	
	funcao inicio()
	{
		real sal, fin

		escreva("Digite o valor do seu salário: \n")
		leia(sal)

		limpa()

		escreva("Digite o valor do finciamento \n")
		leia(fin)

		limpa()
		
		se(fin/sal<=5)
		{
			escreva("Financiamento condedido! \n")
		}
		senao se(fin/sal>5)
		{
			escreva("Financiamento negado! \n")
		}
		escreva("Obrigado por utilizar nosso sistema! \n")			
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 255; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */