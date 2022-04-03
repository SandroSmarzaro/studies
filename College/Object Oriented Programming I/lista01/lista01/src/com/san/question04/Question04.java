package com.san.question04;

public class Question04 {
    public void crossProduct() {
        final byte SIZE = 3;
        int[] firstArray = new int[SIZE];
        int[] secondArray = new int[SIZE];
        int[] crossProductArray = new int[SIZE];

        for (int index = 0; index < SIZE; index++) {
            firstArray[index] = (int) (Math.random() * 100);
            secondArray[index] = (int) (Math.random() * 100);
        }
        crossProductArray[0] = (firstArray[1] * secondArray[2]) - (firstArray[2] * secondArray[1]);
        crossProductArray[1] = (firstArray[2] * secondArray[0]) - (firstArray[0] * secondArray[2]);
        crossProductArray[2] = (firstArray[0] * secondArray[1]) - (firstArray[1] * secondArray[0]);

        for (int index = 0; index < SIZE; index++) {
            System.out.format("First Array: %d\n", firstArray[index]);
        }
        System.out.println();
        for (int index = 0; index < SIZE; index++) {
            System.out.format("Second Array: %d\n", secondArray[index]);
        }
        System.out.println();
        System.out.format("\nThe Cross Product is: (%d, %d, %d)\n", crossProductArray[0], crossProductArray[1], crossProductArray[2]);
    }
}