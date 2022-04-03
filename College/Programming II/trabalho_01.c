#include <stdio.h>
#include <math.h>

typedef struct produto {
    int codigo;
    char nome[20];
    float preco;
    int estoque;
    float valorEstoque;
} tipoProduto;

typedef struct venda {
    int codigo;
    int numeroVenda;
    float preco;
    float total;
    int quantidade;
    int numeroParcelas;
} tipoVenda;

typedef struct parcela {
    int numeroVenda;
    int numeroParcela;
    float valorParcela;
    float total;

} tipoParcela;

//delimitando numero de produtos, venda, titulo e parcelas 
#define NUMEROPRODUTO 5
#define NUMEROVENDA 10
#define NUMEROTITULO 120
#define PARCELASMAXIMA 12

tipoProduto produtoEspecifico[NUMEROPRODUTO];
tipoVenda vendaEspecifica[NUMEROVENDA];
tipoParcela tituloEspecifico[NUMEROTITULO];
int ultimoProduto = 0;
int ultimaVenda = 0;
int ultimoTitulo = 0;
float totalVista = 0;
float totalPrazo = 0;
float totalGeral = 0;
float totalEstoque = 0;
float totalParcelas = 0;

void cadastrarProduto(tipoProduto produtos[]);
void venderProduto(tipoVenda venda[]);
void parcelarProduto(tipoParcela titulo[]);
void desenharLinha(int tamanho);
void listarParcelas();
void listarVendas();
void listarProdutos();

int main(){
    int opcao;
    do{
        puts("1 - Cadastrar Produtos");
        puts("2 - Vender Produtos");
        puts("3 - Listar vendas dos Produtos");
        puts("4 - Parcelas dos Produtos");
        puts("5 - Listar Produtos");
        puts("0 - Sair");
        puts("Digite sua escolha:");
        scanf(" %d", &opcao);
        switch(opcao){
            //opção pra sair do sistema
            case 0:
                puts("Obrigado por usar o sistema!");
                break;
            case 1:
                cadastrarProduto(produtoEspecifico);
                break;
            case 2:
                venderProduto(vendaEspecifica);
                break;
            case 3:
                listarVendas(ultimaVenda);
                break;
            case 4:
                parcelarProduto(tituloEspecifico);
                break;
            case 5:
                listarProdutos();
                break;
            //caso digite uma opção que não existe
            default:
                puts("Opcao invalida! Digite novamente:");
                break;
        }
    }while(opcao != 0);

    return 0;
}

void cadastrarProduto(tipoProduto produtos[]){
    int continuar;

    do{ 
        //caso seja o primeiro produto                                                
        if(ultimoProduto == 0){ 
            puts("Cadastre o codigo do Produto:");
            scanf(" %d", &produtos[ultimoProduto].codigo);
        }
        //caso seja diferente do primeiro
        else{
            puts("Cadastre o codigo do Produto:");
            scanf(" %d", &produtos[ultimoProduto].codigo);
            for(int count = 0; count < ultimoProduto; count++){
              //laço pra verificar cadastro existente
                while(produtos[ultimoProduto].codigo == produtos[count].codigo){
                    count = 0;
                    puts("Produto existente! Digite um novo:");
                    scanf(" %d", &produtos[ultimoProduto].codigo);
                }
            }
        }
        puts("Digite o nome:");
        scanf(" %[^\n]s", produtos[ultimoProduto].nome);      
        puts("Digite o preco:");
        scanf(" %f", &produtos[ultimoProduto].preco);
        //impossibilitando valores não permetidos para preço
        while(produtos[ultimoProduto].preco < 0){
          puts("Preco negativo, digite novamente:");
          scanf(" %f", &produtos[ultimoProduto].preco);
        }
        puts("Digite o estoque:");
        scanf(" %d", &produtos[ultimoProduto].estoque);
        //averiguando valor não aceitável para estoque
        while(produtos[ultimoProduto].estoque < 0){
          puts("Estoque negativo, digite novamente:");
          scanf(" %d", &produtos[ultimoProduto].estoque);
        }
        //calculando preço do estoque do produto
        produtos[ultimoProduto].valorEstoque = produtos[ultimoProduto].preco * produtos[ultimoProduto].estoque;
        //calculando  o valor do estoque total  
        totalEstoque += produtos[ultimoProduto].valorEstoque;
        ultimoProduto++;
        puts("Deseja continuar cadastrando?");
        puts("[1]   SIM     [0]     NAO");
        scanf(" %d", &continuar);
    }while(continuar != 0);
}

