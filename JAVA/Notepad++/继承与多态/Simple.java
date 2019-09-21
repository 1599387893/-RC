//继承的实现

class A{
	int i;
	void showi(){
		System.out.println("i:"+i);
	}
}

class B extends A{
	int k;
	void show()
	{
		showi();
		//super.showi();
		System.out.println("k:"+k);
	}
	void sum(){
		System.out.println("sum:"+(i+k));
	}
}

class Simple{
	public static void main(String[] args){
		A superObj = new A();
		B subObj = new B();
		superObj.i = 10;
		System.out.println("Contents in 父类: ");
		superObj.showi();
		
		subObj.i = 7;
		subObj.k = 9;
		System.out.println("Contents in 子类：");
		subObj.show();
		System.out.println("Sum of i and k in 子类: ");
		subObj.sum();
	}
}
