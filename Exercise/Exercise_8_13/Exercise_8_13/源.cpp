#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
#if 0
	string s;
	cin >> s;
	int i;
	for (i = 0; i < s.size()-1; ++i)
	{
		if (s.find(s[i],i+1)==-1)
		{
			cout << s[i] << endl;
			break;
		}
	}
	if (i == s.size() - 1)
		cout << "not find!" << endl;
#endif

	int a[5] = { 0 };
	int b[5] = { 1 };

	system("pause");
	return 0;
}
#endif


#if 1
#include<stdio.h>
#include<string.h>
#include<Windows.h>
void Func(char str_arg[])
{
	int m = sizeof(str_arg);
	int n = strlen(str_arg);
	printf("%d\n",m);
	printf("%d\n",n);
}
union X
{
	int x;
	char y[4];
}a;

char* myString()
{
	char buffer[6] = { 0 };
	char* s = "Hello world!";
	for (int i = 0; i < sizeof(buffer) - 1; ++i)
		buffer[i] = *(s + i);
	return buffer;
}

int main()
{
#if 0
	char str[] = "Hello";
	Func(str);

	printf("%d\n",1<<3+2);
	
	a.x = 0x11223344;
	printf("%x\n", a.y[0]);
	printf("%x\n", a.y[1]);
	printf("%x\n", a.y[2]);
	printf("%x\n", a.y[3]);

	int a[5] = { 1, 2, 3, 4, 5 };
	int* p1 = (int*)(&a + 1);
	int* p2 = (int*)((int)a + 1);
	int* p3 = (int*)(a + 1);
	printf("%d %x %d\n",p1[-1],p2[0],p3[1]);

	char acX[] = "abc";
	char acY[] = {'a','b','c'};
	char* szX = "abc";
	char* szY = "abc";

	printf("&acX = %p\n&acY = %p\n&szX = %p\n&szY = %p\n",acX,acY,szX,szY);

	//printf("%s\n",myString());
	//int i = 1;
	//printf("%d,%d\n",i,sizeof(i++));
	
	char a[1000];
	int i;
	for (i = 0; i < 1000; ++i)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n",strlen(a));
#endif

	//unsigned char a = 0xA5;
	//unsigned char b = ~a >> 4 + 1;
	//printf("%d\n",b);

	const int i = 0;
	int* j = (int*)&i;
	*j = 1;
	printf("%d %d\n",i,*j);

	system("pause");
	return 0;
}
#endif