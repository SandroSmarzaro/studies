programa
{
	
	funcao inicio()
	{
		inteiro d1, d2, m1, m2, a1, a2, data, d, m, a

		escreva("Digite o valor da data em DDMMAA: \n")
		leia(data)

		limpa()

		d1= data/100000
		d2= (data%100000)/10000

		m1= (data%10000)/1000
		m2= (data%1000)/100

		a1= (data%100)/10
		a2= data%%10

		
		escreva("Sua data inserida no formato DDMMAA é ",d1,d2,m1,m2,a1,a2,"\n")
		escreva("então ela no formato AAMMDD é ",a1,a2,m1,m2,d1,d2,"\n")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 275; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */