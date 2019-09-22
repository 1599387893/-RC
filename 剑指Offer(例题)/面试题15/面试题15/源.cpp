//��������1�ĸ���
#include<iostream>
using namespace std;

int Count1(int num)
{
	int count = 0;
	while (num)
	{
		count++;
		num &= (num - 1);
	}
	return count;
}
int Count2(int num)
{
	int count = 0;
	int x = 0;
	while (num>1)
	{
		x = num % 2;
		if (x == 1)
			count++;
		num /= 2;
	}
	if (num == 1)
		count++;
	return count;
}
int Count3(int num)
{
	int count = 0;
	while (num)
	{
		if (num & 1)
			count++;
		num >>= 1;
	}
	return count;
}
int Count4(int num)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if ((flag&num)>0)
			count++;
		flag <<= 1;
	}
	return count;
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << "����һ������" << num << "��������1�ĸ����У�" << Count1(num) << "��" << endl;
		cout << "������������" << num << "��������1�ĸ����У�" << Count2(num) << "��" << endl;
		cout << "������������" << num << "��������1�ĸ����У�" << Count3(num) << "��" << endl;
		cout << "�����ģ�����" << num << "��������1�ĸ����У�" << Count4(num) << "��" << endl;
	}
	system("pause");
	return 0;
}