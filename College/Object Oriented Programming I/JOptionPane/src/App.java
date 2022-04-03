import javax.swing.JOptionPane;

public class App {
    public static void main(String[] args) throws Exception {
        String test = JOptionPane.showInputDialog(null, "Enter Number:");
        JOptionPane.showMessageDialog(null, "You entered: " + test);
    }
}
