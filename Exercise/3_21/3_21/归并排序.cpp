#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int start,int mid,int end)
{
	vector<int> temp(end - start + 1);
	for (int i = start; i <= end; ++i)
		temp[i - start] = arr[i];
	int i = start, j = mid+1;
	for (int k = start; k <= end ; ++k)
	{
		if (i > mid)
		{
			arr[k] = temp[j - start];
			j++;
		}
		else if (j > end)
		{
			arr[k] = temp[i - start];
			i++;
		}
		else if (temp[i - start] <= temp[j - start])
		{
			arr[k] = temp[i - start];
			i++;
		}
		else
		{
			arr[k] = temp[j-start];
			j++;
		}
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
	vector<int>arr{5,7,6,1,3,9,4,2,8};
	MergeSort(arr,0,arr.size()-1);
	for (const auto c : arr)
		cout << c << " ";
	cout << endl;
	return 0;
}