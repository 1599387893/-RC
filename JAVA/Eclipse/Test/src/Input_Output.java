import java.util.Scanner;

public class Input_Output {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		//----------1------------------------------------
		/*
		Scanner sc = new Scanner(System.in);
		System.out.print("����Ҫ��͵����֣�");
		int num = sc.nextInt();
		while(sc.hasNext()) {
			num+=sc.nextInt();
			System.out.print("��ͽ��Ϊ��");
			System.out.println(num);
			num = sc.nextInt();
		}
		*/
		//----------2----------------------------------------
		/*
		Scanner sc = new Scanner(System.in);
		System.out.print("��������͵�������");
		int count = sc.nextInt();
		while(count!=0){
			int ret = 0;
			System.out.print("�������������֣�");
			for(int i = 0;i<2;++i) 
				ret+=sc.nextInt();
			System.out.println("��ͽ��Ϊ:"+ret);
			count--;
		}
		*/
		//----------3----------------------------------------
		/*
		Scanner sc = new Scanner(System.in);
		System.out.print("������Ҫ��͵����ָ�����");
		int count = sc.nextInt();
		while(count!=0) {
			int num = 0;
			while(count!=0) {
				num+=sc.nextInt();
				count--;
			}
			System.out.print("��ͽ��Ϊ��");
			System.out.println(num);
			System.out.print("������Ҫ��͵����ָ�����");
			count = sc.nextInt();
		}
		*/
		//-------------------4----------------------------
		
	}

}
