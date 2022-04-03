import java.util.Scanner;
import com.san.menu.Menu;

public class App {
    public static void main(String[] args) throws Exception {
        byte questionChoice;
        Scanner scanner = new Scanner(System.in);
        System.out.println("\nChoice your question:");
        questionChoice = scanner.nextByte();
        Menu menu = new Menu();
        menu.question(questionChoice);
        scanner.close();
    }
}
