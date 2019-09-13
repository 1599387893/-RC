#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;
};
class Student:public Person
{
public:
	Student(const char* name="RC" ,int num = 01)
		:Person(name)
		, _num(num)
	{
		cout << "Student(const char*,n=int)" << endl;
	}
	Student(const Student& s)
	{
		cout << "Student(const Student&)" << endl;
		_name = s._name;
		_num = s._num;
	}
	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			_name = s._name;
			_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num;
};

void Test()
{
	Student s1("Jack", 18);
	Student s2(s1);
	Student s3("Rose",17);
	s1 = s3;

}
int main()
{
	Test();
	system("pause");
	return 0;
}