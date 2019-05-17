#if 0
#include<iostream>
using namespace std;

//多态
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
protected :
	string _name;
	string _gender;
	int _age;
};
class Student :public Person
{
public:
	void BuyTicket()//继承的虚函数也是虚函数
	{
		cout << "半价票" << endl;
	}
};

void SellTicketWnd(Person& p)
{
	p.BuyTicket();

}
int main()
{
	Person p;
	Student s;

	SellTicketWnd(p);
	SellTicketWnd(s);
	system("pause");
	return 0;
}


#include<iostream>
using namespace std;

class A{};

class B :public A{};

class Person
{
public:
	//virtual A* Buy()
	//{
	//	cout << "全价票" << endl;
	//	return nullptr;
	//}
	virtual Person* Buy()
	{
		cout << "quanjia" << endl;
		return this;
	}
protected:
	string _name;
	string _gender;
	int _age;
};

class Student :public Person
{
public:
	//virtual B* Buy()
	//{
	//	cout << "半价票" << endl;
	//	return nullptr;
	//}
	virtual Student* Buy()
	{
		cout << "ban" << endl;
		return this;
	}
};

void Sell(Person& p)
{
	p.Buy();
}
int main()
{
	Person p;
	Student s;

	Sell(p);
	Sell(s);
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

//析构函数的重写 -- 协变
class Person
{
public:
	//virtual A* Buy()
	//{
	//	cout << "全价票" << endl;
	//	return nullptr;
	//}
	virtual Person* Buy()
	{
		cout << "quanjia" << endl;
		return this;
	}
	/*virtual*/ ~Person()
	{
		cout << "Person::~Person()" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};

class Student :public Person
{
public:
	//virtual B* Buy()
	//{
	//	cout << "半价票" << endl;
	//	return nullptr;
	//}
	virtual Student* Buy()
	{
		cout << "ban" << endl;
		return this;
	}
	/*virtual*/ ~Student()
	{
		cout << "Student::~Student()" << endl;
	}
};

int main()
{
	Person* p = new Person;
	p->Buy();
	delete p;

	p = new Student;
	p->Buy();
	delete p;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	static int _count;
};
int Base::_count = 0;
class Derived :public Base
{
};

int main()
{
	Base b;
	b._count = 1;
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<Windows.h>
using namespace std;

class Base
{
public:
	virtual void TetsFunction1(){}
	virtual void TetsFunction2(){}
	virtual void TetsFunction3(){}
	virtual void TetsFunction4(){}
	virtual void TetsFunction5(){}
	virtual void TetsFunction6(){}
	virtual void TetsFunction7(){}
	virtual void TetsFunction8(){}

	int _data;
};

int main()
{
	Base b;
	b._data = 1;
	cout << sizeof(b) << endl;
	system("pause");
	
	return 0;
}

#endif

#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual Base& Test()
	{
		cout << "Base::Test()" << endl;
		return *this;

	}
};

class Derived :public Base
{
public:
	virtual Derived& Test()
	{
		cout << "Dervied::Test()" << endl;
		return *this;
	}
};

void Func(Base* b)
{
	(*b).Test();
}
int main()
{
	Base b;
	Derived d;

	Func(&b);
	Func(&d);

	system("pause");
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;

class A{};

class B :public A{};

class Base
{
public:
	virtual A& Func()
	{
		cout << "Baes::Func()" << endl;
		A a;
		return a;
	}
};

class Derived :public Base
{
public:
	virtual B& Func()
	{
		cout << "Derived::Func()" << endl;
		B b;
		return b;
	}
};

void Test(Base& b)
{
	b.Func();
}

int main()
{
	Base b;
	Derived d;
	Test(b);
	Test(d);

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};
class Derived :public Base
{
public:
	virtual ~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

void Test(Base& b)
{
	b.~Base();
}
int main()
{
	Base* b1 = new Base;
	Base* b2 = new Derived;
	delete b1;
	delete b2;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Person
{
public:
	virtual void Test() = 0;
	int _data;
};

class Student :public Person
{
public:
	virtual void Test()
	{
		cout << "Student()" << endl;
	}
};

int main()
{
	//Person p;
	Student s;

	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Person
{
public:
	virtual void Test1() final
	{} 
	virtual void Test2()override{};
};
class Student:public Person
{
public:
	virtual void Test();
};
class Teach :public Student
{
public :
	virtual void Test();
};

int main()
{

}
#endif

#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Func1(){}
	virtual void Func2(){}
	int _data;
};

class Derived :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derived::Func1()" << endl;
	}
	virtual void Func3(){}
};
int main()
{
	Base b;
	b._data = 1;
	Derived d;
	d._data = 10;
	cout << sizeof(Base) << endl;

	system("pause");
	return 0;
}