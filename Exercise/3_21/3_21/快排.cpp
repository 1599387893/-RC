//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int Parition(vector<int>& arr, int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = arr[right - 1];
//	while (begin < end)
//	{
//		while (arr[begin] < key)
//			begin++;
//		while (arr[end] > key)
//			end--;
//		if (begin != end)
//			swap(arr[begin], arr[end]);
//	}
//	if (arr[begin] != key)
//		swap(arr[begin], arr[right - 1]);
//	return begin;
//}
//void QSort(vector<int>& arr, int left, int right)
//{
//	int mid = 0;
//	if (left < right)
//	{
//		mid = Parition(arr, left, right);
//		QSort(arr, left, mid);
//		QSort(arr, mid + 1, right);
//	}
//}
//int main()
//{
//	vector<int> arr{9,8,7,6,5,4,1,2,3 };
//	QSort(arr, 0, arr.size());
//	for (const auto c : arr)
//		cout << c << ' ';
//	cout << endl;
//	return 0;
//}