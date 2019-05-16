////#include<iostream>
////using namespace std;
////
////class Base
////{
////public:
////	void Test()
////	{
////		cout << "Base::Test()" << endl;
////	}
////};
////
////class  Derived :public Base
////{
////public:
////	void Test()
////	{
////		cout << "Derived::Test()" << endl;
////	}
////};
////
////int main()
////{
////	Derived d;
////	d.Test();
////
////	d.Base::Test();
////
////	return 0;
////}
//
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name)
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
//		cout << "Person& operator=(const Person&)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
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
//	Student(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)
//		, _id(s._id)
//	{
//		cout << "Student(const Student&)" << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _id;
//};
//
//void Test()
//{
//	Student s1("RC", 1);
//	Student s2(s1);
//	Student s3("RRCC",10);
//
//	s1 = s3;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//
//	return 0;
//}

//#include<iostream>
//using namespace std;

//class Base
//{
//public:
//	friend void Test();
//};
//
//class Derived :public Base
//{
//};
//
//void Test()
//{
//	cout << "Test" << endl;
//}
//int main()
//{
//	Derived d;
//	d.Test();
//}
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//编译不能通过
//	cout << s._stuNum << endl;//编译不能通过
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(){ ++_count; };
//protected:
//	string _name;
//public:
//	static int _count;
//};
//int Person::_count = 0;
//
//class Student :public Person
//{
//protected:
//	int _stuNum;
//};
//
//class Graduate :public Student
//{
//protected:
//	string _seminarCourse;
//};
//
//void Test()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate g1;
//	Person p1;
//	cout << "人数：" << Person::_count << endl;
//	Person::_count = 0;
//	cout << "人数：" << Person::_count << endl;
//
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

bool Find(int* matrix, int rows, int colums, int number)
{
	bool found = false;

	if (matrix != nullptr&& rows > 0 && colums > 0)
	{
		int row = 0;
		int column = colums - 1;
		while (row < rows && colums >= 0)
		{
			if (matrix[row * colums + colums] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * colums + colums] > number)
				--colums;
			else
				++row;
		}
	}
	return found;
}

int main()
{
	int array[16] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	cout << Find(array, 4, 4, 1)<<endl;
	system("pause");
	return 0;
}