package com.san.question07;

public class Question07 {
    public void euclideanDistance() {
        double x1, x2, y1, y2, distance;
        System.out.print("\nEnter the x1 coordinate: ");
        x1 = Double.parseDouble(System.console().readLine());
        System.out.print("\nEnter the y1 coordinate: ");
        y1 = Double.parseDouble(System.console().readLine());
        System.out.print("\nEnter the x2 coordinate: ");
        x2 = Double.parseDouble(System.console().readLine());
        System.out.print("\nEnter the y2 coordinate: ");
        y2 = Double.parseDouble(System.console().readLine());
        distance = Math.sqrt(
            Math.pow((x2 - x1), 2) + 
            Math.pow((y2 - y1), 2)
        );
        System.out.format("\n\nThe distance between the two points is: %.2f\n\n", distance);
    }
    
}
