#include<iostream>
using namespace std;


//CÓïÑÔÄÚ´æÉêÇë
//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int)* 4);
//	for (int i = 0; i < 4; i++)
//	{
//		p2[i] = i;
//	}
//
//	realloc(p2, 5);
//	for (int i = 0; i < 5; i++)
//	{
//		p2[i] = i;
//	}
//	free(p1);
//	free(p2);
//	return 0;
//}

//C++ÄÚ´æÉêÇë
//int main()
//{
//	int* ptr1 = new int;
//	*ptr1 = 1;
//	int* ptr2 = new int[4]{0, 1, 2, 3};
//	//for (int i = 0; i < 4; i++)
//	//{
//	//	ptr2[i] = i;
//	//}
//
//
//	delete ptr1;
//	delete[] ptr2;
//
//	return 0;
//}

class Test
{
public:
	Test() :_t(0)
	{
		cout << "Test()" << this << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int _t;
};

void TestClass()
{
	Test* p1 = new Test;
	delete p1;

	Test* p2 = new Test[4];
	delete[] p2;
}
int main()
{
	TestClass();

	return 0;
}