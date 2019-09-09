package TestScanner2;

import java.util.*;

public class sc {
	public static void main(String[] args) {
		/*
		Scanner sc = new Scanner(System.in);
		
		System.out.println("please enter a number : ");
		int num1 = sc.nextInt();
		System.out.println("Please enter a number : ");
		double num2 = sc.nextDouble();
		
		System.out.println("-----------------------------------------");
		System.out.println(num1 + "*" + num2 + "=" +(num1*num2));
		*/
		
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			System.out.println(""+sc.hasNextInt());
			System.out.println(""+sc.next());
		}
		sc.close();
		
	}
	
}
