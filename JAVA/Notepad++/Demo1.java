public class Demo1{
	
	//下面是升序的代码
	public void print1(float c){
		float p = c/2;
		float d;
		float e;
		float f;
		float r;
		float s = c % 2;
		if(s == 0){
			System.out.print(" ");
		}
		else{
			for(d=1;d<=p;d++){
				for(f=p;f>=d;f--){
					System.out.print(" ");
				}
				for(e=1;e<=d*2-1;e++){
					if(e == 1 || e == d*2-1){
						System.out.print("*");
					}
					else{
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}
	}
	
	//下面是降序的代码
	public void print2(float m){
		float i;
		float j;
		float k;
		float n = m / 2 + 1;
		float o = m % 2;
		if(o == 0){
			System.out.print(" ");
		}
		else{
			for(i = 1;i<=n;++i){
				for(k = 0;k<i-1;++k){
					System.out.print(" ");
				}
				
				for(j = (n-k)*2-2;j>=1;j--){
					if(i == (n-k)*2-2 || j == 1){
						System.out.print("*");
					}
					else{
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}
	}
	
	public static void main(String[] args){
		Demo1 a = new Demo1();
		float b = 11;
		a.print1(b);
		a.print2(b);
	
	}
}