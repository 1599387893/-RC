#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Parition(vector<int>& arr, int begin, int end)
{
	int& key = arr[end - 1];
	int left = begin;
	int right = end - 1;
	while (left < right)
	{
		while (left < right && arr[left] <= key)
			left++;
		while (left < right && arr[right] > key)
			right--;
		if (left != right)
			swap(arr[left], arr[right]);
	}
	return left;
}
void QSort(vector<int>& arr, int begin, int end)
{
	if (begin < end)
	{
		int mid = Parition(arr, begin, end);
		QSort(arr, begin, mid);
		QSort(arr, mid + 1, end);
	}
}
void Adjust(vector<int>& arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])
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
		swap(arr[i], arr[0]);
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
		if (l1 > r1)
			arr[i] = temp[r2++ - left];
		else if (l2 > r2 || temp[l1 - left] < temp[l2 - left])
			arr[i] = temp[r1++ - left];
		else
			arr[i] = temp[r2++ - left];
	}
}
void MergeSort(vector<int>& arr, int start, int end)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}
int main()
{
	vector<int> arr{9,1,0,5,4,2,7,6,3,8};
	//QSort(arr, 0, arr.size());
	//HeapSort(arr);
	MergeSort(arr, 0, arr.size() - 1);
	for (auto n : arr)
		cout << n << " ";
	cout << endl;
	system("pause");
	return 0;
}