programa
{
	
	funcao inicio()
	{
		real nota, soma_nota_aluno=0, media_aluno, soma_geral=0, media_geral;
		inteiro num_aprovados=0, num_reprovados=0;
		
		para(inteiro i=1;i<=5;i++){
			
			para(inteiro p=1;p<=5;p++){

				escreva("Pro aluno ",i,"º digite o valor da prova ",p,"º:\n");
				leia(nota);
				limpa();

				soma_nota_aluno= soma_nota_aluno + nota;	//Cálculo da soma das notas do aluno
			}
			
			media_aluno= soma_nota_aluno/5.0; 	//Cálculo da média do aluno em si

			soma_geral= soma_geral + media_aluno;	//Cálculo da soma das notas médias de todos alunos
			
			escreva("A média do aluno ",i," é: ",media_aluno,"\n");
			
			se(media_aluno<60){
				
				escreva("Aluno ",i," está reprovado!\n");
				escreva("\n");
				num_reprovados++; 		//Contador de número de reprovados
			}
			senao{
				
				escreva("Aluno ",i," está aprovado!\n");
				escreva("\n");
				num_aprovados++;	//Contador de número de aprovados
			}

			soma_nota_aluno=0;
			media_aluno=0;
			
		}
		media_geral= soma_geral/5.0; 			//Cálculo da média de todos os alunos em si
		
		escreva("A média geral da turma é: ",media_geral,"\n");
		escreva("O números de alunos aprovados é ",num_aprovados,"\n");
		escreva("O números de alunos aprovados é ",num_reprovados,"\n");
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1200; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */