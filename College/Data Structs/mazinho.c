#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define caracter 50
#define max_forn 70
#define max_prod 100

typedef struct
{
    int codigo_produto, codigo_fornecedor;
    float estoque_atual, estoque_minimo, preco_unitario;
    char nome_produto[caracter], descricao[caracter];
} Produto;

typedef struct
{
    int codigo;
    char nome[caracter], cpf_ou_cnpj[caracter], rua[caracter], bairro[caracter], complemento[caracter], numero[caracter], cidade[caracter], estado[caracter], telefone[caracter], ddd[caracter];
} Fornecedor;


//prototipação de funções
void ler_txt(Fornecedor fornecedores[], Produto produtos[],int  *qtd_p, int *qtd_f);
int main(void)
{
    
  Produto produtos[max_prod];
  Fornecedor fornecedores[max_forn];
  int opcao = 0;
  int qtd_p = 0;
  int qtd_f = 0;
    
  ler_txt(fornecedores, produtos, &qtd_p, &qtd_f);
    
    
  for(int i = 0; i < qtd_f; i++){
    printf("%s\n", fornecedores[i].nome);
  }


    while (opcao != 9)
    {
        printf("1 Para cadastrar fornecedor\n");
        printf("2 Para alterar fornecedor\n");
        printf("3 Para cadastrar produtos\n");
        printf("4 Para alterar produtos\n");
        printf("5 Para entrada de estoque\n");
        printf("6 Para realizar venda\n");
        printf("7 Para relatório estoque mínimo\n");
        printf("8 Para gravar dados\n");
        printf("9 Para sair\n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1 /*cadasatrar fornecedor*/:
            
            break;
        case 2 /*alterar Fornecedor*/:

            break;
        case 3 /*cadastrar produtor*/:

            break;
        case 4 /*alterar produtos*/:

            break;
        case 5 /*entrada de estoque*/:

            break;
        case 6 /*realizar venda*/:

            break;
        case 7 /*relatório estoque mínimo*/:

            break;
        case 8 /*gravar dados*/:

            break;
        case 9 /*sair*/:
            system("clear");
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void ler_txt(Fornecedor fornecedores[], Produto produtos[], int *qtd_p, int *qtd_f)
{
  int index_prod = 0;
  int count = 0;
  int auxiliar;
  char lixo[5];
  
  FILE *file_prod; 
  FILE *file_forn;

  file_prod = fopen("prod.txt", "r+");
  file_forn = fopen("forn.txt", "r+");
    //verificando se o arquivo .txt se exite
    if (file_forn == NULL && file_prod == NULL){
      return;
    }
  
  while(!feof(file_prod)){
    fscanf(file_prod,"%d", qtd_p);
    fscanf(file_prod,"%s", lixo);
    for(int i = 0; i < *qtd_p; i++){      
      fscanf(file_prod,"%d", &produtos[i].codigo_produto);
      fscanf(file_prod,"%s", produtos[i].nome_produto);
      fscanf(file_prod,"%s", produtos[i].descricao);
      fscanf(file_prod,"%d", &produtos[i].codigo_fornecedor);
      fscanf(file_prod,"%f", &produtos[i].preco_unitario);
      fscanf(file_prod,"%f", &produtos[i].estoque_atual);
      fscanf(file_prod,"%f", &produtos[i].estoque_minimo);
    }
  }

  fscanf(file_forn, "%d", qtd_f);
  fscanf(file_forn,"%s", lixo);
    while(!feof(file_forn)){
        for(int i = 0; i < *qtd_f; i++){
          fscanf(file_forn, "%d", &fornecedores[i].codigo);
          fscanf(file_forn, " %s", fornecedores[i].nome);
          fscanf(file_forn, "%s", fornecedores[i].cpf_ou_cnpj);
          fscanf(file_forn, " %s", fornecedores[i].rua);
          fscanf(file_forn, "%s", fornecedores[i].numero);
          fscanf(file_forn, " %s", fornecedores[i].complemento);
          fscanf(file_forn, " %s", fornecedores[i].bairro);
          fscanf(file_forn, " %s", fornecedores[i].cidade);
          fscanf(file_forn, "%s", fornecedores[i].estado);
          fscanf(file_forn, "%s", fornecedores[i].ddd);
          fscanf(file_forn, "%s", fornecedores[i].telefone); 
          fscanf(file_forn,"%s", lixo);
      }
    }
    fclose(file_forn);



  fclose(file_prod);
  fclose(file_forn);
}
