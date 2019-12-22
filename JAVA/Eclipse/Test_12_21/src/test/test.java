package test;

import java.math.BigDecimal;
import java.util.Scanner;

public class test {
	public static void main(String[] args) {
		/*int a1 = 10;
		Integer a2 = a1;
		String s1 = new String() ;
		s1.valueOf(4);
		String s2 = a2.toString();
		System.out.println(s1.valueOf(a1));
		System.out.println(s2);
		*/
		/*
		Character ch = new Character('a');
		System.out.println("ch" + ch);
		System.out.println("isUpperCase:"+Character.isUpperCase(ch));
		System.out.println("toUpperCase:"+Character.toUpperCase(ch));
		System.out.println("isLowerCase:"+Character.isLowerCase('A'));
		System.out.println("toLowerCase:"+Character.toLowerCase('A'));
		System.out.println("isDigit:" + Character.isDigit('0'));
		*/
		
		/*
		int big = 0;
		int small = 0;
		int number = 0;
		Scanner scan = new Scanner(System.in);
		System.out.println("Please Enter A String:");
		String line = scan.nextLine();
		char [] chs = line.toCharArray();
		
		for(int x = 0; x < chs.length;++x) {
			if(Character.isUpperCase(chs[x]))
				big++;
			else if(Character.isLowerCase(chs[x]))
				small++;
			else if(Character.isDigit(chs[x]))
				number++;
		}
		System.out.println("´óÐ´×ÖÄ¸£º"+big);
		System.out.println("Ð¡Ð´×ÖÄ¸£º"+small);
		System.out.println("Êý×Ö£º"+number);
		*/
		
		/*
		float a1 = 0.09f;
		float a2 = 0.01f;
		System.out.println(a1+a2);
		System.out.println(0.09f+0.01f);
		BigDecimal bd1 = new BigDecimal("0.09");
		BigDecimal bd2 = new BigDecimal("0.01");
		BigDecimal bd3 = new BigDecimal("1.0");
		BigDecimal bd4 = new BigDecimal("0.32");
		BigDecimal bd5 = new BigDecimal("1.015");
		BigDecimal bd6 = new BigDecimal("100");
		System.out.println("Add:"+bd1.add(bd2));
		System.out.println("Subtract:"+bd3.subtract(bd4));
		System.out.println("multiply:"+bd5.multiply(bd6));
		*/
		
		double a = 12.86;
		int b = (int)a;
		System.out.println(b);
		long c = Math.round(a);
		System.out.println(c);
		double d = Math.floor(a);
		System.out.println(d);
		double e = Math.ceil(a);
		System.out.println(e);
		
		
		
		return;
	}
}
