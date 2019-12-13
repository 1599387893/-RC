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
	//1. 构建堆(从最后一个非叶子节点开始 向上循环进行向下调整)
	//2. 堆排序（原理：堆删除）
	//根节点从0开始计算
	int root = arr.size() / 2-1 ;
	for (; root >= 0; --root)
		Adjust(arr,arr.size(),root );
	for (int i = arr.size()-1; i > 0; i--)
		Erase(arr,i);
}
int Parition(vector<int>& arr, int  beg, int end)
{

}
void Q_Sort1(vector<int>& arr,int begin,int end)
{
	int mid = Parition(arr,begin,end);
	Q_Sort1(arr, begin, mid - 1);
	Q_Sort1(arr, mid+1,end);
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

	Q_Sort1(arr,0,arr.size()-1); //hoare法
	//Q_Sort2(arr); //挖坑法
	//Q_Sort3(arr); //前后指针法
	//Merge_sort(arr);
	Print(arr);
	system("pause");
	return 0;
}