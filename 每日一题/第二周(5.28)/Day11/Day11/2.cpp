//2
//��������������bit��
//����ʾ����
//			7
//���ʾ����
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
		// n����32�ξͱ�Ϊ0
		while (n)
		{
			//��ȡ��ǰλ�Ķ�����ֵ
			if (n & 1)
			{
				//���1��ֵ�����������ۼӣ����Ҹ���������
				++count;
				maxCount = max(count, maxCount);
			}
			else
			{
				//���1��ֵ�������������ۼ�
				count = 0;
			}
			//����һ�Σ�Ϊ��ȡ��һλ������ֵ��׼��
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}
#endif