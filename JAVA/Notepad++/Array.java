public class Array{
	public static void main(String[] args){
		
		int size = 10;
		double[] mylist = new double[size];
		mylist[0] = 5.6;
		mylist[1] = 4.5;
		mylist[2] = 3.3;
		mylist[3] = 13.2;
		mylist[4] = 4.0;
		mylist[5] = 34.33;
		mylist[6] = 34.0;
		mylist[7] = 45.45;
		mylist[8] = 99.993;
		mylist[9] = 11123;
		
		double total = 0;
		for(int i = 0;i<size;++i){
			total += mylist[i];
		}
		System.out.println("总和为："+total);
	}
}