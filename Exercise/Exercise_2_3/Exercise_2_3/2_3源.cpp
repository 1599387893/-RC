#include<iostream>
#include<assert.h>
using namespace std;

////值传递
//void swop1(int a1, int b1)
//{
//	a1 = a1 ^ b1;
//	b1 = a1 ^ b1;
//	a1 = a1 ^ b1;
//}
////地址传递
//void swop2(int* a2,int* b2)
//{
//	*a2 = *a2 ^ *b2;
//	*b2 = *a2 ^ *b2;
//	*a2 = *a2 ^ *b2;
//}
////引用传递
//void swop3(int &a3, int &b3)
//{
//	a3 = a3 ^ b3;
//	b3 = a3 ^ b3;
//	a3 = a3 ^ b3;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	cout << a << "  " << b << endl;
//	swop1(a, b);
//	cout << a << "  " << b << endl;
//	swop2(&a, &b);
//	cout << a << "  " << b << endl;
//	swop3(a, b);
//	cout << a << "  " << b << endl;
//	system("pause");
//	return 0;
//
//}

//查找数字
//void index(int a[], int n, int & sub)
//{
//	if (0 == n)
//	{
//		sub = -1;
//		return;
//	}
//	while (-1 != n--)
//	{
//		if (sub == a[n])
//		{
//			sub = n;
//			return;
//		}
//	}
//	sub = -1;
//	return;
//}
//int main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int sub = 5;
//	int n = sizeof(a) / sizeof(a[0]);
//	index(a, n, sub);
//	if (-1 == sub)
//	{
//		cout << "not in the array!" << endl;
//		cout << sub << endl;
//	}
//	else
//	{
//		cout << "sub in the array!" << endl;
//		cout << sub << endl;
//	}
//	system("pause");
//	return 0;
//}
//

//字符串查找函数
//int mystrchr(char string[], char c)
//{
//	assert(string);
//	int count = 0;
//	while (*string)
//	{
//		count++;
//		if (*string == c)
//			return count;
//		string++;
//	}
//	return 0;
//}
//int main()
//{
//	char s[] = "joker xue";
//	char c = 'x';
//	int x = mystrchr(s, c);
//	cout << x << endl;
//	system("pause");
//	return 0;
//}

void mystrrev(char string[])
{
	assert(string);
	if (*string == '\0' || *(string + 1) == '\0')
		return;
	else
	{
		char* start = string;
		char* end = string;
		while (*end++);
		char temp;
		--end;
		--end;
		while (start < end)
		{
			temp = *start;
			*start = *end;
			*end = temp;
			start++;
			end--;
		}
	}
}
int main()
{
	char s[] = "joker xue";
	cout << s << endl;
	mystrrev(s);
	cout << s << endl;
	system("pause");
	return 0;
}