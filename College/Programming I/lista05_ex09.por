programa
{
	
	funcao inicio()
	{
		cadeia nome
		real valor_unt, valor_desc, valor_final, desc, desc_real
		inteiro quant

		escreva ("Digite o nome do produto : \n")
		leia (nome)

		limpa()
		
		escreva ("Digite a quantidade desse produto \n")
		leia (quant)

		limpa()

		escreva ("Digite o preço unuitário desse produto: \n")
		leia (valor_unt)

		limpa()

		escreva("Digite a porcentagem de desconto desse produto: \n")
		leia(desc)

		limpa()

		desc = desc / 100
		desc_real = desc * valor_unt
		valor_final = (valor_unt - desc_real)*quant

		escreva ("O seu produto ", nome, " comprado na quantidade de ", quant, " vezes\n")
		escreva ("tem o valor de cada um como R$ ", valor_unt, " com desconto de R$ ", desc_real,"\n")
		escreva ("sendo assim, tem o valor final de R$ ", valor_final,"\n")
		 
		


		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 546; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */