package com.san.Menu;

import java.util.Scanner;

public abstract class PaymentTypeMenu {
    protected static byte input(Scanner scan) {
        ClearScreenMenu.clearScreen();
        System.out.format("%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.println("\tPayment Type: ");
        System.out.println("\n\t[1] - Credit Card");
        System.out.println("\t[2] - Debit Card");
        System.out.println("\t[3] - Cash");
        System.out.println("\t[0] - Cancel");
        System.out.format("\n%s\n\n", "-".repeat(Menu.QUANTITY_OF_CHARACTERS));
        System.out.print("Enter Payment Type: ");
        byte paymentType = scan.nextByte();
        
        return paymentType;
    }
}
