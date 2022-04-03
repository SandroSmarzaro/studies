package com.san.Menu;

public abstract class CarModelsMenu {
    protected static void show() {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\t1 - Hatchback");
        System.out.println("\t2 - Sedan");
        System.out.println("\t3 - SUV");
        System.out.println("\t4 - Truck");
        System.out.println("\t0 - Cancel");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter your option: ");
    }
}
