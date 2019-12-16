#include<iostream>
#include<vector>
using namespace std;
void Print(vector<int>& arr)
{
	auto it = arr.begin();
	while (it != arr.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void Insert_Sort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int temp = i - 1;
		int key = arr[i];
		while (temp >= 0 && arr[temp] > key)
		{
			arr[temp + 1] = arr[temp];
			temp--;
		}
		arr[temp+1] = key;
	}
}
void Shell_Sort(vector<int>& arr)
{
	int gap = 3;
	while (gap >= 1)
	{
		for (int i = gap; i < arr.size(); i += gap)
		{
			for (int j = i - gap; j >= 0; j -= gap)
				if (arr[j + gap] < arr[j])
					swap(arr[j + gap], arr[j]);
		}
		gap--;
	}
}
void Select_Sort1(vector<int>& arr)
{
	int min = 0; 
	for (size_t i = 1; i < arr.size(); ++i)
	{
		for (int j = i; j < arr.size(); ++j)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[i-1] , arr[min]);
		min = i ;
	}
}
void Select_Sort(vector<int>& arr)
{
	int min = 0;
	int max = arr.size() - 1;
	for (size_t i = 1; i < arr.size() / 2; ++i)
	{
		for (int j = i; j < arr.size() / 2; ++j)
		{
			if (arr[min] > arr[j])
				min = j;
			if (arr[max] < arr[j])
				max = j;
		}
		swap(arr[i - 1], arr[min]);
		swap(arr[arr.size() - 1 - i], arr[max]);
		min = i;
		max = arr.size() - 2 - i;
	}
}
void Bubblo_Sort(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size()-1; ++i)
	{
		bool flag = true;
		for (size_t j = 0; j < arr.size() - 1; ++j)
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = false;
			}
		if (flag)
			break;
	}
}
void Adjust(vector<int>& arr, int size,int parent)
{
	int child = parent * 2+1;
	while (child < size)
	{
		if (child + 1 < size && arr[child] < arr[child + 1])
			child += 1;
		if (arr[child] > arr[parent])
			swap(arr[child], arr[parent]);
		parent = child;
		child = parent * 2+1;
	}
}
void Erase(vector<int>& arr, int i)
{
	swap(arr[0], arr[i]);
	Adjust(arr, i, 0);
}
void Heap_Sort(vector<int>& arr)
{
	//1. ������(�����һ����Ҷ�ӽڵ㿪ʼ ����ѭ���������µ���)
	//2. ������ԭ����ɾ����
	//���ڵ��0��ʼ����
	int root = arr.size() / 2-1 ;
	for (; root >= 0; --root)
		Adjust(arr,arr.size(),root );
	for (int i = arr.size()-1; i > 0; i--)
		Erase(arr,i);
}
int Parition1(vector<int>& arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = arr[right - 1];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
			swap(arr[begin], arr[end]);
	}
	if (arr[begin] != key)
		swap(arr[begin], arr[right - 1]);
	return begin;
}
void Q_Sort1(vector<int>& arr,int left,int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Parition1(arr,left,right);
		Q_Sort1(arr,left,mid);
		Q_Sort1(arr,mid+1,right);
	}
}
int Parition2(vector<int>& arr, int left, int right)
{
	int begin = left;
	int end = right ;
	int key = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		if (begin < end)
			arr[end] = arr[begin];
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
			arr[begin] = arr[end];
	}
	arr[begin] = key;
	return begin;
}
void Q_Sort2(vector<int>& arr,int left,int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Parition2(arr,left,right);
		Q_Sort2(arr,left,mid-1);
		Q_Sort2(arr,mid+1,right);
	}
}
int main()
{
	vector<int> arr = { 9, 1, 2, 0, 7, 4, 3, 6, 8, 5 };
	Print(arr);
	//Insert_Sort(arr);
	//Shell_Sort(arr);
	//Select_Sort(arr);
	//Bubblo_Sort(arr);
	//Heap_Sort(arr);

	//Q_Sort1(arr, 0, arr.size() - 1); //hoare��
	Q_Sort2(arr,0,arr.size()-1); //�ڿӷ�
	//Q_Sort3(arr); //ǰ��ָ�뷨
	//Merge_sort(arr);
	Print(arr);
	system("pause");
	return 0;
}