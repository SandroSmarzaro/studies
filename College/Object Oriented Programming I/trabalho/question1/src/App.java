import com.sandro.Circle.Circle;
import com.sandro.Execeptions.NegativeValueException;

public class App {

    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
    public static void main(String[] args) throws Exception {
        clearScreen();
        try {
            System.out.println("\nConstruindo um círculo com raio negativo");
            Circle circle = new Circle(0, 1, 2);
            circle.setRadius(-1);
        }
        catch (NegativeValueException e) {
            System.out.println(e.getMessage());
        }
        Circle circle = new Circle(1, 1, 1);
        
        try {
            System.out.println("\nDefinindo um raio negativo ao círculo");
            circle.setRadius(-1);
        }
        catch (NegativeValueException e) {
            System.out.println(e.getMessage());
        }

        try {
            System.out.println("\nAumentando uma porcentagem negativa ao raio");
            circle.increaseRadius(-1);
        }
        catch (NegativeValueException e) {
            System.out.println(e.getMessage());
        }

        circle.setRadius(2.9);
        circle.increaseRadius(5.3);
        circle.setCicleCenter(1.4, 5.694);
        double radius = circle.getRadius();
        double[] coordinates = circle.getCoordinates();
        double area = circle.getCircleArea();
        double perimeter = circle.getCircumference();
        System.out.printf("\nRaio: %.2f\nCoordenada X: %.2f\nCoordenada Y: %.2f\nÁrea: %.2f\nCircuferência: %.2f\n\n", radius, coordinates[0], coordinates[1], area, perimeter);
    }
    
}