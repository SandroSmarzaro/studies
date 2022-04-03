package com.san.question05;

import java.util.Scanner;

public class Question05 {
    public void fiveAnalysis() {
        final byte SIZE = 5;
        float[] numbers = new float[SIZE];
        float[] evenNumbers = new float[SIZE];
        float[] oddNumbers = new float[SIZE];
        float bigger = Float.MIN_VALUE;
        float smaller = Float.MAX_VALUE;
        float sum = 0;
        float average;
        Scanner scanner = new Scanner(System.in);

        for (int index = 0; index < SIZE; index++) {
            System.out.format("Enter the %dº number: ", index + 1);
            numbers[index] = scanner.nextFloat();
            if (numbers[index] > bigger) bigger = numbers[index];
            else if (numbers[index] < smaller) smaller = numbers[index];
            sum += numbers[index];
        }
        for (byte index = 0; index < SIZE; index++) {
            byte countEven = 0;
            byte countOdd = 0;
            if (numbers[index] % 2 == 0) {
                evenNumbers[index] = numbers[countEven];
                countEven++;
            }
            else {
                oddNumbers[index] = numbers[countOdd];
                countOdd++;
            }
        }
        scanner.close();
        average = sum / (float) SIZE;
        System.out.format("\nBigger number: %.2f\n", bigger);
        System.out.format("Smaller number: %.2f\n", smaller);
        System.out.format("Average: %.2f\n", average);
        // System.out.format("Even numbers: %.2f\n", evenNumbers);
        // System.out.format("Odd numbers: %.2f\n\n", oddNumbers);
    }
}