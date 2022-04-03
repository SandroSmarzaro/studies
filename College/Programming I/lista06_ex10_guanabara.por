programa
{
	
	funcao inicio()
	{
		inteiro m=0, num, i=1, div_par=0, fatorial=0, soma=0,t=1

	enquanto(t!=2){
		escreva("Acrescente um valor a m: \n")
		leia(num)

		limpa()

		se(num<=0){
			escreva("Número inválido!\n")
		
		}senao se(num>0){
						
				m=m+num
				se(num%2==0){
					para(i=1;m>=i;i++){
						se(m%i==0){
							div_par++
						}
					}
					escreva(div_par,"\n") 
				i=1
							
				}senao se(num%2!=0 e num<12){
							
					para(i=1;num>=1;num--){
						escreva(num," x ")	
					}
				escreva("\n")
				i=1
				}senao se(num%2!=0 e num>12){
					
					para(i=1;num>=i;i++){
						soma=soma+i
					}
				escreva(soma,"\n")
				}			
			}	
		escreva("\nDeseja continuar? <1>Sim <2>Não \n")
		leia(t)
		limpa()
		
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 185; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */