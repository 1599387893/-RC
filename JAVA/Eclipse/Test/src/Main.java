import java.util.*;
import java.text.*;
 
public class Main {
	public static void main(String[] args) {
		DecimalFormat f = new DecimalFormat("#.00#");
		DecimalFormat g = new DecimalFormat("0.000");
		// �����0ָһλ���֣�#ָ��0���������
		double a = 123.456789, b = 0.123456;
		System.out.println(f.format(a));
		System.out.println(f.format(b));
		System.out.println(g.format(a));
		System.out.println(g.format(b));
	}
}