programa
{
	inclua biblioteca Matematica --> Mat
	funcao inicio()
	{
		real razao, a1, ntermos, an

		escreva ("Digite a razão da progressão geométrica (PG): \n")
		leia (razao)

		limpa()

		escreva ("Digite o número de termos existente dessa PG: \n")
		leia (ntermos)

		limpa()

		escreva ("Digite o primeiro termos dessa PG: \n")
		leia (a1)

		limpa()

		an = a1 * Mat.potencia (razao,(ntermos-1))
		
		escreva ("O N termo dessa PG determindado pelo seus valores inseridos é = ",an, "\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 318; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */