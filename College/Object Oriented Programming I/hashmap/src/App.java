import java.io.IOException;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;

public class App {
    public static void main(String[] args) throws IOException, InterruptedException {
        clearScreen();
        HashMap<Integer, String> produtos = new HashMap<>();
        HashMap<Integer, Double> precos = new HashMap<>();
        int opcao;
        do {
            Scanner scanner = new Scanner(System.in);
            clearScreen();
            opcao = menu(scanner);
            clearScreen();
            processarMenu(opcao, produtos, precos, scanner);
        } while (opcao != 0);
    }

    public static void clearScreen() throws IOException, InterruptedException{
        System.out.print("\033[H\033[2J");
        System.out.flush();
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    }

    public static int menu(Scanner scanner) {
        System.out.format("%s\n", "-".repeat(50));
        System.out.println("1 - Cadastrar Produto");
        System.out.println("2 - Alterar Produtos");
        System.out.println("3 - Remover Produtos");
        System.out.println("4 - Listar Produtos");
        System.out.println("0 - Sair");
        System.out.format("%s\n", "-".repeat(50));
        System.out.print("Digite a opção desejada: ");

        return scanner.nextInt();
    }

    public static void processarMenu(int opcao, HashMap<Integer, String> produtos, HashMap<Integer, Double> precos, Scanner scanner) throws InterruptedException, IOException {
        switch (opcao) {
            case 0 -> sair();
            case 1 -> cadastrarProduto(produtos, precos, scanner);
            case 2 -> alterarProduto(produtos, precos, scanner);
            case 3 -> removerProduto(produtos, precos, scanner);
            case 4 -> listarProdutos(produtos, precos);
            default -> opcaoInvalida();
        }
    }

    public static void sair() throws IOException, InterruptedException {
        clearScreen();
        System.out.format("%s\n\n", "-".repeat(50));
        System.out.println("\t\tSaindo...\n");
        System.out.format("%s", "-".repeat(50));
        Thread.sleep(1000);
    }

    public static void opcaoInvalida() throws IOException, InterruptedException {
        clearScreen();
        System.out.format("%s\n\n", "-".repeat(50));
        System.out.println("\tOpção inválida");
        System.out.format("\n%s\n\n", "-".repeat(50));
        System.out.println("Digite ENTER para continuar.");
        System.in.read();
    }

    public static void cadastrarProduto(HashMap<Integer, String> produtos, HashMap<Integer, Double> precos, Scanner scanner) throws IOException {
        System.out.format("%s\n", "-".repeat(50));
        System.out.print("Digite o nome do produto: ");
        scanner.nextLine();
        String nome = scanner.nextLine();
        System.out.print("\n\nDigite o preço do produto: ");
        Double preco = scanner.nextDouble();
        int key = obterProximaChave(produtos.keySet());
        produtos.put(key, nome);
        precos.put(key, preco);
        System.out.format("%s\n", "-".repeat(50));
        System.out.println("\nProduto cadastrado com sucesso!\n");
        System.out.println("Digite ENTER para continuar.");
        System.in.read();
    }

    public static int obterProximaChave(Set<Integer> keySet) {
        if (!keySet.isEmpty()) return Collections.max(keySet) + 1;
        return 1;
    }

    public static void alterarProduto(HashMap<Integer, String> produtos, HashMap<Integer, Double> precos, Scanner scanner) throws IOException{
        System.out.format("%s\n", "-".repeat(50));
        System.out.print("Digite o código do produto: ");
        int codigo = scanner.nextInt();

        if (produtos.containsKey(codigo)) {
            System.out.format("%s\n", "-".repeat(50));
            System.out.print("\nDigite o novo nome do produto: ");
            scanner.nextLine();
            produtos.replace(codigo, scanner.nextLine());
            System.out.print("\nDigite o novo preço do produto: ");
            precos.replace(codigo, scanner.nextDouble());
            System.out.format("%s\n", "-".repeat(50));
            System.out.println("\nProduto alterado com sucesso!\n");
        }
        else {
            System.out.format("%s\n", "-".repeat(50));
            System.out.println("\nProduto não encontrado!\n");
        }
        System.out.println("Digite ENTER para continuar.");
        System.in.read();
    }

    public static void removerProduto(HashMap<Integer, String> produtos, HashMap<Integer, Double> precos, Scanner scanner) throws IOException {
        System.out.format("%s\n", "-".repeat(50));
        System.out.print("Digite o código do produto: ");
        int codigo = scanner.nextInt();
        System.out.format("%s\n", "-".repeat(50));
        if (produtos.containsKey(codigo)) {
            produtos.remove(codigo);
            precos.remove(codigo);
            System.out.println("\nProduto removido com sucesso!\n");
        }
        else {
            System.out.println("\nProduto não encontrado!\n");
        }
        System.out.println("Digite ENTER para continuar.");
        System.in.read();
    }

    public static void listarProdutos(HashMap<Integer, String> produtos, HashMap<Integer, Double> precos) throws IOException {
        System.out.format("%s\n", "-".repeat(50));
        System.out.println("\tLista de Produtos");
        System.out.format("%s\n", "-".repeat(50));
        System.out.format("%3s\t%-15s %9s\n", "Cod", "Produto", "Preço");
        System.out.format("%s\n", "-".repeat(50));
        // for (Map.Entry<Integer, String> produto : produtos.entrySet()) {
        //     System.out.format("%-3d\t%-15s %,9.2f\n",produto.getKey(), produto.getValue(), precos.get(produto.getKey()));
        // }
        produtos.forEach((key, value) -> {
            System.out.format("%-3d\t%-15s %,9.2f\n", key, value, precos.get(key));
        });
        System.out.format("%s\n\n", "-".repeat(50));
        System.out.println("Digite ENTER para continuar.");
        System.in.read();
    }
}
