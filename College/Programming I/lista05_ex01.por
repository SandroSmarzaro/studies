programa
{
	
	funcao inicio()
	{
		cadeia nome
		real salario, imp_desc, sal_liq

		escreva ("Digite o nome do funcionário: \n")
		leia (nome)

		limpa()

		escreva ("Digite o salário do funcionário: \n")
		leia (salario)

		limpa()

		escreva ("Digite em reais o valor do imposto que será descontaado do salário do funcionário: \n"))
		leia (imp_desc)

		limpa()

		sal_liq = salario - imp_desc

		escreva ("O funcionário ",nome," recebe salário líquido no valor de R$ ", sal_liq"\n")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 425; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */