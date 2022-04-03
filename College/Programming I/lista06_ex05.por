programa
{
	
	funcao inicio()
	{
		inteiro num, soma, impar, par, soma_impar, soma_par,i
		real = media, media_par, media_impar

		i=1, par=0, impar=0, soma=0, soma_impar=0, media=0.0, soma_par=0, media_par=0.0, media_impar=0.0

		enquanto(i<=5){
			escreva("Digite um número inteiro: \n")
			leia(num)	
			limpa()

			soma=soma+num
			media=soma/5.0
			
			i++

			se(num%2==0){
				par=par+1
				soma_par=soma_par+num
				media_par=soma_par/5.0
			}senao{
				impar=impar+1
				soma_impar=num+soma_impar
				media_impar=soma_impar/5.0
				
			}
			
		}
		escreva("O número de impares é: ",impar," \n")
		escreva("O número de pares é: ",par, " \n")
		escreva("Média é: ",media," \n")
		escreva("A média impar é: ",media_impar," \n")
		escreva("A media par é: ",media_par," \n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 536; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */