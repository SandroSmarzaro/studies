programa
{
	
	funcao inicio()
	{
		real n1, n2, n3, n4, soma, multi

		escreva("Digite o valor do 1º número \n")
		leia(n1)

		limpa()
		
		escreva("Agora digite o valor do 2º número \n")
		leia(n2)

		limpa()
		
		escreva("Desta vez digite o 3º número \n")
		leia(n3)

		limpa()
		
		escreva("Por último, digite o 4º número \n")
		leia(n4)

		limpa()

		soma = (n1+n2) + (n1+n3) + (n1+n4) + (n2+ n3) + (n2+n4) + (n3+n4)
		multi = (n1*n2) * (n1*n3) * (n1*n4) * (n2*n3) * (n2*n4) * (n3*n4)

		escreva("O resultado da soma e multiplicação distribuida é ",soma," e ",multi," respectivamente. \n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 588; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */