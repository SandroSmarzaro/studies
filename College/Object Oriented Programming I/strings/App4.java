package app;

public class App {
    public static void main(String[] args) throws Exception {
        String[] names = {"Alciano", "Beltrano", "Ciclano","Deltrano", "Euclaciano"};
        short[] ages = {18, 19, 20, 21, 22};
        double[] salaries = {1000.0, 2000.0, 3000.0, 4000.0, 5000.0};

        double sumSalary = 0.0;
        for (double salary : salaries) sumSalary += salary;
        double averageSalary = sumSalary / salaries.length;
        for (short index = 0; index < names.length; index++) {
            System.out.format("%12s | %,-7.2f | %3d |\n", names[index], salaries[index], ages[index]);
        }
        System.out.format("%12s | %,-7.2f |\n", "Average", averageSalary);
    }
}
