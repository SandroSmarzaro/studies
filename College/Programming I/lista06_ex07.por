programa
{
	
	funcao inicio()
	{
		inteiro i=1, p1, p2, p3, p4, p5, soma, aprovados=0, reprovados=0
		real media=0.0, mediag=0.0, soma_media=0.0
		
		enquanto(i<=5){
			escreva("Digite o valor da 1º avaliação: \n")
			leia(p1)
			limpa()

			escreva("Digite o valor da 2º avaliação: \n")
			leia(p2)
			limpa()

			escreva("Digite o valor da 3º avaliação: \n")
			leia(p3)
			limpa()

			escreva("Digite o valor da 4º avaliação: \n")
			leia(p4)
			limpa()

			escreva("Digite o valor da 5º avaliação: \n")
			leia(p5)
			limpa()

			soma=p1+p2+p3+p4+p5

			media=soma/5.0
			
			se(media <=60){
				escreva("Reprovado! \n")
				reprovados=reprovados+1

				
				}senao{
					escreva("Aprovado! \n")
					aprovados=aprovados+1

				}

		soma_media=soma_media+media
		mediag=soma_media/5

		i++
		}
		
		escreva("A média geral da turma é: ",mediag," \n\n")
			
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 735; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {media, 7, 7, 5};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */