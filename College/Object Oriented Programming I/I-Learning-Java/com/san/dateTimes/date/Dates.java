package com.san.dateTimes.date;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Month;
import java.time.temporal.ChronoUnit;

public class Dates {
	public static void dates() {
		LocalDate date = LocalDate.now();
		LocalDate natal = LocalDate.of(2020, 12, 25);
		LocalDate birthday = LocalDate.parse("2020-03-27");
		natal = natal.plusDays(30);
		natal = natal.plusWeeks(5);
		natal = natal.plusMonths(1);
		natal = natal.plusYears(1);
		natal = natal.plus(1, ChronoUnit.DAYS);

		birthday = birthday.minusDays(5);
		birthday = birthday.minusWeeks(2);
		birthday = birthday.minusMonths(1);
		birthday = birthday.minusYears(1);
		birthday = birthday.minus(1, ChronoUnit.WEEKS);

		DayOfWeek dayOfWeek = date.getDayOfWeek();
		int dayOfMouth = date.getDayOfMonth();
		Month month = date.getMonth();
		int monthValue = date.getMonthValue();
		int year = date.getYear();
		int dayOfYear = date.getDayOfYear();

		boolean test;
		test = date.isAfter(birthday);
		test = date.isBefore(birthday);
		test = date.isEqual(birthday);
		test = date.isLeapYear();
		int compareDays = date.compareTo(birthday);
	}
}