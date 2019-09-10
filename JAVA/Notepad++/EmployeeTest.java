import java.io.*;
public class EmployeeTest{

	public static void main(String[] args){
		Employee one = new Employee("RUNOOB1");
		Employee two = new Employee("RUNOOB2");
		
		one.empAge(26);
		one.empDesignation("high IT man");
		one.empSalary(1000);
		one.printEmployee();
		
		two.empAge(21);
		two.empDesignation("low IT man");
		two.empSalary(500);
		two.printEmployee();
		
		String s="i am RC\n are you";
		System.out.println(s);
	}
}