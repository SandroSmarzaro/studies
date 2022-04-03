package com.san.ex04;

import com.san.clearScreen.ClearScreen;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.TemporalAdjusters;
import java.util.Scanner;

public class Ex04 {
    public static void sundaysOfMonth() {
        ClearScreen.clearScreen();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number of year:");
        int year = scanner.nextInt();
        System.out.println("Enter a number of month:");
        int month = scanner.nextInt();
        scanner.close();

        LocalDate date = LocalDate.of(year, month, 1);
        LocalDate firstSunday = date.with(TemporalAdjusters.firstInMonth(DayOfWeek.SUNDAY));
        int intMonth = date.getMonthValue();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        do {
            System.out.println(firstSunday.format(formatter));
            firstSunday = firstSunday.plusWeeks(1);
        } while (firstSunday.getMonthValue() == intMonth);
    }
}
