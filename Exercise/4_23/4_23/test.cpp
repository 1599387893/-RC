//���ֲ���
//��n��������С��K����
//��������ͶӲ�ң���Ͷ����Ӯ�ĸ���
//extern����

#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

//���ֲ��ң������㷨��
int binarySearch(vector<int>& arr,const int& target)
{
	int left = 0;
	int right = arr.size() - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] < target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

//���ֲ���(Ѱ����߽��㷨)
int left_bound(vector<int>& arr, const int& target)
{
	if (arr.size() == 0) return -1;
	int left = 0, right = arr.size();
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == target)
			right =  mid;
		else if (arr[mid] > target)
			right = mid;
		else
			left = mid+1;
	}
	if (left == arr.size()) return -1;
	return arr[left] == target ? left : -1;
}
//���ֲ��ң�Ѱ���ұ߽��㷨��
int right_bound(vector<int>& arr, const int& target)
{
	if (arr.size() == 0) return -1;
	int left = 0, right = arr.size();
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == target)
			left = mid + 1;
		else if (arr[mid] > target)
			right = mid;
		else
			left = mid + 1;
	}
	return left - 1;
}
int main()
{
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(8);
	pq.push(4);
	pq.push(5);
	pq.push(9);
	pq.push(2);
	pq.push(3);
	pq.push(1);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}