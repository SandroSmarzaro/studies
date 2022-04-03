package com.san.Menu;

import java.util.Scanner;

public abstract class MileageVehicleMenu {
    protected static double input(Scanner scan) {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tMileage of Vehicle: ");
        System.out.println("\n\t[0] - Cancel");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter Mileage: ");
        double mileageVehicle = scan.nextDouble();

        return mileageVehicle;
    }
}
