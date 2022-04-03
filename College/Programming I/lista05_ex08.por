programa
{
	
	funcao inicio()
	{
		inteiro n1, n2, n3, soma, media, mod, div

		escreva ("Digite o valor da 1º nota: \n")
		leia (n1)

		limpa()

		escreva ("Agora digite o valor da 2º nota: \n")
		leia (n2)

		limpa()
		
		escreva ("Por último, digite o valor da 3º nota: \n")
		leia(n3)

		limpa()

		soma = n1 +n2 + n3
		media= soma/3
		mod = n1 % n2
		div= mod/3

		escreva ("A soma das notas é: ", soma, "\n")
		escreva ("Já a média das nostas é: ", media,"\n")
		escreva ("O resto da 1º nota com a 2º é: ", mod,"\n")
		escreva ("E a divisão inteira do resto pela 3º é: ", div"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 160; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */