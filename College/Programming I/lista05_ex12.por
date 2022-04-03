programa
{
	
	funcao inicio()
	{
		real lado_quad, area, perimetro

		escreva ("Digite o lado do quadrado desejado: \n")
		leia(lado_quad)

		area = lado_quad * lado_quad
		perimetro = lado_quad + lado_quad + lado_quad + lado_quad

		escreva("Sabendo que o tamanho do lado do quadrado inserido é ",lado_quad,"\n")
		escreva("sua área é ",area," e seu perímetro é ",perimetro,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 115; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */