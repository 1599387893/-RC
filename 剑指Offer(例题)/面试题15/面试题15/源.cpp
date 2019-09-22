//二进制中1的个数
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
		cout << "方法一：数字" << num << "二进制中1的个数有：" << Count1(num) << "个" << endl;
		cout << "方法二：数字" << num << "二进制中1的个数有：" << Count2(num) << "个" << endl;
		cout << "方法三：数字" << num << "二进制中1的个数有：" << Count3(num) << "个" << endl;
		cout << "方法四：数字" << num << "二进制中1的个数有：" << Count4(num) << "个" << endl;
	}
	system("pause");
	return 0;
}