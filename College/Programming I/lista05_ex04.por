programa
{
	
	funcao inicio()
	{
		real razao, ntermos, a1, an

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
		
		escreva ("O N termo dessa PA determindado pelo seus valores inseridos é = ",an, "\n")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 429; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */