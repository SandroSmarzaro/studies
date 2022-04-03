programa
{
	
	funcao inicio()
	{
		inteiro normal, c, d, u, inverso

		escreva("Digite o valor do número inteiro: \n")
		leia(normal)

		limpa()
		
		c= normal /100
		d= (normal%100)/10
		u= normal%10

		inverso=(u*100)+(d*10)+c

		escreva("O seu número inserido foi ",normal," o inverso dele é ",inverso,"\n")
		
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 191; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */