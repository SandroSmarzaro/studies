package com.san.ex03;

import java.time.Month;
import java.time.YearMonth;
import java.util.Scanner;

public class Ex03 {
    public static void daysOfMouths() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the year:");
        int year = scanner.nextInt();
        scanner.close();
        for (Month month : Month.values()) {
            YearMonth yearMonth = YearMonth.of(year, month);
            System.out.println(month + " has " + yearMonth.lengthOfMonth() + " days");
        }
    }
}
