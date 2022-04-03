package com.san.Menu;

import java.util.Scanner;

public abstract class NameVehicleMenu {
    protected static String input(Scanner scan) {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tName of Vehicle: ");
        System.out.println("\n\t[0] - Cancel");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter Name: ");
        scan.nextLine();
        String nameVehicle = scan.nextLine();

        return nameVehicle;
    }
}
