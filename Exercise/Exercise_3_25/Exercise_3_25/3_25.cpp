#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
using namespace std;

//struct student
//{
//	void InitStudent(char* name, int age, char* gender)
//	{
//		strcpy(_name, name);
//		_age = age;
//		strcpy(_gender, gender);
//	}
//
//	void PrintStudent()
//	{
//		cout << _name << "-" << _age << "-" << _gender << endl;
//	}
//	char _name[20];
//	int _age;
//	char _gender[3];
//};
//
//int main()
//{
//	student s1, s2, s3;
//	s1.InitStudent("zhangsan", 10, "ÄÐ");
//	s2.InitStudent("lisi", 20, "Å®");
//	s3.InitStudent("wangwu", 30, "nan");
//	
//	s1.PrintStudent();
//	s2.PrintStudent();
//	s3.PrintStudent();
//
//	return 0;
//}

//class student
//{
//public:
//
//	void InitStudent(char* name, int age, char* gender)
//	{
//		strcpy(_name, name);
//		_age = age;
//		strcpy(_gender, gender);
//	}
//
//	void PrintStudent()
//	{
//		cout << _name << "-" << _age << "-" << _gender << endl;
//	}
//private:
//
//	char _name[20];
//	int _age;
//	char _gender[3];
//};
//
//int main()
//{
//	student s1, s2, s3;
//	s1.InitStudent("zhangsan", 10, "ÄÐ");
//	s2.InitStudent("lisi", 20, "Å®");
//	s3.InitStudent("wangwu", 30, "ÄÐ");
//
//	s1.PrintStudent();
//	s2.PrintStudent();
//	s3.PrintStudent();
//	cout << sizeof(s1) << endl;
//
//
//	return 0;
//}

//#pragma pack(1)
//class A
//{
//public:
//	void TestFun()
//	{}
//	A(int a, char b) :_a(a), _b(b){}
//    
//	int _a;
//	char _b;
//};
//
//class B
//{
//public:
//	void TestFun(){}
//};
//class C
//{
//};
//
//int main()
//{
//	A a(1,'c');
//	//C c1, c2, c3;
//	cout << sizeof(a) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	
//	cout << offsetof(A, _b) << endl;
//	return 0;
//}

//class Student
//{
//public:
//	Student(char* name, int age, char* gender):_age(age)
//	{
//		strcpy(_name, name);
//		//_age = age;
//		strcpy(_gender, gender);
//	}
//	void PrintStudnet()
//	{
//		cout << _name << "-" << _age << "-" << _gender << endl;
//	}
//private:
//	char _name[20]  ;
//	int _age = 10;
//	char _gender[3] ;
//};
//
//int main()
//{
//	Student s1("peter",20,"nan");
//	s1.PrintStudnet();
//
//	/*Student s2("jingjing", 36, "Å®");
//	s2.PrintStudnet();*/
//	return 0;
//}

struct Student
{
public:

	char _name[20];
	int _age;
	char _gender[3];
};

void InitStudent(Student* this, char* name, int age, char* gender)
{
	strcpy(this->_name, name);
	this->_age = age;
	strcpy(this->_gender, gender);
}

int main()
{
	return 0;
}