void venderProduto(tipoVenda venda[]){
    int igual = 0;
    int continuar;
    int codigoSalvo;

    do{
        do{
            puts("Digite o codigo do produto:");
            scanf(" %d", &venda[ultimaVenda].codigo);
            for(int count = 0; count < ultimoProduto; count++){
                //verificando se não existe o código
                if(venda[ultimaVenda].codigo == produtoEspecifico[count].codigo){
                    igual++;
                    //salvando a posição do codigo do produto na venda
                    codigoSalvo = count;
                }
            }
        }while(igual == 0);
        igual = 0;
        printf("Quantidade a ser vendida do produto: %s, valor: %.2f, estoque: %d\n", produtoEspecifico[codigoSalvo].nome, produtoEspecifico[codigoSalvo].preco, produtoEspecifico[codigoSalvo].estoque);
        scanf(" %d", &venda[ultimaVenda].quantidade);
        //Validando a quantidade a ser vendida ser compativel com o estoque
        while(produtoEspecifico[codigoSalvo].estoque - venda[ultimaVenda].quantidade < 0 || venda[ultimaVenda].quantidade < 0){
            puts("Quantidade negativa ou maior do que o estoque, digite novamente:");
            scanf("%d", &venda[ultimaVenda].quantidade);
        }
        //diminuindo a quantidade vendida no estoque, podia usar o truque "-="
        produtoEspecifico[codigoSalvo].estoque -=  venda[ultimaVenda].quantidade;
        venda[ultimaVenda].preco = produtoEspecifico[codigoSalvo].preco;
        //calculando o valor total da venda
        venda[ultimaVenda].total = venda[ultimaVenda].quantidade * venda[ultimaVenda].preco;
        puts("Quantidade de parcelas: (0 e 1 parcelas para a vista)");
        scanf(" %d", &venda[ultimaVenda].numeroParcelas);
        //limitando o valor do numero de parcelas
        while(venda[ultimaVenda].numeroParcelas > PARCELASMAXIMA || venda[ultimaVenda].numeroParcelas < 0){
            puts("Numero de parcelas negativo ou execede o maximo de 12x, digite novamente:");
            scanf(" %d", &venda[ultimaVenda].numeroParcelas);
        }
        //se o número de  parcelas for maior que 1 é a prazo, caso contrário é a vista
        if(venda[ultimaVenda].numeroParcelas > 0){
            totalPrazo += venda[ultimaVenda].total;
        }
        else{
            totalVista += venda[ultimaVenda].total;
        }
        //valor total de todos os itens
        totalGeral += venda[ultimaVenda].total;
        venda[ultimaVenda].numeroVenda = ultimaVenda + 1;
        ultimaVenda++;
        puts("Deseja continuar vendendo?");
        puts("[1]   SIM     [0]     NAO");
        scanf(" %d", &continuar);
    }while(continuar != 0);
}

