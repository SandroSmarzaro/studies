programa
{
	
	funcao inicio()
	{
		real reais, dolar, peso, euro, iene, reais_dolar, reais_peso, reais_euro, reais_iene

		escreva("Digite o valor em reias R$: \n")
		leia(reais)

		limpa()

		escreva("Digite o valor em dolar US$: \n")
		leia(dolar)

		limpa()

		escreva("Digite o valor em peso argentino $: \n")
		leia(peso)

		limpa()

		escreva("Digite o valor em euros €: \n")
		leia(euro)

		limpa()

		escreva("Digite o valor em ienes ¥: \n")
		leia(iene)

		limpa()
		
		reais_dolar = reais / dolar
		reais_peso = reais / peso
		reais_euro = reais / euro
		reais_iene = reais / iene

		escreva("O seu valor de R$ ",reais," equivale a US$ ",reais_dolar,"\n")
		escreva("O seu valor de R$ ",reais," equivale a $ ",reais_peso,"\n")
		escreva("O seu valor de R$ ",reais," equivale a € ",reais_euro,"\n")
		escreva("O seu valor de R$ ",reais," equivale a ¥ ",reais_iene,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 590; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */