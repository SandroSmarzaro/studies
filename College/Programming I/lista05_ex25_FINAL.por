programa
{
	
	funcao inicio()
	{
		inteiro d, m,a, data, data2

		escreva("Digite o valor da data em DDMMAA: \n")
		leia(data)

		limpa()

		d= data/10000

		m= (data%10000)/100
		
		a= data%100

		data2=(a*10000)+(m*100)+d
		

		
		escreva(data," ",data2)
		
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