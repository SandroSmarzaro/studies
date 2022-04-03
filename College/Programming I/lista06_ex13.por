programa
{
	
	funcao inicio()
	{
		inteiro pessoas
		real peso, altura, imc
		cadeia nome
		
		para(pessoas=1;pessoas<=50;pessoas++){

			escreva("\nDigite o nome ou digite 'sair' para parar o programa: \n")
			leia(nome)

			limpa()

			se(nome!="sair"){
				
				escreva("Digite o peso em (kg): \n")
				leia(peso)

				limpa()

				escreva("Digite a altura em (m); \n")
				leia(altura)

				limpa()

				imc=peso/(altura*altura)

				se(imc<=18.5){
					escreva(nome," está abaixo do peso ideal.\n")
				
				}senao se(imc>18.5 e imc<=24.9){
					escreva(nome," parabéns! Você está no seu peso ideal!\n")
				
				}senao se(imc>=25 e imc<=29.9){
					escreva(nome," você está acima do seu peso(sobrepeso).\n")
				
				}senao se(imc>=30){
					escreva(nome," está em obesidade.\n")
				}		
			}senao{
				pessoas=51
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 763; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {pessoas, 6, 10, 7}-{nome, 8, 9, 4};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */