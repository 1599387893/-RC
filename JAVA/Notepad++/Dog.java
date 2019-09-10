/*
public class Dog{
	String breed;
	int age;
	String color;
	
	public Dog(String name){
		System.out.println("Dog name : " + name);
	}
	void barking(){}
	void hungry(){}
	void sleeping(){}
	
	public static void main(String []args){
		Dog mydog = new Dog("pipi");
		//System.out.println("Dog");
		mydog.age=12;
		mydog.color="black";
		System.out.println(mydog.age);
		System.out.println(mydog.color);
	}
}
*/

public class Dog{
	int puppyAge;
	public Dog(String name){
		System.out.println("Dog name is :"+name);
	}
	
	public void setAge(int age){
		puppyAge=age;
	}
	
	public int getAge(){
		System.out.println("Dog age is : "+puppyAge);
		return puppyAge;
	}
	public static void main(String[] args){
		Dog p1 = new Dog("tommy");
		p1.setAge(10);
		p1.getAge();
		System.out.println("variable:"+p1.puppyAge);
	}
}


























