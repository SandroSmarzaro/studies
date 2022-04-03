package com.san.question08;

import java.util.Scanner;

public class Question08 {
    public void inclination() {
        Scanner scanner = new Scanner(System.in);
        double x, y, radianAngle, degreeAngle;
        System.out.print("\nInsert the x: ");
        x = scanner.nextDouble();
        System.out.print("\nInsert the y: ");
        y = scanner.nextDouble();
        scanner.close();

        radianAngle  = Math.atan2(y, x);
        degreeAngle = Math.toDegrees(radianAngle);
        System.out.format("\n\nThe angle is: %.2fº\n\n", degreeAngle);
    }
}
