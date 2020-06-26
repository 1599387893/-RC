#include<iostream>
#include<vector>
using namespace std;

int Parition(vector<int>& arr, int left, int right)
{
	int start = left;
	int end = right - 1;
	int& key = arr[right - 1];
	while (start < end)
	{
		while (start < end && arr[start] <= key)
			start++;
		while (start < end && arr[end] > key)
			end--;
		if (start != end)
			swap(arr[end], arr[start]);
	}
	return start;
}
void Qsort(vector<int>& arr,int left,int right)
{
	if (left < right)
	{
		int mid = Parition(arr, left, right);
		Qsort(arr, left, mid);
		Qsort(arr, mid + 1, right);
	}
}
void Adjust(vector<int>& arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size &&  arr[child + 1] < arr[child])
			child++;
		if (arr[child] < arr[parent])
			swap(arr[child], arr[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(vector<int>& arr)
{
	for (int i = arr.size() / 2 - 1; i >= 0;--i)
		Adjust(arr, arr.size(), i);
	for (int i = arr.size()-1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		Adjust(arr, i, 0);
	}
}

void merge(vector<int>& arr, int left, int mid, int right)
{
	int start1 = left, start2 = mid + 1;
	int end1 = mid, end2 = right;
	vector<int> temp(right - left + 1);
	for (int i = 0; i < temp.size(); ++i)
		temp[i] = arr[i + left];
	for (int i = left; i <= right; ++i)
	{
		if (start1 > end1)
			arr[i] = temp[start2++ - left];
		else if (start2 > end2 || temp[start1 - left] < temp[start2 - left])
			arr[i] = temp[start1++ - left];
		else
			arr[i] = temp[start2++ - left];
	}
}
void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		merge(arr,left,mid,right);
	}

}
int main()
{
	vector<int>  arr{1,5,9,3,7,2,6,4,8};
	//Qsort(arr,0,arr.size());
	//HeapSort(arr);
	MergeSort(arr, 0, arr.size() - 1);
	for (const auto n : arr)
		cout << n << " ";
	cout << endl;
	system("pause");
	return 0;
}