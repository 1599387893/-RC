import java.util.Scanner;

public class Input_Output {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		//----------1------------------------------------
		/*
		Scanner sc = new Scanner(System.in);
		System.out.print("输入要求和的数字：");
		int num = sc.nextInt();
		while(sc.hasNext()) {
			num+=sc.nextInt();
			System.out.print("求和结果为：");
			System.out.println(num);
			num = sc.nextInt();
		}
		*/
		//----------2----------------------------------------
		/*
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入求和的组数：");
		int count = sc.nextInt();
		while(count!=0){
			int ret = 0;
			System.out.print("请输入两个数字：");
			for(int i = 0;i<2;++i) 
				ret+=sc.nextInt();
			System.out.println("求和结果为:"+ret);
			count--;
		}
		*/
		//----------3----------------------------------------
		/*
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入要求和的数字个数：");
		int count = sc.nextInt();
		while(count!=0) {
			int num = 0;
			while(count!=0) {
				num+=sc.nextInt();
				count--;
			}
			System.out.print("求和结果为：");
			System.out.println(num);
			System.out.print("请输入要求和的数字个数：");
			count = sc.nextInt();
		}
		*/
		//-------------------4----------------------------
		
	}

}
