import java.io.*;

public class Employee{
	String name;
	int age;
	String designation;
	double salary;
	
	public Employee(String name){
		this.name = name;
	}
	public void empAge(int empAge){
		age = empAge;
	}
	public void empDesignation(String  empDesig){
		designation = empDesig;
	}
	public void empSalary(double empSalary){
		salary = empSalary;
	}
	
	public void printEmployee(){
		System.out.println("name(姓名) : "+name);
		System.out.println("Age(年龄) : "+age);
		System.out.println("designation(职位) : "+designation);
		System.out.println("salary(薪资) : "+salary);
	}
}