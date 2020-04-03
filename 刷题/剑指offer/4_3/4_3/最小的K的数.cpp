#if 0
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> res;
		if (k == 0)
			return res;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < k; ++i)
			res.push_back(arr[i]);
		return res;
	}
};


class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> res;
		if (k == 0 || arr.size() == 0)
			return res;
		priority_queue<int> pq;
		for (int i = 0; i <k; ++i)
			pq.push(arr[i]);
		for (int i = k; i<arr.size(); ++i)
		{
			if (arr[i]<pq.top())
			{
				pq.pop();
				pq.push(arr[i]);
			}
		}
		while (!pq.empty())
		{
			res.push_back(pq.top());
			pq.pop();
		}
		return res;
	}
};
#endif

#include<iostream>
#include<vector>
using namespace std;

int Parition(vector<int>& arr, int left, int right)
{
	int& key = arr[right - 1];
	int begin = left, end = right-1;
	while (begin < end)
	{
		while (begin <end && arr[begin] <= key)
			begin++;
		while (begin <end && arr[end] >key)
			end--;
		if (begin != end)
			swap(arr[begin], arr[end]);
	}
	return begin;
}
void QSort(vector<int>& arr, int left, int right, const int K)
{
	if (left < right)
	{
		int mid = Parition(arr, left, right);
		if (mid >= K)
			return;
		QSort(arr, left, mid, K);
		QSort(arr, mid + 1, right, K);
	}
}
int  main() {
	vector<int> arr{3,2,1};
	int k = 2;
	vector<int> res;
	if (arr.size() == 0 || k == 0)
		return 0;
	QSort(arr, 0, arr.size(), k - 1);
	for (int i = 0; i < k; ++i)
		res.push_back(arr[i]);
	return 0;
}