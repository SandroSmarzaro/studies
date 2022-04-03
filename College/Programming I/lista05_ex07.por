programa
{
	
	funcao inicio()
	{
		inteiro A,B, C

		escreva ("Digite o valor inteiro de A: \n")
		leia (A)

		escreva ("Digite o valor inteiro de B: \n")
		leia (B)

		limpa()

		escreva ("Se você colocou A = ", A, " e B = ", B,"\n")
		
		C = A
		A = B
		B = C

		escreva ("Então invertendo A com B fica A = ", A," e B = ", B,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 329; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */