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
//		while (begin < end && arr[begin] <= key)
//			begin++;
//		while (begin < end && arr[end] >= key)
//			end--;
//		if (begin < end)
//			swap(arr[begin], arr[end]);
//	}
//	if (arr[begin] != key)
//		swap(arr[begin], arr[right - 1]);
//	return begin;
//}
//void QSort(vector<int>& arr,int left,int right)
//{
//	int mid = 0;
//	if (left < right)
//	{
//		mid = Parition(arr, left, right);
//		QSort(arr, left, mid);
//		QSort(arr, mid + 1, right);
//	}
//
//}
//
////小根堆
//void Adjust(vector<int>& arr,int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size)
//	{
//		if (child + 1 < size && arr[child] > arr[child + 1])
//			child++;
//		if (arr[parent] > arr[child])
//			swap(arr[parent], arr[child]);
//		parent = child;
//		child = parent * 2 + 1;
//	}
//}
////堆排序
//void HeapSort(vector<int>& arr)
//{
//	//建堆
//	//从第一个非叶子节点的位置开始
//	for (int i = arr.size() / 2 - 1; i >= 0; --i)
//		Adjust(arr, arr.size(), i);
//	//堆删除
//	for (int i = arr.size()-1; i > 0; --i)
//	{
//		swap(arr[0], arr[i]);
//		Adjust(arr, i, 0);
//	}
//}
//
//
//
//int main()
//{
//	vector<int> arr = { 2, 5, 6, 9, 4, 0, 1, 7, 3, 8 };
//	//QSort(arr,0,arr.size());
//	HeapSort(arr);
//	for (const auto c : arr)
//		cout << c << " ";
//	cout << endl;
//	cin >> arr[0];
//	return 0;
//}