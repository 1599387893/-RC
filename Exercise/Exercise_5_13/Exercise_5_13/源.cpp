//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	//Person(string name, int age)
//	//	:_name(name)
//	//	, _age(age)
//	//{
//	//	cout << "Person(string,int)" << endl;
//	//}
//	void Print()
//	{
//		cout << "name" << _name << endl;
//		cout << "age" << _age << endl;
//	}
//protected:
//	string _name = "RC";
//	int _age = 20;
//};
//
//class Student:public Person
//{
////public:
////	Student(string name, int age, int stuid)
////		:Person(name, age)
////		, _stuid(stuid)
////	{
////		cout << "Student(string,int,int)" << endl;
////	}
////	void StuPrint()
////	{
////		Print();
////		cout << "stuid" << _stuid << endl;
////
////	}
////private:
////	int _stuid;
//};
//
//class Teach :public Person
//{
////public:
////	Teach(string name, int age, int id)
////		:Person(name, age)
////		, _jobid(id)
////	{
////		cout << "Teach(string,int,int)" << endl;
////	}
////	void TeaPrint()
////	{
////		Print();
////		cout << "jobid" << _jobid << endl;
////	}
////private:
////	int _jobid;
//};
//
//int main()
//{
//	//Person p("RC",15);
//	//Student s("RC", 20, 45);
//	//Teach t("RJP", 46, 1);
//
//	//p.Print();
//	//s.StuPrint();
//	//t.TeaPrint();
//	Person p ;
//	Student s;
//	Teach t;
//	p.Print();
//	s.Print();
//	t.Print();
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name;
//private:
//	int _age;
//};
//
////class Student :public Person
////class Student :protected Person
//class Student :private Person 
//{
//public:
//	void StuPrint()
//	{
//		cout << _name << endl;
//	}
//protected:
//	int _stuid;
//};
//class StudentLittle :public Student
//{
//public:
//	void LiPrint()
//	{
//		//cout << _name << endl;
//	}
//};
//int main()
//{
//	Student s;
//	//s.Print();
//	s.StuPrint();
//	//s._name;
//	//s._age;
//	StudentLittle l;
//	l.LiPrint();
//	//l.Print();
//	l.StuPrint();
//
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "Person::Print()" << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	void StuPrint()
//	{
//		cout << "Student::Print()" << endl;
//	}
//protected:
//	int _stuid;
//};
//
//int main()
//{
//	Student s;
//	Person p = s;
//	Person* pp = &s;
//	Person& rp = s;
//
//	//s = p;
//	pp = &s;
//	Student* s1 = (Student*)pp;
//
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
////隐藏/重定义
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "Person()" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "Studen()" << endl;
//	}
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	s.Person::Print();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(string name)
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person&)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "operator=()" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Student :public Person
//{
//public:
//	Student(string name, int num)
//		:Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		:Person(s._name)
//		, _num(s._num)
//	{
//		cout << "Student(const Student&)" << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		cout << "Student operator=()" << endl;
//		if (this != &s)
//		{
//			_name = s._name;
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//private:
//
//	int _num;
//};
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}
//int main()
//{
//	Test();
//
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;

//友元和静态成员

//class Student;
//
//class Person
//{
//public:
//	friend void Display(const Person& p,const Student& s);
//private:
//	string _name;
//};
//
//class Student :public Person
//{
//private:
//	int _num;
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//cout << s._num << endl;
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//
//	return 0;
//}

class Person
{
public:
	Person(){ ++_count; }
protected:
	string _name;
public:
	static int _count;
};
int Person::_count = 1;

class Student :public Person
{
protected:
	int _num;
};
class Graduate :public Student
{
protected:
	string _seminarCourse;
};

void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "人数" << Person::_count << endl;
	Student::_count = 0;
	cout << "人数" << Person::_count << endl;

}
int main()
{
	TestPerson();

	return 0;
}