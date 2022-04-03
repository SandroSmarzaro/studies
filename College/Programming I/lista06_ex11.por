programa
{
	inclua biblioteca Matematica-->mat
	funcao inicio()
	{
		inteiro i=1, d, divisor=0,p,f, divprimo=0
		real quad, cubo, fatorial=1.0
		logico primo

		escreva("/ Número / Quadrado / Cubo / Fatorial / Divisores / Primos /\n")
		
		para(i=1;i<=100;i++){
			
			quad=mat.potencia(i, 2.0)
			
			cubo=mat.potencia(i, 3.0)

			f=i
			
			para(;f>=1;f--){
				fatorial=fatorial*f
			}

			para(d=1;i>=d;d++){
				se(i%d==0){
					divisor=divisor+1
				}
			}

			para(p=1;p<=i;p++){
				se(i%p==0){
					divprimo++
				}
			}se(divprimo==2 ou divprimo==1){
				primo=verdadeiro
			}senao{
				primo=falso
			}
			
			escreva("    ",i,"        ",quad,"      ",cubo,"      ",fatorial,"          ",divisor,"         ",primo," \n")
			
			
			se(i%10==0){
				escreva("\n/ Número / Quadrado / Cubo / Fatorial / Divisores / Primos /\n")
			}
			
			divisor=0
			fatorial=1
			divprimo=0
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 739; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */