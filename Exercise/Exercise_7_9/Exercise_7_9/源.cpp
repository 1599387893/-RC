#if 0
// write your code here cpp
#include<iostream>
using namespace std;
int nor[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool Judge_leap(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
		return true;
	else
		return false;
}
int Earn(int y1, int y2, int m1, int m2, int d1, int d2)
{
	int money = 0;
	if (m1 == 2 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 11)
		money = 1;
	else
		money = 2;
	//int days = nor[m1];
	//if (Judge_leap(y1) && m1 == 2)
	//	days++;
	while ((y1 != y2) || (m1 != m2) || (d1 != d2))
	{
		if (Judge_leap(y1))
			nor[2] = 29;
		else
			nor[2] = 28;

		if (d1 <= nor[m1])
		{
			//素数月份
			if (m1 == 2 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 11)
			{
				money += 1;
				d1++;
			}
			else
			{
				money += 2;
				d1++;
			}
		}
		else //向前加一个月
		{
			if (m1 == 12)
			{
				y1++;
				m1 = 1;
				d1 = 1;
			}
			else
			{
				m1++;
				d1 = 1;
			}
		}
	}
	return money;
}
int main()
{
	int y1, m1, d1;
	int y2, m2, d2;
	while (cin >> y1 >> m1 >> d1)
	{
		cin >> y2 >> m2 >> d2;
		cout << Earn(y1, y2, m1, m2, d1, d2) << endl;
	}
	return 0;
}


#include<iostream>
using namespace std;

int f[] = { 1, 1, 2 };
int main()
{
	int n;
	while (cin >> n)
	{
		double fn = 0;
		double a = f[1];
		double b = f[2];
		if (n == 1 || n == 2)
		{
			cout << f[n] << endl;
			continue;
		}
		for (int i = 3; i <= n; ++i)
		{
			fn = a + b;
			a = b;
			b = fn;
		}
		printf("%06f\n", fn);
	}
	return 0;
}
#endif

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 100000

long long int num[MAX + 1] = { 1, 1, 2, 3, 5 };

void solve() 
{
	for (int i = 5; i <= MAX; i++) 
	{ 
		num[i] = num[i - 1] + num[i - 2];         
		num[i] %= 1000000; 
	}
}

int main()
{
	int n;
	solve();
	while (scanf("%d", &n) != EOF)
		printf((n < 29 ? "%d\n" : "%06d\n"), num[n]);
	return 0;
}