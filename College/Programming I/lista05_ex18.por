programa
{
	
	funcao inicio()
	{
		real distancia, tempo, velocidade, litros, litro_dist

		escreva("Digite o valor do tempo em horas gasto no trajeto: \n")
		leia(tempo)

		limpa()
		
		escreva("Digite o valor da velocidade média em Km/h feita no tajeto: \n")
		leia(velocidade)

		limpa()

		distancia = tempo * velocidade

		escreva("Digite o quanto automóvel pecorre em km/h por litro de combustível\n")
		leia(litro_dist)

		limpa()
		
		litros = distancia/litro_dist

		escreva("Com seu automóvel andando a ",velocidade, " Km/h, em um tempo de ",tempo," hora(s) \n")
		escreva("em uma distancia de ", distancia," kilômetros, o tanto de litros gasto é ",litros,"\n")
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 567; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */