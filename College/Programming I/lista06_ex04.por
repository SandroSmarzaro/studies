programa
{
	
	funcao inicio()
	{
		real sal, sal_novo, desc, desc_convertido
		cadeia nome

		sal_novo=0.0
		desc=0.0
		desc_convertido=0.0

		
		escreva("Digite o nome do funcionário: \n")
		leia(nome)

		limpa()

		escreva("Digite o salário do funcionário: \n")
		leia(sal)

		limpa()
		
		se(sal<=998)
		{
			desc=0.1
			sal_novo= (sal*desc)+sal
		}
		senao se(sal>998 e sal<=1200)
		{
			desc=0.06		
			sal_novo=(sal*desc)+sal
		}
		senao se(sal>1200 e sal<=1500)
		{
			desc=0.04
			sal_novo=(sal*desc)+sal
		}
		senao se(sal>1500 e sal<=1800)
		{
			desc=0.02
			sal_novo=(sal*desc)+sal
		}
		senao se(sal>1800)
		{
			desc=0.0
			sal_novo=(sal*desc)+sal
		}
		senao
		{
			escreva("ERR0R \n")
		}

		desc_convertido=desc*100
		
		escreva("O funcionário ",nome," teve desconto de ",desc_convertido," %\n")
		escreva("entaõ seu salário atual de R$ ",sal," mudou para R$ ",sal_novo,"\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 786; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */