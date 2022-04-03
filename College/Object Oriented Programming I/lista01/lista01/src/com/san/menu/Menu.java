package com.san.menu;

import com.san.question01.*;
import com.san.question02.Question02;
import com.san.question03.Question03;
import com.san.question04.Question04;
import com.san.question05.Question05;
import com.san.question06.Question06;
import com.san.question07.Question07;
import com.san.question08.Question08;

public class Menu {
    public void question(byte questionNumber) {
        switch (questionNumber) {
            case 0:
                System.out.println("\n\nExiting of list...");
                break;
            
            case 1:
                Question01 question01 = new Question01();
                question01.getArea();
                break;

            case 2:
                Question02 question02 = new Question02();
                question02.calculator();
                break;

            case 3:
                Question03 question03 = new Question03();
                question03.primeNumber();
                break;

            case 4:
                Question04 question04 = new Question04();
                question04.crossProduct();
                break;
            
            case 5:
                Question05 question05 = new Question05();
                question05.fiveAnalysis();
                break;

            case 6:
                Question06 question06 = new Question06();
                question06.studentsAverage();
                break; 

            case 7:
                Question07 question07 = new Question07();
                question07.euclideanDistance();
                break;

            case 8:
                Question08 question08 = new Question08();
                question08.inclination();
                break;
            default:
                break;
        }
    }
}
