#include<iostream>
#include<vector>
using namespace std;

int Find3(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j)
			if (arr[i] == arr[j])
				return arr[j];
	return -1;

}
//这个解法与1，2，3都不同，
//要求：在一个长度为n+1的数组里的所有数字都在1~n的范围内，找出重复的数字。
int Find4(int* arr, int size)
{
	vector<int> temp;
	temp.resize(size, 0);
	for (int i = 0; i < size; ++i)
	{
		temp[arr[i]]++;
		if (temp[arr[i]] == 2)
			return arr[i];
	}
	return -1;
}

int countRange(const int* arr, int size, int start, int end);
int Find5(const int* arr, int size)
{
	if (arr == nullptr || size <= 0)
		return -1;

	int start = 1;
	int end = size - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(arr, size, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}
int countRange(const int* arr, int size, int start, int end)
{
	if (arr == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < size; ++i)
		if (arr[i] >= start && arr[i] <= end)
			++count;
	return count;
}

int main()
{
	int arr2[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << Find5(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl;
	system("pause");
return 0;
}


//int Find5(int*arr, int size)
//{
//	int left = 0;
//	int right = size - 1;
//	int mid = 0;
//	while (right >= left)
//	{
//		mid = (right - left) / 2 + mid;
//		int ret = count(arr, left, right, mid);
//		if (ret == 1)
//			left = mid;
//		else
//			right = mid;
//	}
//	return arr[mid];
//}
//
//int count(const int*arr, int left, int right, int mid)
//{
//	int less = 0;
//	int greater = 0;
//	for (int i = 0; i <= right; ++i)
//	{
//		if (mid > arr[i])
//			greater++;
//		else
//			less++;
//	}
//	if (less > greater)
//		return -1;
//	return 1;
//}
