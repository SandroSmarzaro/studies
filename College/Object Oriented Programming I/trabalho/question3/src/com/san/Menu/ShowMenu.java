package com.san.Menu;

public abstract class ShowMenu {
    public static void show() {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\t1 - Vehicles for Sale");
        System.out.println("\t2 - Register Sales");
        System.out.println("\t3 - Sell Vehicle");
        System.out.println("\t4 - Registred Sales");
        System.out.println("\t0 - Exit");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
    }
}
