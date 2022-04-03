package com.san.ex02;

import com.san.clearScreen.ClearScreen;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.TemporalAdjuster;
import java.time.temporal.TemporalAdjusters;
import java.util.Scanner;

public class Ex02 {
    public static void paymentSlip() {
        ClearScreen.clearScreen();
        System.out.println("Enter the date of expiration: ");
        Scanner scanner = new Scanner(System.in);
        String expirationDateSting = scanner.nextLine();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate expirationDate = LocalDate.parse(expirationDateSting, formatter);

        DayOfWeek dayOfWeek = expirationDate.getDayOfWeek();
        if (dayOfWeek == DayOfWeek.SUNDAY || dayOfWeek == DayOfWeek.SATURDAY) {
            LocalDate newExpirationDate = expirationDate.with(TemporalAdjusters.next(DayOfWeek.MONDAY));
            System.out.format(
                    "The next business day is: %s",
                    newExpirationDate.format(formatter)
            );
        }
        else System.out.println("The expiration date is valid");
    }
}
