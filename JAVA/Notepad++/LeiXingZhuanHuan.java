public class LeiXingZhuanHuan{
	public static void main(String[] args){
		char c1='a';
		int  i1=c1;
		System.out.println("char自动类型转换为int后的值为："+i1);
		
		char c2='A';
		int i2=c2+1;
		System.out.println("char类型和int计算后的值为："+i2);
		
		int i3=123;
		byte b=(byte)i3;
		System.out.println("int强制类型转换为byte后的值为："+b);
		
		long g = (long)9223372036854775807L;
		long h = (long)-9223372036854775808L;
	}
}