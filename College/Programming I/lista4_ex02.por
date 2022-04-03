programa
{
	
	funcao inicio()
	{
		cadeia nome, sobrenome, terceironome
		inteiro n1, n2, n3
		logico f1, f2, f3
		leia (nome)
		leia (sobrenome)
		leia (terceironome)
		leia(n1)
		leia(n2)
		leia(n3)
		leia(f1)
		leia(f2)
		leia(f3)
		f1= (sobrenome == terceironome)
		f2= (n2 <=n1+n3)
		f3 = (f1 e f2) ou f3
		n1=n2+n1- (n3%3)
		n2=n1+(n3/3)
		n3=10
		terceironome=nome
		nome=sobrenome
		f3=(nome == terceironome)

		escreva(nome, " ", sobrenome, " ", terceironome, "\n")
		escreva(n1, " ", n2, " ", n3, "\n")
		escreva(f1, " ", f2, " ", f3, "\n")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 553; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */