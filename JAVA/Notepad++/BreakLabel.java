class BreakLabel{
	public static void main(String[] args){
		boolean t = true;
		first:{
			second:{
				third:{
					System.out.println("Before the break");
					if(t)
						break first;
					System.out.println("this is third block.");
				}
				System.out.println("this is second block.");
			}
			System.out.println("this is first block.");
		}
		System.out.println("this is main block.");
	}
}