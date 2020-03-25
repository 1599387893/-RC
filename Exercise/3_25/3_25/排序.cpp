//#include<iostream>
//#include<vector>
//using namespace std;
//
//int Parition(vector<int>& arr, int left, int right)
//{
//	int key = arr[right - 1];
//	int begin = left;
//	int end = right - 1;
//	while (begin < end)
//	{
//		while (begin < end && arr[begin] <= key)
//			begin++;
//		while (begin < end && arr[end] >= key)
//			end--;
//		if (begin != end)
//			swap(arr[begin], arr[end]);
//	}
//	if (begin != right - 1)
//		swap(arr[begin], arr[right - 1]);
//	return begin;
//}
//void QSort(vector<int>& arr, int left, int right)
//{
//	if (left < right)
//	{
//		int mid = Parition(arr, left, right);
//		QSort(arr, left, mid);
//		QSort(arr, mid + 1, right);
//	}
//}
//
//void Adjust(vector<int>& arr, int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size)
//	{
//		if (child + 1 < size && arr[child] > arr[child + 1])
//			child++;
//		if (arr[child] < arr[parent])
//			swap(arr[child], arr[parent]);
//		parent = child;
//		child = parent * 2 + 1;
//	}
//}
//void HeapSort(vector<int>& arr)
//{
//	for (int i = arr.size() / 2 - 1; i >= 0; i--)
//		Adjust(arr, arr.size(), i);
//	for (int i = arr.size() - 1; i >= 0; --i)
//	{
//		swap(arr[0], arr[i]);
//		Adjust(arr, i, 0);
//	}
//}
//void merge(vector<int>& arr, int left, int mid, int right)
//{
//	vector<int> temp; 
//	for (int i = left; i <= right; ++i)
//		temp.push_back(arr[i]);
//	int l1 = left, r1 = mid, l2 = mid + 1, r2 = right;
//	for (int i = left; i <= right; ++i)
//	{
//		if (l2 > right)
//			arr[i] = temp[(l1++) - left];
//		else if (l1 >mid || temp[l1 - left] > temp[l2 - left])
//			arr[i] = temp[(l2++) - left];
//		else
//			arr[i] = temp[(l1++) - left];
//	}
//}
//void MergeSort(vector<int>& arr, int left, int right)
//{
//	if (left < right)
//	{
//		int mid = left + (right - left) / 2;
//		MergeSort(arr, left, mid);
//		MergeSort(arr, mid + 1, right);
//		merge(arr, left, mid, right);
//	}
//}
//int main()
//{
//	vector<int> arr{2,5,8,6,4,1,3,0,9,7};
//	//QSort(arr, 0, arr.size());
//	//HeapSort(arr);
//	MergeSort(arr, 0, arr.size() - 1);
//	for (const auto c : arr)
//		cout << c << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}