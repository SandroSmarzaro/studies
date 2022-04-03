package com.san.Menu;

public abstract class ClearScreenMenu {
    protected static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
