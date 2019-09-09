package DataTypes;

import java.io.*;

class Marks{
	int engMarks;
	int mathMarks;
	int phyMarks;
}
public class DateTypes {
	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4,5,6,7,8,9};
		String arrStr[] = {"ab","cd","ef","gh","ij"};
		
		for(int x:arr) {
			System.out.print(x+" ");
		}
		
		for(String s:arrStr) {
			System.out.println(s);
		}
		
		System.out.println(Min(arr));
		/*
		Marks obj1 = new Marks();
		obj1.engMarks = 50;
		obj1.mathMarks = 80;
		obj1.phyMarks = 90;
		
		System.out.println(obj1.engMarks);
		System.out.println(obj1.mathMarks);
		System.out.println(obj1.phyMarks);
		*/
		
		/*byte b1 = 100;
		short s1 = 5000;
		long l1 = 150000000L;
		float f1 = 5.75f;
		double d1 = 19.99d;
		boolean boo1 = true;
		boolean boo2 = false;
		char c1 = 'a';
		char c2 = 65;
		char c3 = 66;
		char c4 = 67;
		String s2 = "Hello RC";
		
		System.out.println(b1);
		System.out.println(s1);
		System.out.println(l1);
		System.out.println(f1);
		System.out.println(d1);
		System.out.println(boo1);
		System.out.println(boo2);
		System.out.println(c1);
		System.out.println(c2);
		System.out.println(c3);
		System.out.println(c4);
		System.out.println(s2);
		*/	
	}
	public static int Min(int[] arr) {
		int ret = arr[0];
		for(int x:arr)
			if(x < ret)
				ret = x;
		return ret;
	}
}
