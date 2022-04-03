programa
{
	inclua biblioteca Matematica --> Mat
	funcao inicio()
	{
		inteiro n1, n2, n_elevado, n1_quad, n2_quad
		
		escreva("Digite o 1º número inteiro: \n")
		leia(n1)

		limpa()

		escreva("Digite o 2º número inteiro\n")
		leia(n2)

		limpa()
		
		n_elevado = Mat.potencia(n1, n2)
		
		n1_quad = Mat.potencia(n1, 2)
		
		n2_quad = Mat.potencia(n2, 2)

		escreva ("Se ",n1," e ",n2," foram os números inseridos\n")
		escreva ("então ", n1, " elevado a ",n2, " é = ",n_elevado,"\n")
		escreva ("e o quadrado de 1º é ",n1_quad, " e o quadrado do 2º é ", n2_quad, "\n")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 288; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */