#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& nums, int l1, int r1, int l2, int r2)
{
	int i = l1;
	int j = l2;
	int n = (r1 - l1 + 1) + (r2-l2+1);
	vector<int> temp(n);
	int k = 0;
	while (i <= r1 && j <= r2)
	{
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	for (int i = 0; i < n; ++i)
		nums[l1 + i] = temp[i];
}
void MergeSort(vector<int>& arr, int start, int end)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}
int main()
{
	vector<int> nums{ 1, 4, 3, 2, 5, 6, 3 };
	MergeSort(nums, 0, nums.size());
	for (const auto c : nums)
		cout << c << " ";
	cout << endl;
	cin >> nums[0];
	return 0;
}