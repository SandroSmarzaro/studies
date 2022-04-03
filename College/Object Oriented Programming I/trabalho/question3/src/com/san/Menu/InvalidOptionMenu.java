package com.san.Menu;

import java.io.IOException;

public abstract class InvalidOptionMenu {
    protected static void show() {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tInvalid Option!");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Type ENTER to continue.");
        try {
            System.in.read();
        } catch (IOException e) {}
    }
}
