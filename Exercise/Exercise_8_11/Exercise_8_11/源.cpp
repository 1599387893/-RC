#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;

#if 0
int main()
{
#if 0
	double **a[3][4];
	cout << sizeof(a) << endl;


	char acHello[] = "hello\0world";
	char acNew[15] = { 0 };
	strcpy(acNew, acHello);
	cout << strlen(acNew) << "   " << sizeof(acHello) << endl;

	char a[20];
	char* p1 = (char*)a;
	char* p2 = (char*)(a + 5);
	int n = p2 - p1;
	cout << n << endl;

	int x;
	cout << (x=5>1+2&&2||2*4<4-!0) << endl;
#endif


	system("pause");
	return 0;
}
#endif

//#pragma pack(4)

int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}
void GlobalInit(unsigned int arg)
{
	arg = 0x01;
	return;
}
unsigned int g_global = 0;
int main()
{
#if 0
	struct tagtest1
	{
		short a;
		char d;
		long b;
		long c;
	};
	struct tagtest2
	{
		long b;
		long c;
		char d;
		short a;
	};
	struct tagtest3
	{
		long c;long b;
		char d;short a;
	};
	struct tagtest1 t1;
	struct tagtest2 t2;
	struct tagtest3 t3;

	cout << sizeof(t1) << endl;
	cout << sizeof(t2) << endl;
	cout << sizeof(t3) << endl;

	cout << fun(2019) << endl;

#endif

	GlobalInit(g_global);
	cout << g_global << endl;
	system("pause");
	return 0;
}
#pragma pack()