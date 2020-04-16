#if 0
#include<iostream>
using namespace std;

int main()
{
	int n = 3;
	int number = 0, pos = 0;
	long base = 9, digits = 1;
	//确定他是几位数
	while (n - base*digits>0)
	{
		n -= base*digits;
		base *= 10;
		digits++;
	}
	//确定该数字是digits位数的第几个
	number = n / 3 + pow(10, digits - 1);
	//确定是该数字的哪一位上的值
	pos = n%digits;
	while (pos--)
		number /= 10;
	cout << number % 10 << endl;
	return 0;
}
#endif