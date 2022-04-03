programa
{
	
	funcao inicio()
	{
		real nota

		escreva("Digite sua nota: \n")
		leia(nota)

		limpa()
		
		se(nota>=0 e nota<=10){
		
			se(nota<3){
			escreva("Conceito E \n")
		
				}senao se(nota<6){
				escreva("Conceito D \n")
		
					}senao se(nota<8){
					escreva("Conceito C \n")
		
						}senao se(nota<9){
						escreva("Conceito B \n")
		
							}senao se(nota<=10){
							escreva("Conceito A \n")
			}
		}
		senao
			escreva("Nota fora do intervalo \n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 432; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */