programa
{
	
	funcao inicio()
	{
		real razao, ntermos, a1, an, soma

		escreva ("Digite a razão da progressão aritmética(PA): \n")
		leia (razao)

		limpa()

		escreva ("Digite o número de termos existente dessa PA: \n")
		leia (ntermos)

		limpa()

		escreva ("Digite o primeiro termos dessa PA: \n")
		leia (a1)

		limpa()

		an = a1 + (ntermos - 1) * razao
		
		soma = (a1 + an) * ntermos / 2

		escreva ("A soma dos ", ntermos, " termos dessa PA é igual a: ", soma,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 442; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */