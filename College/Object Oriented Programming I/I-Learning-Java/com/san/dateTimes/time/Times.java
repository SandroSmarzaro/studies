package com.san.dateTimes.time;

import java.time.LocalTime;
import java.time.temporal.ChronoUnit;

public class Times {
	public static void Times() {
		LocalTime time = LocalTime.now();
		LocalTime arravialTime = LocalTime.of(13,15);
		LocalTime finishedTime = LocalTime.parse("14:30");

		arravialTime = arravialTime.plusNanos(200000000);
		arravialTime = arravialTime.plusSeconds(1);
		arravialTime = arravialTime.plusMinutes(1);
		arravialTime = arravialTime.plusHours(1);
		arravialTime = arravialTime.plus(500, ChronoUnit.MINUTES);
		finishedTime = finishedTime.minusNanos(200000000);
		finishedTime = finishedTime.minusSeconds(1);
		finishedTime = finishedTime.minusMinutes(1);
		finishedTime = finishedTime.minusHours(1);
		finishedTime = finishedTime.minus(500, ChronoUnit.MINUTES);

		int nano = time.getNano();
		int second = time.getSecond();
		int minute = time.getMinute();
		int hour = time.getHour();
		int secondOfDay = time.toSecondOfDay();

		boolean test;
		test = time.isAfter(arravialTime);
		test = time.isBefore(finishedTime);
	}
}