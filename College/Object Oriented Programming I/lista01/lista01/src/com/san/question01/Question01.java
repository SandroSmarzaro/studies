package com.san.question01;

import java.util.Scanner;

public class Question01 {
    public void getArea() {
        float length, width, area;

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the length of the rectangle: ");
        length = scan.nextFloat();
        System.out.println("Enter the width of the rectangle: ");
        width = scan.nextFloat();
        scan.close();

        area = length * width;
        System.out.println("\nThe area  is: " + area + "\n");
    }
    
}