programa
{
	
	funcao inicio()
	{
		inteiro codigo, digitov, s, A, B, C, D, E

		digitov=7
		
		escreva("Digite o valor do código: \n")
		leia(codigo)

		limpa()
		
		A=codigo/10000
		B=(codigo%10000)/1000
		C=(codigo%1000)/100
		D=(codigo%100)/10
		E=codigo%10
				
		s= 6*A + 5*B + 4*C + 3*D + 2*E
		digitov = s%7

		escreva("S = ",s," e o DigitoV = ",digitov,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 251; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */