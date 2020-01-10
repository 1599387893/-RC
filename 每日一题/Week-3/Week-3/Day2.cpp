//1.�������ڵ�������ת��
#if 0
#include<iostream>
using namespace std;

int Month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int DayOfYear(int y, int m, int d)
{
	int days = 0;
	for (int i = 1; i < m; ++i)
	{
		if (i == 2 && (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)))
			days++;
		days += Month[i];
	}
	days += d;
	return days;
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
		cout << DayOfYear(year, month, day) << endl;
	return 0;
}
//2.���˵Ĵ���

#include <iostream>
#include <stdlib.h>
using namespace std;

int n;
int nums[1000];
int cmp(const void * a, const void * b)
{
	return *(int*)a - *(int*)b;
}
// ˼·��DFS����ȫ��ϣ�ͬʱע���֦�������ظ����
int findall(int nums[], int index, long sum, long multi)
{
	int count = 0;
	for (int i = index; i<n; i++) {
		sum += nums[i];
		multi *= nums[i];
		if (sum > multi)
			count += 1 + findall(nums, i + 1, sum, multi);
		else if (nums[i] == 1)
			count += findall(nums, i + 1, sum, multi);
		else
			break;
		sum -= nums[i];
		multi /= nums[i];
		// ������ȵ�Ԫ�أ������ظ����
		while (i<n - 1 && nums[i] == nums[i + 1])
			i++;
	}
	return count;
}
int main(int argc, char* argv[])
{
	while (cin >> n) {
		for (int i = 0; i<n; i++)
			cin >> nums[i];
		// ��С��������
		qsort(nums, n, sizeof(int), cmp);
		cout << findall(nums, 0, 0, 1) << endl;
	}

	return 0;
}
#endif