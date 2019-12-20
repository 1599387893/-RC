#include<iostream>
#include<vector>
using namespace std;
#if 0
int main()
{
	vector<int> arr{ 1, 4, 8, 9, 12, 63, 79 };
	int right = arr.size()-1;
	int left = 0;
	int mid = left + (right - left) / 2;
	int key = 0;
	cin >> key;
	while (left <= right)
	{
		if (arr[mid] == key)
			break;
		else if (arr[mid] < key)
			left = mid+1;
		else
			right = mid-1;
		mid = left + (right - left) / 2;
	}
	if (left > right)
		cout << "No" << endl;
	else
		cout << mid << endl;
	system("pause");
	return 0;
}
#endif
double(*fptr)();
int  main()
{
	cout << sizeof(fptr) << endl;
	system("pause");
	return 0;
}