#if  0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Parition(vector<int>& arr, int left, int right)
{
	int& key = arr[right - 1];
	int begin = left, end = right - 1;
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >key)
			end--;
		if (begin != end)
			swap(arr[begin], arr[end]);
	}
	return begin;
}
void QSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = Parition(arr, left, right);
		QSort(arr,left, mid);
		QSort(arr,mid + 1, right);
	}
}
void Adjust(vector<int>& arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child] > arr[child + 1])
			child++;
		if (arr[child] < arr[parent])
			swap(arr[child], arr[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(vector<int>& arr)
{
	for (int i = arr.size() / 2 - 1; i >= 0; --i)
		Adjust(arr, arr.size(), i);
	for (int i = arr.size() - 1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		Adjust(arr, i, 0);
	}
}

void merge(vector<int>& arr, int left, int mid, int right)
{
	vector<int> temp;
	for (int i = left; i <= right; ++i)
		temp.push_back(arr[i]);
	int l1 = left, l2 = mid + 1, r1 = mid, r2 = right;
	for (int i = left; i <= right; ++i)
	{
		if (l1 > mid)
			arr[i] = temp[l2++ - left];
		else if (l2 > right || temp[l1 - left] <= temp[l2 - left])
			arr[i] = temp[l1++ - left];
		else
			arr[i] = temp[l2++ - left];
	}
}
void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
int main()
{
	vector<int> arr{1,5,9,3,4,7,6,0,2,8};
	//QSort(arr, 0, arr.size());
	//HeapSort(arr);
	MergeSort(arr, 0, arr.size() - 1);
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
	system("pause");
	return 0;
}
#endif