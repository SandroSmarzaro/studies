package com.san.Menu;

import java.util.Scanner;

public abstract class EngineCapacityMenu {
    protected static int input(Scanner scan) {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tEngine Capacity of Vehicle: ");
        System.out.println("\n\t[0] - Cancel");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter Capacity: ");
        int engineCapacity = scan.nextInt();

        return engineCapacity;
    }
}
