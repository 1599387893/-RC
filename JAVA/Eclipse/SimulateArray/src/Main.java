
public class Main {
	public static void main(String[] args) {
		Array<Integer> arr = new Array<>(20);
		
		//arr.PrintArray();
		//System.out.println(arr);
		
		for(int i = 0;i<10;++i)
			arr.addLast(i);
		System.out.println(arr);
		//arr.add(0,0);
		//arr.add(1,1);
		//arr.add(2,2);
		//arr.add(3,3);
		//arr.add(4, 4);
		
		arr.add(1,100);
		System.out.println(arr);
		
		arr.addFrist(-1);
		System.out.println(arr);
		
		arr.remove(2);
		System.out.println(arr);
		
		arr.removeElement(4);
		System.out.println(arr);
		
		arr.removeFrist();
		System.out.println(arr);
		
		
		//arr.addLast(4);
		//arr.addFrist(0);
		//for(int i = 0;i<arr.getSize();++i)
		//System.out.println("3号位置上的元素为："+arr.Get(3));
		//System.out.println("该数组中是否有3这个元素？" + arr.contains(3));
		
		//System.out.println(arr);
	}
}
