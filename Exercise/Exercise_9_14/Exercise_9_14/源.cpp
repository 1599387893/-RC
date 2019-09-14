#include<iostream>
using namespace std;

#if 0
class Person
{
public:
	Person(){ ++_count; }
protected:
	string _name;
public:
	static int _count;
};
int Person::_count = 0;

class Student:public Person
{
protected:
	int _stuNum;
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
	cout << "����Ϊ��" << Person::_count << endl;
	Student::_count = 0;
	cout << "����Ϊ��" << Person::_count << endl;
}
#endif

#if 0
//���μ̳�
//������μ̳е���������Ͷ���������ķ���--����̳�
class Person
{
public:
	string _name;
};
class Student :virtual public Person
{
protected:
	int _num;
};
class Teacher :virtual public Person
{
protected:
	int _id;
};
class Assistant :public Student, public Teacher
{
protected:
	string _majorCourse;
};
void Test()
{
	Assistant a;
	a._name = "RC";
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
	//cout << "Person::" << a.Person::_name << endl;
	//cout << "Student::" << a.Student::_name << endl;
	//cout << "Teacher::" << a.Student::_name << endl;
}
#endif

class A{};
class B :public A{};

class Person
{
public:
	virtual A* BuyTicket(){ cout << "��Ʊ--ȫ��" << endl; return new A; }
};
class Student :public Person
{
public:
	virtual B* BuyTicket(){ cout << "��Ʊ--���" << endl; return new B; }
};
void Func(Person& p)
{
	p.BuyTicket();
}
void TestDT()
{
	Person p;
	Student s;
	Func(p);
	Func(s);
}
int main()
{
	//TestPerson();
	//Test();
	TestDT();
	system("pause");
	return 0;
}