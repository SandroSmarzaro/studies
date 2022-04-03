import java.util.Scanner;

import com.sandro.Exception.NotEnoughFuelException;
import com.sandro.Exception.ZeroSpeedException;
import com.sandro.Vehicle.Vehicle;

public class App {

    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
    public static void main(String[] args) throws Exception {
        Vehicle car = new Vehicle(50, 55.5, 3, 10000);
        Scanner scan = new Scanner(System.in);
        short option;
        do {
            clearScreen();
            System.out.println("1 - Refuel");
            System.out.println("2 - Accelerate");
            System.out.println("3 - Brake");
            System.out.println("4 - Show Speed");
            System.out.println("5 - Show Fuel Volume");
            option = scan.nextShort();
            switch (option) {
                case 1:
                    System.out.println("What is the price of a liter?");
                    double literCoast = scan.nextDouble();
                    System.out.println("How much did you pay?");
                    double amountPaid = scan.nextDouble();  
                    double change = car.reful(literCoast, amountPaid);
                    if (change == 0) 
                        System.out.println("You've fueled your vehicle!");
                    else 
                        System.out.println("You filled the tank and you have " + change);
                    Thread.sleep(500);
                    break;

                case 2:
                    System.out.println("How many seconds did you accelerate?");
                    double secondsAccelarate = scan.nextDouble();
                    try {
                        car.accelerate(secondsAccelarate);
                        System.out.println("You accelerated for " + secondsAccelarate + " seconds!");
                    } catch (NotEnoughFuelException e) {
                        System.out.println(e.getMessage());
                    }
                    finally {
                        Thread.sleep(500);
                    }
                    break;
                
                case 3:
                    System.out.println("How many seconds did you brake?");
                    double secondsBrake = scan.nextDouble();
                    try {
                        car.brake(secondsBrake);
                        System.out.println("You brake for " + secondsBrake + " seconds!");
                    }
                    catch (ZeroSpeedException e) {
                        System.out.println(e.getMessage());
                    }
                    finally {
                        Thread.sleep(500);
                    }
                    break;

                case 4:
                    System.out.println("Current speed: " + car.getCurrentSpeed());
                    Thread.sleep(500);
                    break;

                case 5:
                    System.out.println("Current fuel volume: " + car.getFuelVolume());
                    Thread.sleep(500);
                    break;
            
                default:
                    System.out.println("Invalid option!");
                    Thread.sleep(500);
                    break;
            }

        } while(option != 0);
        scan.close();
        
    }
}
