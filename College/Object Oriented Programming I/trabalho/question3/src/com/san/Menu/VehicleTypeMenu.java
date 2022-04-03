package com.san.Menu;

import java.util.Scanner;

public abstract class VehicleTypeMenu {
    protected static byte input(Scanner scan) {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tIs Bike or Car?\n");
        System.out.println("[1] - Bike\t[2] - Car\t[0] - Cancel");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter your option: ");
        byte option = scan.nextByte();
        
        return option;
    }
}
