#include<iostream>
using namespace std;

class Person
{
protected:
	string _name;
	string _sex;
	int _age;
};

class Student :public Person
{
public:
	int _id;
};


void Test()
{
	Person* pptr;//基类对象
	Student s;//派生类对象

	pptr = &s;
	Student* ps = (Student*)pptr;
	ps->_id = 1;
}
//void Test()
//{
//	Person p;//基类对象
//
//	Student s = p;
//}
//void Test()
//{
//	Student s;//派生类对象
//
//	Person p = s;//派生类对象可以赋值给基类对象
//
//	Person* pptr = &s;//派生类对象可以赋值给基类指针
//
//	Person& pref = s;//派生类对象可以赋值给基类引用
//}

int main()
{
	Test();

	return 0;
}