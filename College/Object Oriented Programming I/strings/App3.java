import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Insert the CPF: ");
        String cpf = scanner.next();
        System.out.format("%b", validateCpf(cpf.trim()));
        scanner.close();
    }

    // INDEX: 0  1  2  3  4  5  6  7  8  9 10 11 12 13
    // CPF  : 1  1  1  .  1  1  1  .  1  1 1  -  0  0
    public static boolean validateCpf(String cpf) {
        if (cpf.length() != 14) return false;
        else if (!cpf.contains(".")) return false;
        else if (!cpf.contains("-")) return false;
        else if (cpf.charAt(3) != '.') return false;
        else if (cpf.charAt(7) != '.') return false;
        else if (cpf.charAt(11) != '-') return false;

        for (Character character : cpf) {
            if (character == "." || character == "-") continue;
            else if (!Character.isDigit(character)) return false;
        }
        return true;
    }
}
