package com.san.clearScreen;

public class ClearScreen {
    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
    /*
    public static void clearScreen() throws IOException, InterruptedException {
       new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    }
    */
}
