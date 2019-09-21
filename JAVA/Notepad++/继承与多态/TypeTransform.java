//对象间的类型转换

class A{
	String s=  "class A";
}
class B extends A{
	String s=  "class B";
}
class TypeTransform{
	public static void main(String[] args){
		B bb,b = new B();
		A a,aa;
		
		//子类转父类--显式或隐式
		a = (A)b;
		aa = b;
		System.out.println(a.s);
		System.out.println(aa.s);
		
		//父类转子类--显式
		bb = (B)a;
		System.out.println(bb.s);
	}
}
