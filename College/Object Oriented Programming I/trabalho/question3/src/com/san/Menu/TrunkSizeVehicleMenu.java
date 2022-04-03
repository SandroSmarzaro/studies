package com.san.Menu;

import java.util.Scanner;

public abstract class TrunkSizeVehicleMenu {
    protected static double input(Scanner scan) {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tTrunkSize of Vehicle: ");
        System.out.println("\n\t[0] - Cancel");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter TrunkSize: ");
        double trunkSize = scan.nextDouble();
        
        return trunkSize;
    }
}
