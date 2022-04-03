import java.io.IOException;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        byte option;
        do {
            clearScreen();
            showMenu();
            option = getOption(scanner);
            double result = calculateNumbers(option, scanner);
            System.out.format("\nResult: %.3f", result);
            Thread.sleep(500);
        } while (option != 0 );
        scanner.close();
    }
    public static void clearScreen() throws IOException, InterruptedException {
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();    
    }
    public static void showMenu() {
        System.out.println("1 - Sum");
        System.out.println("2 - Diference");
        System.out.println("3 - Product");
        System.out.println("4 - Division");
        System.out.println("0 - Exit");
    }
    public static byte getOption(Scanner scanner) {
        byte option = scanner.nextByte(5);
        return option;
    }
    public static float[] getNumbers(Scanner scanner) {
        float[] numbers = new float[2];
        numbers[0] = scanner.nextFloat();
        numbers[1] = scanner.nextFloat();
        return numbers;
    }
    public static double calculateNumbers(byte option, Scanner scanner) throws InterruptedException {
        double result = 0;
        switch (option) {
            case 0:
                System.out.println("Exiting of System...");
                Thread.sleep(500);
                break;
            float[] numbers = getNumbers(scanner);
            float x = numbers[0];
            float y = numbers[1];
            case 1:
                return sumNumbers(x, y);
            case 2:
                return diferneceNumbers(x, y);
            case 3:
                return productNumbers(x, y);
            case 4:
                return divisionNumbers(x, y);
            default:
                System.out.println("Incorrect Option! Anweser again.");
                Thread.sleep(500);
                break;
        }
        return result;
    }
    public static double sumNumbers(float x, float y) {
        return x + y;
    }
    public static double diferneceNumbers(float x, float y) {
        return x - y;
    }
    public static double productNumbers(float x, float y) {
        return x * y;
    }
    public static double divisionNumbers(float x, float y) {
        if (y == 0) return Double.POSITIVE_INFINITY;
        return x / y;
    }
}
