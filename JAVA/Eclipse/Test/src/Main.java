import java.util.*;
import java.text.*;
 
public class Main {
	public static void main(String[] args) {
		DecimalFormat f = new DecimalFormat("#.00#");
		DecimalFormat g = new DecimalFormat("0.000");
		// 这里的0指一位数字，#指除0以外的数字
		double a = 123.456789, b = 0.123456;
		System.out.println(f.format(a));
		System.out.println(f.format(b));
		System.out.println(g.format(a));
		System.out.println(g.format(b));
	}
}