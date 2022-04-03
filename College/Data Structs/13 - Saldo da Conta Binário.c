#include <stdio.h>
#define MAX 15

struct contaCliente{
  unsigned int NConta;
  char nome[MAX];
  char sobrenome[MAX];
	double saldo;
};

unsigned int escolha(void);
void arquivoTexto(FILE *readPtr);
void alteraRegistro(FILE *fPtr);
void novoRegistro(FILE *fPtr);
void apagaRegistro(FILE *fPtr);

int main(void)
{
	 // Leitura do arquivo
	 // Verificar exixtência, ou criar um novo
	 
   FILE *cfPtr; 
   if ((cfPtr = fopen("contas.dat", "rb+")) == NULL) {
      puts("não abre.");
   } 
   else { 
      unsigned int opcao; // opção do usuário
      while ((opcao = escolha()) != 5) { 
         switch (opcao) { 
            case 1:
               arquivoTexto(cfPtr);
               break;
            case 2:
               alteraRegistro(cfPtr);
               break;
            case 3:
               novoRegistro(cfPtr);
               break;
            case 4:
               apagaRegistro(cfPtr);
               break;
            default:
               puts("Opção Inválida");
               break;
         } 
      } 
      fclose(cfPtr); 
   }
}

// Menu de opções
unsigned int escolha(void)
{ 
   unsigned int opcao; // variable to store user's opcao
   printf("%s", "\nEntre com a opção\n"
      "1 - criar arquivo texto com as contas\n"
      "    \"contas.txt\" \n"
      "2 - Altera uma conta\n"
      "3 - Adiciona um registro\n"
      "4 - apaga uma conta\n"
      "5 - fim do programa\n? ");
   scanf("%u", &opcao); // receive opcao from user
   return opcao;
} 

void arquivoTexto(FILE *readPtr){
	FILE *escritaPtr;
  struct contaCliente conta = {0, "", "", 0};
	if((escritaPtr = fopen("contas.txt","w"	)) == NULL){
		puts("arquivo não pode ser aberto");
	} else{
		rewind(readPtr);
    fprintf(escritaPtr,"Conta  Nome            Sobrenome    Saldo\n");
    fread(&conta, sizeof(struct contaCliente), 1, readPtr);
    while(!feof(readPtr)){
      if(conta.NConta != 0){
				// Imprime cabeçalho no arquivo de relatório
        fprintf(escritaPtr, "%4d   %-15s %-10s %10.2f\n", conta.NConta, conta.nome, conta.sobrenome, conta.saldo);
      }
			// Lê um registro no arquivo e avança o ponteiro de arquivo
      fread(&conta, sizeof(struct contaCliente), 1, readPtr);
    }
    fclose(escritaPtr);
  }
}
// Altera o saldo de uma conta de um registro específico
// o vaor informado será adicionado ou subraido 
void alteraRegistro(FILE *fPtr){
   unsigned int contaId;
   puts("Conta para alterar (1 - 100): ");
   scanf("%d", &contaId);   
	 //posiciona fPtr na posição do registro desejado        
   fseek(fPtr, (contaId - 1) * sizeof(struct contaCliente), SEEK_SET);
   struct contaCliente conta = {0, "", "", 0.0};
	 // lê o registro desejado do arquivo e posiciona na variável
   fread(&conta, sizeof(struct contaCliente), 1, fPtr);
   if (conta.NConta == 0) {
      printf("conta #%d sem informação.\n", contaId);
   }
   else { // altera
      printf("%-6d%-16s%-16s%10.2f\n\n", 
        conta.NConta, conta.nome, 
        conta.sobrenome, conta.saldo);
      // faz tranzação
      printf("%s", "Entre com valor positivo Débito (+)\n"
             "ou positivo para Crédito (-): ");
      double tranzacao; //  valor da tranzação 
      scanf("%lf", &tranzacao);
      conta.saldo += tranzacao; // atualizacão do saldo
      printf("%-6d%-16s%-11s%10.2f\n", 
         conta.NConta, conta.nome, 
         conta.sobrenome, conta.saldo);
      // move ponteiro para a posição             
      fseek(fPtr, (contaId - 1) * sizeof(struct contaCliente), SEEK_SET);
      // atualiza       
      fwrite(&conta, sizeof(struct contaCliente), 1, fPtr);
   } 
}
void novoRegistro(FILE *fPtr){
   printf("%s", "Entre com o número da conta (1 - 100): ");
   unsigned int contaId;
   scanf("%d", &contaId);
	 // posiciona no registro lido, lembrando que a gravação começa da posição 0
	 // e as contas começão do 1
   fseek(fPtr, (contaId - 1) * sizeof(struct contaCliente), SEEK_SET);          
   struct contaCliente conta = { 0, "", "", 0.0 };
   fread(&conta, sizeof(struct contaCliente), 1, fPtr);
	 //verifica se a conta na posição escolhida já está cadastrada
   if (conta.NConta != 0) {
      printf("conta #%d já cadastrada.\n",
         conta.NConta);
   }
   else { // Cria registro
      printf("%s", "Entre com nome, sobrenome, saldo\n? ");
      scanf("%14s%14s%lf", conta.nome, conta.sobrenome, &conta.saldo);
      conta.NConta = contaId; 
      fseek(fPtr, (conta.NConta - 1) * sizeof(struct contaCliente), SEEK_SET);
      // insere os dados na posição selecionada
      fwrite(&conta, sizeof(struct contaCliente), 1, fPtr);     
   } 
}
void apagaRegistro(FILE *fPtr){
	// obtendo conta para apagar
	printf("%s", "Conta para apagar (1 - 100): ");
	unsigned int contaId;
	scanf("%d", &contaId);

	// movimenta o ponteiro para o registro específico               
	fseek(fPtr, (contaId - 1) * sizeof(struct contaCliente), SEEK_SET);                                                 
	struct contaCliente conta; // estrutura para receber os dados lidos

	// lê registro do arquivo                               
	fread(&conta, sizeof(struct contaCliente), 1, fPtr);

	if (conta.NConta == 0) {
		printf("conta %d não existe.\n", contaId);
	} 
	else { // delete record
		fseek(fPtr, (contaId - 1) * sizeof(struct contaCliente), SEEK_SET);
		struct contaCliente contaVazia = { 0, "", "", 0 };
		// altera a conta para uma conta vazia
		fwrite(&contaVazia,sizeof(struct contaCliente), 1, fPtr);
	}
}
