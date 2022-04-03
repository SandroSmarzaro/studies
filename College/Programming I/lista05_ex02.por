programa
{
	
	funcao inicio()
	{
		cadeia nome
		real hora_ex, hora_pad, total_ex, total_pad, sal_an
		
	
		hora_ex = 18.0
		hora_pad = 9.0

		escreva ("Digite o total de horas padrão que o funcionário trabalhou ao ano:\n")
		leia (total_pad)

		limpa()

		escreva ("Digite o total de horas extras que o funcionário trabalhou ao ano:\n")
		leia (total_ex)

		limpa()
		
		sal_an = total_pad * hora_pad + total_ex * hora_ex

		escreva ("O salário anual do funcionário é: R$ ",sal_an,"\n")
		
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 487; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */