programa
{
	inclua biblioteca Matematica --> Mat
	funcao inicio()
	{
		real pi, volume, raio, altura

		pi = 3.14159

		escreva("Digite o valor da altura da lata de óleo: \n")
		leia(altura)

		limpa()

		escreva("Digite o volume da la de óleo: \n")
		leia(volume)

		limpa()

		escreva("Digite o valor do raio da lata de óleo: \n")
		leia(raio)

		limpa()

		volume= altura * pi * Mat.potencia(raio, 2)

		escreva("O volume da lata de óleo com os dados inseridos é = ",volume,"\n") 


		
	}

}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 482; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */