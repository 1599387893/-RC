#if 0
#include<iostream>
#include<string>
using namespace std;
/*
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
private:
	string _name = "RC";
	int _age = 18;
};

class Student:public Person
{
protected:
	int _stuid;
};

class Teacher :public  Person
{
protected:
	int _jobid;
};

void Test1()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
}
*/

class Person
{
protected:
	string _name = "RC";
	string _sex = "man";
	int _age = 20;
	int _num = 111;
};
class Student :public Person
{
public:
	void Print()
	{
		cout << "name : " << _name << endl;
		cout << "sex : " << _sex << endl;
		cout << "age : " << _age << endl;
		cout << "_num : " << _num << endl;
	}
public :
	int _num = 999;
};
void Test2()
{/*
	Student s;
	Person p = s;
	Person* pptr = &s;
	Person& rp = s;

	//s = p;
	pptr = &s;
	Student* ps1 = (Student*)pptr;
	ps1->_no = 10;

	pptr = &p;
	Student* ps2 = (Student*)pptr;
	ps2->_no = 20;
	*/
}
void Test3()
{
	Student s;
	s.Print();
}

class A
{
public :
	void fun()
	{
		cout << "A::fun()" << endl;
	}
};
class  B:public A
{
public:
	void fun(int a)
	{
		cout << "B::fun()" << endl;
	}
};
void Test4()
{
	A a;
	B b;
	a.fun();
	b.fun(1);
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();

	system("pause");
	return 0;
}
#endif