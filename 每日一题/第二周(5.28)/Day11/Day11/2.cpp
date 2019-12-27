//2
//求二进制最大连续bit树
//输入示例：
//			7
//输出示例：
//			3

#include<iostream>
using namespace std;

int count_one(int n)
{
	int ret = 0;
	int temp = 0;
	while (n)
	{
		temp = 0;
		while (n % 2 == 1)
		{
			++temp;
			n /= 2;
		}
		if (temp>ret)
			ret = temp;
		n /= 2;
	}
	return ret;
}

int main()
{
	int number = 0;
	int count = 0;
	while (cin >> number)
	{
		count = count_one(number);
		cout << count << endl;
	}
	system("pause");
	return 0;
}

#if 0
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n右移32次就变为0
		while (n)
		{
			//获取当前位的二进制值
			if (n & 1)
			{
				//如果1的值连续，计数累加，并且跟新最大计数
				++count;
				maxCount = max(count, maxCount);
			}
			else
			{
				//如果1的值不连续，重新累加
				count = 0;
			}
			//右移一次，为获取下一位二进制值做准备
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}
#endif