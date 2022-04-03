programa
{
	inclua biblioteca Matematica --> Mat
	funcao inicio()
	{
		real n1, n2, n3
		logico l1, l2, l3
		
		n1 = 1.0
		n2 = 1.0
		n3 = 1.0
		l1 = falso
		l2 = falso
		l3 = verdadeiro
		l2 = (nao l1) ou (l2)
		l3 = l1 e (l2 ou l1)
		n3 = (Mat.raiz(n1,4.0)) * (Mat.potencia(n3,n2))
		l1 = (l1 ou (l2 e l3))
		n1 = n3/n2 - 1
		
		escreva (n1, " ",n2," ",n3 "\n")
		escreva (l1, " ",l2, " ",l3, "'\n")

		l2=(nao l1) e (Mat.raiz(n3,n2+1) != n1)
		n2=Mat.potencia(n3+n2+n1,n2)
		
		escreva (l2, "\n")
		escreva (n2, "\n")


	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 481; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */