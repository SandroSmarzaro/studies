programa
{
	
	funcao inicio()
	{
		inteiro a=-1, b=-1, mdc, mmc=1, resto, i=1, A, B
	

		enquanto(i!=2){
				
			escreva("\nDigite o valor de a: \n")
			leia(a)
			limpa()
			
			escreva("\nDigite o valor de b: \n")
			leia(b)
			limpa()

			se(a>0 e b>0){
		
				enquanto(a!=0 e b!=0){
					A=a
					B=b
					
					enquanto(b!=0){
						resto=a%b
						a=b
						b=resto
						
					}mdc=a
					escreva("MDC = ",mdc)
		
					mmc=A*(B/mdc)
					escreva(" e MMC = ",mmc," \n")
				
				}
			}senao se(a==0 e b==0){
				i=2
			
			}senao{
				
				escreva("Um ou os dois números digitados foram invalidos!\n")
				escreva("Quer continuar? <1>Sim <2>Não\n")
				leia(i)
				limpa()
				
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 688; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */