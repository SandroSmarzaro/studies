import java.util.Scanner;

import com.san.course.Student;

public class App {
    public static void main(String[] args) {

		// This is comment in one line
		/* This is comment in multiple lines*/
		/**
		* This is document comment */
		System.out.println("\nHello world!\n");

		Student firstStudent = new Student();
		firstStudent.enroll();

		com.san.scholl.Student secondStudent = new com.san.scholl.Student();
		secondStudent.enroll();

		byte int_st= 8; 		// 8 Bits
		short int_nd = 16;
		final int int_rd = 32;	// Final like's const
		long int_4th = 64L;		// L Explicitamente falar que o número é grande

		System.out.println("\nByte = Min: " + Byte.MIN_VALUE + " Max: " + Byte.MAX_VALUE);
		System.out.println("\nShort = Min: " + Short.MIN_VALUE + " Max: " + Short.MAX_VALUE);
		System.out.println("\nInteger = Min: " + Integer.MIN_VALUE + " Max: " + Integer.MAX_VALUE);
		System.out.println("\nLong = Min: " + Long.MIN_VALUE + " Max: " + Long.MAX_VALUE);

		float dec_st = 32.32f;	// f Explicitamente dizendo que é um float de 32 bits
		double dec_nd = 64.64;

		System.out.println("\nFloat = Min: " + Float.MIN_VALUE + " Max: " + Float.MAX_VALUE);
		System.out.println("\nDouble = Min: " + Double.MIN_VALUE + " Max: " + Double.MAX_VALUE);

		char chat_st = 'a';		// Unicode 16 bits
		boolean boo_st = false;

		boo_st = boo_st ^ boo_st;	// Exclusive Or

		int[] array_st;					// Declaração não inicializavél
		int[] array_nd = new int[3];	// Declaração inicializavél
		int[] array_rd = {10, 20, 30};	// Declaração já atribuida

		for (int element : array_rd) {	// For each
			int_st += element;
		}

		byte option;
        Scanner scan = new Scanner(System.in);
        option = scan.nextByte();  
        scan.close();
        System.out.format("Number: %d", option);

		// Thread.sleep(1000);

		// public static void clearScreen() throws IOException, InterruptedException {
		// 	new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
		// }
	}	
}
