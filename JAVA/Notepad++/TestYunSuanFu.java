class Vehicle{}

public class TestYunSuanFu extends Vehicle{
	
	public static void main(String[] args){
		
		Vehicle aa = new TestYunSuanFu();
		boolean result = aa instanceof TestYunSuanFu;
		System.out.println(result);
		
		
		int a=10;
		int b=20;
		int c=25;
		int d=25;
		System.out.println("a + b = "+(a+b));
		System.out.println("a - b = "+(a-b));
		System.out.println("a * b = "+(a*b));
		System.out.println("b / a = "+(b/a));
		System.out.println("b % a = "+(b%a));
		System.out.println("c % a = "+(c%a));
		System.out.println("a++ = "+(a++));
		System.out.println("a-- = "+(a--));
		
		System.out.println("d++ = "+(d++));
		System.out.println("++d = "+(++d));
		
		int a1=10;
		int b1=20;
		System.out.println("a==b = "+(a==b));
		System.out.println("a!=b = "+(a!=b));
		System.out.println("a>b = "+(a>b));
		System.out.println("a<b = "+(a<b));
		System.out.println("a>=b = "+(a>=b));
		System.out.println("a<=b = "+(a<=b));
		
		b=(a==1) ? 20 : 30;
		System.out.println("Value of b is :" + b);

		b=(a==10) ? 20 : 30;
		System.out.println("Value of b is : " + b);
	}
}