//方法重写与变量覆盖

class SuperCla{
	int a = 3;
	int b = 4;
	void show(){
		System.out.println("super result = "+(a+b));
	}
}
class SubCla extends SuperCla{
	int a = 10;
	void show(){
		int c = super.a*b;
		System.out.println("sub result = "+c);
	}
}

class Coverage{
	public static void main(String[] args){
		SuperCla sp = new SuperCla();
		SubCla sb = new SubCla();
		
		sp.show();
		System.out.println("In super class : a = "+sp.a);
		sb.show();
		System.out.println("In sub Class : a = "+sb.a);
	}
}