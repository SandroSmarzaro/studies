programa
{
	
	funcao inicio()
	{
		inteiro i
		real a, b, c

		escreva("Digite o valor de I de 1 a 3; \n")
		leia(i)
		limpa()

		se(i==1 ou i==2 ou i==3){
		
			escreva("Digite qualquer valor de A; \n")
			leia(a)
			limpa()

			escreva("Digite qualquer valor de B; \n")
			leia(b)
			limpa()
	
			escreva("Digite qualquer valor de C; \n")
			leia(c)
			limpa()
			
			escolha(i){
				caso 2:
					se(a>b e b>c){
						escreva(a,b,c)
						}senao se(a>c e c>b){
							escreva(a,c,b)
						}senao se(b>a e a>c){
							escreva(b,a,c)
						}senao se(b>c e c>a){
							escreva(b,c,a)
						}senao se(c>b e b>a){
							escreva(c,b,a)
						}senao se(c>a e a>b){
							escreva(c,a,b)
						}pare
	
				caso 1:
					se(a>b e b>c){
						escreva(c,b,a)
						}senao se(a>c e c>b){
							escreva(b,c,a)
						}senao se(b>a e a>c){
							escreva(c,a,b)
						}senao se(b>c e c>a){
							escreva(a,c,b)
						}senao se(c>b e b>a){
							escreva(a,b,c)
						}senao se(c>a e a>b){
							escreva(b,a,c)
						}pare
	
				caso 3:
					se(a>b e b>c){
						escreva(c,a,b)
						}senao se(a>c e c>b){
							escreva(b,a,c)
						}senao se(b>a e a>c){
							escreva(c,b,a)
						}senao se(b>c e c>a){
							escreva(a,b,c)
						}senao se(c>b e b>a){
							escreva(a,c,b)
						}senao se(c>a e a>b){
							escreva(b,c,a)
						}pare
			}
		}senao
			escreva("Valor de I inválido \n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 148; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */