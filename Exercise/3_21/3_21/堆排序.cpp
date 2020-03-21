//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//void Adjust(vector<int>& arr, int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size)
//	{
//		if (child + 1 < size && arr[child + 1] < arr[child])
//			child++;
//		if (arr[parent] > arr[child])
//			swap(arr[parent], arr[child]);
//		parent = child;
//		child = parent * 2 + 1;
//	}
//}
//void HeapSort(vector<int>& arr)
//{
//	for (int i = arr.size() / 2 - 1; i >= 0; --i)
//		Adjust(arr,arr.size(),i);
//	for (int i = arr.size() - 1; i > 0; --i)
//		Adjust(arr, i, 0);
//}
//int main()
//{
//	vector<int> arr{9,7,8,2,4,5,3,1};
//	HeapSort(arr);
//	for (const auto c : arr)
//		cout << c << " ";
//	cout << endl;
//	return 0;
//}