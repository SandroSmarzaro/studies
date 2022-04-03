programa
{
	
	funcao inicio()
	{
		real sal_bruto, desc_10, desc_05, sal_liq, sal_bruto2

		escreva("Digite o salário bruto do funcionário R$: \n")
		leia(sal_bruto)

		limpa()

		desc_10 = sal_bruto * 0.10
		sal_bruto2 = sal_bruto - desc_10
		desc_05 = sal_bruto2 * 0.05
		sal_liq = sal_bruto2 - desc_05

		escreva("O salário líquido do funcionário é R$ ",sal_liq,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 373; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */