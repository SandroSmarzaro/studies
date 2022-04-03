programa
{
	inclua biblioteca Matematica--> mat
	funcao inicio()
	{

		inteiro num_perfeito, divisor=1, soma_divisores=0;
		
		para(inteiro n=1;n<=10;n++){
			
			num_perfeito=mat.potencia(2, n-1)*((mat.potencia(2, n))-1);
					
			enquanto(num_perfeito>divisor){
				
				se(num_perfeito%divisor==0){
					
					soma_divisores= soma_divisores+divisor;

				}
			
			divisor++;
			
			}
			
			se(num_perfeito == soma_divisores){
						
				escreva(num_perfeito," ");
					
			}
			
			soma_divisores=0;
			divisor=1;				
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 263; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {num_perfeito, 7, 10, 12}-{divisor, 7, 24, 7}-{soma_divisores, 7, 35, 14}-{n, 9, 15, 1};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */