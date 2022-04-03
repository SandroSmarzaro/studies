package com.san.question02;

import java.util.Scanner;

public class Question02 {
    public void calculator() {
        int x1, x2;
        Scanner scanner = new Scanner(System.in);
        System.out.println("\nEnter the value of x1:");
        x1 = scanner.nextInt();
        System.out.println("\nEnter the value of x2:");
        x2 = scanner.nextInt();
        scanner.close();

        System.out.format("\nSum: %d\nDifference: %d\nMultiplication: %d\nDivision: %f\n\n", x1 + x2, x1 - x2, x1 * x2, (float) x1 / x2);
    }
}
