import java.util.*;
import java.text.*;

public class DecimalFormat {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		/*
		DecimalFormat df1 = new DecimalFormat("#.00#");
		DecimalFormat df2 = new DecimalFormat("0.000");
		
		double d1 = 12.345678, d2 = 0.123456;
		System.out.println(df1.format(a));
		System.out.println(df1.format(b));
		System.out.println(df2.format(a));
		System.out.println(df2.format(b));
		*/
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
