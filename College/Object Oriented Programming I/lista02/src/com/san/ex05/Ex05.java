package com.san.ex05;

import java.time.DayOfWeek;
import java.time.LocalDate;

public class Ex05 {
    public static void yearWithMoreFriday13() {
        LocalDate dateOfTurn = LocalDate.of(0, 1, 13);
        int biggestYear = dateOfTurn.getYear();
        int biggestCount = 0;
        do {
            int friday13Count = 0;
            int yearTurn = dateOfTurn.getYear();
            do {
                if (dateOfTurn.getDayOfWeek() == DayOfWeek.FRIDAY) friday13Count++;
                dateOfTurn = dateOfTurn.plusMonths(1);
            } while (yearTurn == dateOfTurn.getYear());
            if (friday13Count >= biggestCount) {
                biggestCount = friday13Count;
                biggestYear = dateOfTurn.minusYears(1).getYear();
            }
        } while (dateOfTurn.isBefore(LocalDate.now()));
        System.out.println("Year with more Friday 13: " + biggestYear);
    }
}
