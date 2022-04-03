package com.san.Menu;

public abstract class ExitProgramMenu {
    protected static void show() {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tExiting Program...\n");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        try {
            Thread.sleep(Menu.WAITING_TIME);
        } catch (InterruptedException e) { }
        ClearScreenMenu.clearScreen();
    }
}
