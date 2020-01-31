#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	int val;
	int col;
	int row;
	Node(int _val, int _row, int _col) 
		:val(_val)
		,row(_row)
		,col(_col)
	{}
};

//向下调整
void Adjust1(vector<int>& heap, int parent)
{
	size_t child = parent * 2 + 1;
	while (child<heap.size())
	{
		if (child + 1 < heap.size() && heap[child + 1] < heap[child])
			child++;
		if (heap[child] < heap[parent])
			swap(heap[child], heap[parent]);
		parent = child;
		child = parent * 2+1;
	}
}
void Adjust2(vector<Node*>& heap, int parent)
{
	size_t child = parent * 2 + 1;
	while (child < heap.size())
	{
		if (child + 1 < heap.size() && heap[child + 1]->val < heap[child]->val)
			child++;
		if (heap[child]->val < heap[parent]->val)
			swap(heap[child], heap[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void Heap_Sort(vector<int>& heap)
{
	int parent = heap.size() / 2-1;
	for (int i = parent; i >= 0; --i)
		Adjust1(heap, parent);
}
void Heap_Sort(vector<Node*>& heap)
{
	int parent = heap.size() / 2 - 1;
	for (int i = parent; i >= 0; --i)
		Adjust2(heap, parent);
}
vector<int> MergeArrays(vector<vector<int>>& arrs)
{
	vector<int> res;
	int count = 0;
	vector<Node*> heap;//这里也可以使用优先级队列或者set，不需要排序的过程；
	for (size_t i = 0; i < arrs.size(); ++i)
	{
		heap.push_back(new Node(arrs[i][0],i,0));
		count += arrs[i].size(); //用来确定最终的循环次数
	}
	//先将堆中元素排序
	Heap_Sort(heap);
	while (count--)
	{
		//将堆顶元素(最小值)插入到结果数组中
		res.push_back(heap[0]->val);
		//判断堆顶元素是不是其数组的最后一个元素
		if (heap[0]->col == arrs[heap[0]->row].size() - 1)
		{
			heap[0]->val = INT_MAX;//将堆顶元素替换成最大值；
			heap[0]->col = INT_MAX;
			heap[0]->row = INT_MAX;
		}
		else
		{
			heap[0]->val = arrs[heap[0]->row][heap[0]->col + 1];
			heap[0]->row = heap[0]->row;
			heap[0]->col = heap[0]->col + 1;
		}
		Adjust2(heap, 0);
	}
	return res;
}
int main()
{
	vector<vector<int>> arrs{ {1,2,7,9}, {5,6}, {3}, {4,8} };
	vector<int> res = MergeArrays(arrs);
	for (auto c : res)
		cout << c << " ";
	cout << endl;
	return 0;
}