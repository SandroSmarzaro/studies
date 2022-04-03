programa
{
	
	funcao inicio()
	{
		real n1, n2, n3, soma, multi, media

		escreva("Digite o valor do 1º número: \n")
		leia(n1)

		limpa()

		escreva("Digite o valor do 2º número: \n")
		leia(n2)

		limpa()

		escreva("Digite o valor do 3º número: \n")
		leia(n3)

		limpa()

		soma = n1+n2+n3
		media = soma/3
		multi=n1*n2*n3

		escreva("O valor da soma dos três números é ",soma," a média é ",media," e o produto ",multi," \n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 363; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */