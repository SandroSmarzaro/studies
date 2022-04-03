programa
{
	inclua biblioteca Matematica-->mat
	funcao inicio()
	{
		real area, raio, pi

		pi = 3.14159

		escreva ("Digite o valor da raio de sua circuferência: \n")
		leia(raio)
		
		limpa()

		area = pi * mat.potencia(raio,2.0)

		escreva("A área da cincuferência que você inseriu o raio é = ",area,"\n")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 203; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */