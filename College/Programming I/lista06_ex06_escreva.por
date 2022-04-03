programa
{
	
	funcao inicio()
	{
		real num=1.0, suc=0.0, ant=0.0, atual=0.0

		
		enquanto(num!=0){
				escreva("Digite um número: \n")
				leia(num)
				limpa()

				se(num!=0){
				ant=atual	
			
				atual=suc
				
				suc=num
			
				escreva("Antecessor: ",ant," ,atual: ",atual,"  e sucessor:",suc,"  \n")			
				}senao
					escreva("Antecessor: ",ant," ,atual: ",atual,"  e sucessor:",suc,"  \n")	
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 330; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */