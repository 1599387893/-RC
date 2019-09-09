import java.sql.Date;

public class Print {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		
		System.out.println("        *");
		System.out.println("       **");
		System.out.println("      ***");
		System.out.println("     ****");
		System.out.println("    *****");
		System.out.println("   ******");
		System.out.println("  *******");
		System.out.println(" ********");
		
		System.out.println(200+432);
		
		//printDate
		Date d = new Date();
		String str = d.toLocaleString();
		System.out.println("当前日期 ："+str);
		
		
	}

}
