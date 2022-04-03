package com.san.Menu;

import java.util.Scanner;

public abstract class NumberOfDoorsVehicleMenu {
    protected static short input(Scanner scan) {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tNumbers of Doors: ");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter Number: ");
        short numberOfDoors = scan.nextShort();

        return numberOfDoors;
    }
}
