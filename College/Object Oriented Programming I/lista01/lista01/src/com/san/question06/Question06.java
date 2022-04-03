package com.san.question06;

import java.util.Scanner;

public class Question06 {
    public void studentsAverage() {
        final byte MAX_STUDENTS = 5;
        final byte GRADE_WEIGHT = 2;
        final byte MAX_GRADE = 10;
        final byte MIN_GRADE = 0;
        Scanner scanner = new Scanner(System.in);
        
        for (byte studentNumber = 1; studentNumber <= MAX_STUDENTS; studentNumber++) {
            float sum = 0;
            float average = 0;
            float firstGrade = 0;
            float secondGrade = 0;
            System.out.format("\nEnter the first grade of %dº student: \n", studentNumber);
            do {
                firstGrade = scanner.nextFloat();
            } while (firstGrade < MIN_GRADE || firstGrade > MAX_GRADE);
            System.out.format("\nEnter the second grade of %dº student: \n", studentNumber);
            do {
                secondGrade = scanner.nextFloat();
            } while (secondGrade < MIN_GRADE || secondGrade > MAX_GRADE);
            sum = firstGrade + secondGrade;
            average = sum / (float) GRADE_WEIGHT;
            System.out.format("\nThe average of %dº student is: %.2f\n", studentNumber, average);
        }
        scanner.close();
    }
}
