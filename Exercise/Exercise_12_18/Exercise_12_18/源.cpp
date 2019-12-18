#include<iostream>
using namespace std;

int main()
{
#if 0
	struct { int a; double b; } x;
	struct { int a; double b; } *p;
	//p = &x;

#pragma pack(8)
	struct Node
	{
		int date;
		struct Node* next;
	}a;
	cout << sizeof(a) << endl;
#pragma pack()
#endif

	struct A
	{
		int a : 2;
		int b : 5;
		int c : 10;
		int d : 30;
	}a;
	cout << sizeof(a) << endl;
	system("pause");
	return 0;
}
