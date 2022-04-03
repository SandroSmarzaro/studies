// Consulta saldos deitel
#include <stdio.h>

int main(void)
{ 
   FILE *clientesPtr; // ponteiro para clientes

   // tenta abrir o arquivo, sai do programa caso não consiga
   if ((clientesPtr = fopen("clientes.txt", "r")) == NULL) {
      puts("Arquivo não pode ser aberto");
   }
   else {
      // menu de opções
      printf("%s", "Escolha a opção\n"
         " 1 - Lista contas com saldo zero\n"
         " 2 - Lista contas em credito\n"
         " 3 - Lista contas em debito\n"
         " 4 - Lista cliente específico e o saldo\n"
         " 5 - termina\n? ");
      unsigned int opcao;
      scanf("%u", &opcao);

      // processa a opção
      while (opcao != 5) { 
         unsigned int conta; // número da conta
         double saldo; // saldo da conta
         char nome[30]; // nome do titular
         int contaPesq;
         int encontrou;

         // lê os dados da conta do arquivo           
         fscanf(clientesPtr, "%d%29s%lf", &conta, nome, &saldo);

         switch (opcao) { 
            case 1:
               puts("\nContas com saldo zero:");
               // lê arquivo até o fim
               while (!feof(clientesPtr)) { 
                  // testa saldo
                  if (saldo == 0) {
                     printf("%-10d%-13s%7.2f\n", 
                        conta, nome, saldo);
                  } 
                  // l6e dados do arquivo
                  fscanf(clientesPtr, "%d%29s%lf",                   
                     &conta, nome, &saldo);                
               } 
               break;
            case 2:
               puts("\nContas em crédito:\n");

               // Lê dados do início ao fim do arquivo
               while (!feof(clientesPtr)) { 
                  // saida de registros com saldo menor que 0
                  if (saldo < 0) {
                     printf("%-10d%-13s%7.2f\n", 
                        conta, nome, saldo);
                  } 
                  // lê dados do arquivo
                  fscanf(clientesPtr, "%d%29s%lf",                   
                     &conta, nome, &saldo);                
               } 
               break;
            case 3:
               puts("\n Contas em débito:\n");

               // lê até o fim do arquivo
               while (!feof(clientesPtr)) { 
                  // output only if balance is greater than 0
                  if (saldo > 0) {
                     printf("%-10d%-13s%7.2f\n", 
                        conta, nome, saldo);
                  } 

                  // read account, name and balance from file
                  fscanf(clientesPtr, "%d%29s%lf",                   
                     &conta, nome, &saldo);                
               } 

              break;
						case 4:
              printf("Numero da conta a ser pesquisada: ");
              scanf("%d", &contaPesq);
              encontrou = (contaPesq == conta);

              while(!feof(clientesPtr) && !encontrou){
                fscanf(clientesPtr, "%d%29s%lf", &conta, nome, &saldo);
								encontrou = (contaPesq == conta);   
              }

              if(encontrou == 0){
                puts("Conta nao encontrada");
              } else {
                printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
							}
              
              break;
						         
         }  
         rewind(clientesPtr); // manda clientesPtr para o início do arquivo

         printf("%s", "\n? ");
         scanf("%d", &opcao);
      } 

      puts("End of run.");
      fclose(clientesPtr); // fecha arquivo
   } 
} 
/*

'''
n = int(input())
soma = 0
for valor in range(1, n+1):
	soma += valor
print(soma)

O(fat(n))

''' 

n = int(input())
soma = ((1 + n) * n) / 2
O(1)

*/
/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/