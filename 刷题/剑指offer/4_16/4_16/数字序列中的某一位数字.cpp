#if 0
#include<iostream>
using namespace std;

int main()
{
	int n = 3;
	int number = 0, pos = 0;
	long base = 9, digits = 1;
	//ȷ�����Ǽ�λ��
	while (n - base*digits>0)
	{
		n -= base*digits;
		base *= 10;
		digits++;
	}
	//ȷ����������digitsλ���ĵڼ���
	number = n / 3 + pow(10, digits - 1);
	//ȷ���Ǹ����ֵ���һλ�ϵ�ֵ
	pos = n%digits;
	while (pos--)
		number /= 10;
	cout << number % 10 << endl;
	return 0;
}
#endif