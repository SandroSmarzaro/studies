package com.san.ex01;

import com.san.clearScreen.ClearScreen;

import java.io.IOException;
// import java.time.Duration;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

public class Ex01 {
    public static void getDaysDifference() throws IOException, InterruptedException {
        ClearScreen.clearScreen();
        System.out.println("Enter your date of birth in the format dd/mm/yyyy:");
        Scanner scanner = new Scanner(System.in);
        String birthDateInsert = scanner.nextLine();
        scanner.close();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate birthDate = LocalDate.parse(birthDateInsert, formatter);
        // Period period = Period.between(birthDate, LocalDate.now());
        // Period period = birthDate.until(LocalDate.now());
        // Long daysDifference = LocalDate.now().toEpochDay() - birthDate.toEpochDay();
        // Long daysDifference = Duration.between(birthDate.atStartOfDay(), LocalDate.now().atStartOfDay()).toDays();
        System.out.format(
                "The total days from your birth until today is: %d\n",
                ChronoUnit.DAYS.between(birthDate, LocalDate.now())
        );
    }
}