void parcelarProduto(tipoParcela titulo[]){
    float soma = 0;
    int parcela;
    static int venda = 0;

    //Fazendo o titulo de todas as vendas
    for(; venda < ultimaVenda; venda++){
        parcela = 0;
        do{
            titulo[ultimoTitulo].numeroVenda = vendaEspecifica[venda].numeroVenda;
            titulo[ultimoTitulo].numeroParcela = parcela + 1;
            titulo[ultimoTitulo].total = vendaEspecifica[venda].total;
            //Quando o pagamento for à vista, valor da única parcela é o total
            if(vendaEspecifica[venda].numeroParcelas == 0){
                titulo[ultimoTitulo].valorParcela = vendaEspecifica[venda].total;
            }
            //Quando o pagamento for a prazo, divir cada título com o valor da parcela
            else{
                titulo[ultimoTitulo].valorParcela = vendaEspecifica[venda].total / vendaEspecifica[venda].numeroParcelas;
            }
            //Arredondar o valor da parcela
            titulo[ultimoTitulo].valorParcela = floor(titulo[ultimoTitulo].valorParcela * 100) / 100;
            //somando o valor das parcelas
            totalParcelas += titulo[ultimoTitulo].valorParcela;
            soma += titulo[ultimoTitulo].valorParcela;
            ultimoTitulo++;
            parcela++;
        }while(parcela < vendaEspecifica[venda].numeroParcelas);
        //se a soma das parcelas forem menor que o valor total , acrescentar a diferença na ultima parcela
        if(soma < vendaEspecifica[venda].total){
            titulo[ultimoTitulo - 1].valorParcela += vendaEspecifica[venda].total - soma;
            totalParcelas += vendaEspecifica[venda].total - soma;
        }
        soma = 0;
    }
    listarParcelas();
}

void desenharLinha(int tamanho){
    for(int count = 0; count < tamanho; count++){
        printf("-");
    }
    puts("");
}

void listarParcelas(){
    desenharLinha(45);
    puts("Venda |  Total  | Parcela | ValorParcela");
    desenharLinha(45);
    for(int count = 0; count < ultimoTitulo; count++){
        printf("%2d    %9.2f     %2d        %9.2f\n", tituloEspecifico[count].numeroVenda, tituloEspecifico[count].total, tituloEspecifico[count].numeroParcela, tituloEspecifico[count].valorParcela);
    }
    desenharLinha(45);
    printf("Total das Parcelas            %9.2f\n", totalParcelas);
    desenharLinha(45);
    puts("");
}

void listarVendas(int ultimo){
    desenharLinha(70);
    puts("Venda |  Produto  | Quant |   Preco   |   Total   | Parcelas");
    desenharLinha(70);
    for(int count = 0; count < ultimo; count++){
        printf("%2d         %3d       %3d   %9.2f     %9.2f     %3d\n", vendaEspecifica[count].numeroVenda, vendaEspecifica[count].codigo, vendaEspecifica[count].quantidade, vendaEspecifica[count].preco, vendaEspecifica[count].total, vendaEspecifica[count].numeroParcelas);
    }
    desenharLinha(70);
    printf("Total a Vista                            %9.2f\n", totalVista);
    printf("Total a Prazo                            %9.2f\n", totalPrazo);
    printf("Total das vendas                         %9.2f\n", totalGeral);
    desenharLinha(70);
    puts("");
}

void listarProdutos(){
    desenharLinha(70);
    puts("   Codigo   |    Preco    |  Quant  |    Total    |   Nome");
    desenharLinha(70);
    for(int count = 0; count < ultimoProduto; count++){
        printf("%5d         %9.2f       %3d      %9.2f       %s\n", produtoEspecifico[count].codigo, produtoEspecifico[count].preco, produtoEspecifico[count].estoque, produtoEspecifico[count].valorEstoque, produtoEspecifico[count].nome);
    }
    desenharLinha(70);
    printf("Total do Estoque                       %9.2f\n", totalEstoque);
    desenharLinha(70);
    puts("");
}

/*
-----------------MELHORIAS---------------------
1. Não aceitar estoque negativo             OK
2. Não aceitar preços negativos             OK
3. Mostrar dados dos produtos na venda      OK
4. Acertar total a vista                    OK
5. Total das parcelas                       OK
6. Ver nome das variávei de controle        OK
------------------------------------------------
*/