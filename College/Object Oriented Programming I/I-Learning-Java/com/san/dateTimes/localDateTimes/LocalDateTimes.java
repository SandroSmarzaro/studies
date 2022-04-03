package com.san.dateTimes.localDateTimes;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class LocalDateTimes {
	public static void localDateTimess() {
		LocalDateTime now = LocalDateTime.now();
		LocalDateTime birth = LocalDateTime.of(2001, 3, 27, 19, 57);
		LocalDateTime twinBirth = LocalDateTime.parse("2001-03-27T19:56");

		int dayOfMounth = birth.getDayOfMonth();
		now = now.plusDays(5);
		now = now.minusMinutes(30);
		boolean isBisext = twinBirth.toLocalDate().isLeapYear();
		int secondOfDay = twinBirth.toLocalTime().toSecondOfDay();

		DateTimeFormatter firstFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd E HH:mm:ss");
		DateTimeFormatter secondFormatter = DateTimeFormatter.ofPattern("EEEE, dd 'de' MMMM 'de' yyyy, 'às' HH:mm");
		String formatted = birth.format(secondFormatter);
		System.out.println(formatted);
	}
}