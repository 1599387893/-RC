//数组中的重复数字
#include<iostream>
#include<algorithm>
using namespace std;

extern int Find3(int* arr, int size);
extern int Find4(int* arr, int size);
extern int Find5(int* arr, int size);
extern int countRange(int* arr, int size, int start, int end);

//要求：在一个长度为n的数组里，所有的数字都在0~n-1的范围内，找出重复的数字
int Find1(int* arr, int size)
{
	sort(arr, arr + size);
	for (int i = 0; i < size-1; ++i)
		if (arr[i] == arr[i + 1])
			return arr[i];
	return -1;
}
int Find2(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == i)
			continue;
		if (arr[arr[i]] == arr[i])
			return arr[i];
		else
			swap(arr[arr[i]], arr[i]);
	}
	return -1;
}

#if 0
int main()
{
	int arr1[] = { 4, 3, 1, 0, 2, 5, 3 };
	cout << Find1(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	cout << Find2(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	cout << Find3(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;

	int arr2[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << Find4(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	cout << Find5(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl;
	system("pause");
	return 0;
}
#endif
 