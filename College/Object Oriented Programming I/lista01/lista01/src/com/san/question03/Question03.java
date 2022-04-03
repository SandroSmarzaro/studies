package com.san.question03;

import java.util.Scanner;

public class Question03 {
    public void primeNumber() {
        int number;
        Scanner scanner = new Scanner(System.in);
        System.out.println("\nEnter the number:");
        number = scanner.nextInt();
        scanner.close();
        if (number != 0) {
            int quantityPrime = 0;
            for (int turnNumber = 2; turnNumber < number; turnNumber++) {
                int divisorsNumber = 0;
                for (int auxiliar = turnNumber; auxiliar > 1; auxiliar--) {
                    if (turnNumber % auxiliar == 0) {
                        divisorsNumber++;
                    }
                }
                if (divisorsNumber < 2) {
                    quantityPrime++;
                }
            }
            System.out.format("\nThe quantity of prime numbers is: %d\n", quantityPrime);
        }
        else {
            System.out.println("\nThe number is not valid.\n");
        }
    }
}
